import numpy as np
from numpy import log, sqrt, arctan2, pi, sin, exp, isnan
import rclpy
from rclpy.qos import qos_profile_sensor_data
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray
from celeste_navigation import cue
from celeste_interfaces.msg import CueMsg

N_POL_OPS = 8


class PolCueDetector(Node):
    """
    Publish cue every 0.1 seconds.
    """
    def __init__(self):
        super().__init__('pol_cue_detector')
        self.pol_op_responses = [None] * N_POL_OPS
        self.n_sol_neurons = 8
        self.pol_prefs = [0, 90, 180, 270, 45, 135, 225, 315]
        self.sol_prefs = [0] * self.n_sol_neurons

        self.decode_sensor = self.bio_inspired_decode
        self.activation = self.sqrt_activation  # TODO: use which? log() get 0

        self.subscribers = [
            self.create_subscription(Int32MultiArray, f'pol_op_{i}', self.create_callback(i), qos_profile_sensor_data)
            for i in range(N_POL_OPS)
        ]

        self.cue_pub = self.create_publisher(CueMsg, 'pol_cue', 10)

        self.timer = self.create_timer(0.1, self.publish_cue)
        self.pol_cue = cue.Cue("pol", 1, 0, 0)

    def create_callback(self, index):
        def callback(msg):
            self.pol_op_responses[index] = msg.data
        return callback

    @staticmethod
    def log_activation(x):
        return log(x)

    @staticmethod
    def sqrt_activation(x):
        return sqrt(x)

    def bio_inspired_decode(self):
        pol_neuron_responses = [0] * N_POL_OPS
        for i in range(N_POL_OPS):
            s_vert = abs(self.pol_op_responses[i][2])
            s_horiz = abs(self.pol_op_responses[i][3])
            r_vert = self.activation(s_vert)
            r_horiz = self.activation(s_horiz)
            r_op = r_horiz - r_vert
            r_po = r_horiz + r_vert

            if r_po == 0:  # TODO: often 0?
                r_po = float('nan')

            pol_neuron_responses[i] = r_op / r_po

        pol_sol_ratio = self.n_sol_neurons / N_POL_OPS
        R = complex(0, 0)

        for z in range(self.n_sol_neurons):
            r_sol_z = 0
            for j in range(N_POL_OPS):
                alpha_j = np.radians(self.pol_prefs[j] - 90)  # TODO: degrees or radians?
                r_sol_z += pol_sol_ratio * sin(alpha_j - self.sol_prefs[z]) * pol_neuron_responses[j]
            R += r_sol_z * exp(complex(0, -1) * 2 * pi * (z - 1) / self.n_sol_neurons)
        a = R.real
        b = R.imag
        angle = np.angle(R)
        phi = arctan2(-b, a)
        print(f'R:{R},phi:{phi},angle:{angle}')
        tau = sqrt(a * a + b * b)
        phi = -phi

        return phi, tau

    def publish_cue(self):
        if all(response is not None for response in self.pol_op_responses):
            phi, tau = self.decode_sensor()
            self.pol_cue.set_azimuth(phi)
            self.pol_cue.set_contrast(tau)
            self.cue_pub.publish(self.pol_cue.to_msg())
            self.get_logger().info(self.pol_cue.to_string())


def main(args=None):
    rclpy.init(args=args)
    node = PolCueDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
