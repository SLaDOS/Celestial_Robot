import math
import numpy as np
import roslib
import rospy
import std_msgs.msg
import bb_util.msg

# Node not currently linked to calibration routine.
# TODO: link this up with the calibration routine
calibration_offset = 0

# One vector per pol_op unit - non-configurable
pol_op_responses = [[] for _ in range(N_POL_OPS)]

# Subscription topics for each pol_op unit
pol_sub_topics = [
    "pol_op_0",
    "pol_op_1",
    "pol_op_2",
    "pol_op_3",
    "pol_op_4",
    "pol_op_5",
    "pol_op_6",
    "pol_op_7",
]

# Default number of sol neurons
n_sol_neurons = 8

# Preferred angles for pol and sol neurons
pol_prefs = np.radians([0, 90, 180, 270, 45, 135, 225, 315])
sol_prefs = np.linspace(0, 2 * math.pi, n_sol_neurons, endpoint=False)

# Polarization cue message
pol_cue = bb_util.msg.Cue("pol", 1, 0, 0)

# Activation function for pol neurons
activation = lambda x: np.log(x)

def radians(degrees):
    return degrees * math.pi / 180

def degrees(radians):
    return 180 * radians / math.pi

def init_parser(parser, argc, argv):
    parser.add_argument(
        "-a", "--activation",
        help="Activation function for pol neurons (default: log)"
    )
    parser.add_argument(
        "-n_sol", "--n_sol_neurons", type=int,
        help="Number of sol neurons (default: 8)"
    )
    parser.add_argument(
        "-h", "--help", action="help",
        help="Show this help message and exit."
    )
    args = parser.parse_args(argv)

    if args.activation:
        global activation
        activation = {
            "log": lambda x: np.log(x),
            "sqrt": lambda x: np.sqrt(x),
        }[args.activation]

    if args.n_sol_neurons:
        global n_sol_neurons
        n_sol_neurons = args.n_sol_neurons
        global sol_prefs
        sol_prefs = np.linspace(0, 2 * math.pi, n_sol_neurons, endpoint=False)

def pol_callback(pol_msg, i):
    pol_op_responses[i] = pol_msg.data

def bio_inspired_decode():
    # Extract the relevant photodiodes and take their absolute response
    pol_neuron_responses = np.zeros(N_POL_OPS)
    for i in range(N_POL_OPS):
        s_vert = abs(pol_op_responses[i][2])
        s_horiz = abs(pol_op_responses[i][3])
        r_vert = activation(s_vert)
        r_horiz = activation(s_horiz)
        r_op = r_horiz - r_vert
        r_po = r_horiz + r_vert
        pol_neuron_responses[i] = r_op / r_po if r_po != 0 else np.nan

    # Compute the response of the sol neurons
    sol_neuron_responses = np.zeros(n_sol_neurons)
    for z in range(n_sol_neurons):
        r_sol_z = 0
        for j in range(N_POL_OPS):
            alpha_j = pol_prefs[j] - math.pi / 2
            r_sol_z += (
                n_sol_neurons / N_POL_OPS *
                np.sin(alpha_j - sol_prefs[z]) *
                pol_neuron_responses[j]
            )
        sol_neuron_responses[z] = r_sol_z

    # Compute the complex R value
    R = np.complex(0, 0)
    for z in range(n_sol_neurons):
        R += (
            sol_neuron_responses[z] *
            np.exp(-1j * 2 * math.pi * (z - 1) / n_sol_neurons)
        )

    # Compute the angle and certainty of the sensor reading
    phi = -np.arctan2(-R.imag, R.real)
    tau = np.sqrt(R.real ** 2 + R.imag ** 2)
    return phi, tau

def main():
    rospy.init_node("pol_cue_detector")

    # Initialize the argument parser
    init_parser(argparse.ArgumentParser(), rospy.myargv(), rospy.myargv()[1:])

    # Subscribe to the pol_op topics
    pol_subs = []
    for i, topic in enumerate(pol_sub_topics):
        pol_subs.append(
            rospy.Subscriber(
                topic, std_msgs.msg.Int32MultiArray, pol_callback, i
            )
        )

    # Advertise the cue topic
    cue_pub = rospy.Publisher("pol_cue", bb_util.msg.Cue, queue_size=10)

    # Fill the pol_op_responses array with zeros
    for i in range(N_POL_OPS):
        pol_op_responses[i] = [0] * 4

    # Spin at 10 Hz
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
            phi, tau = bio_inspired_decode()
            pol_cue.azimuth = phi
            pol_cue.contrast = tau
            cue_pub.publish(pol_cue)
            rospy.loginfo(pol_cue)
        except Exception as e:
            rospy.logerr(e)
        rate.sleep()

if __name__ == "__main__":
    main()

