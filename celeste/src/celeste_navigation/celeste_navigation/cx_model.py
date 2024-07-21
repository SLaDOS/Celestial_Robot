import numpy as np


class CentralComplex:
    """
    Class definition of the Central Complex.

    The central complex path integration model as defined by Stone et al.
    Ported from the AntBot implementation provided by Luca Scimeca. This
    version of the model does not implement TN neurons for speed measurement.
    """
    CX_N_TL2 = 16  # The number of TL2 neurons in the model.
    CX_N_CL1 = 16  # The number of CL1 neurons in the model.
    CX_N_TB1 = 8  # The number of TB1 neurons in the model.
    CX_N_CPU4 = 16  # The number of CPU4 neurons in the model.
    CX_N_CPU1 = 16  # The number of CPU1 neurons in the model.

    def __init__(self):
        self.n_tl2 = self.CX_N_TL2  # The number of TL2 neurons in use.
        self.n_cl1 = self.CX_N_CL1  # The number of CL1 neurons in use.
        self.n_tb1 = self.CX_N_TB1  # The number of TB1 neurons in use.
        self.n_cpu4 = self.CX_N_CPU4  # The number of CPU4 neurons in use.
        self.n_cpu1 = self.CX_N_CPU1  # The number of CPU1 neurons in use.
        self.tb1_tb1_weight = 1  # The default TB1-TB1 weightings.

        self.noise = 0.0  # Noise injected on the output of each layer.

        self.tl2_slope = 6.8  # TL2 activation slope
        self.tl2_bias = 3.0  # TL2 activation bias
        self.tl2_prefs = np.array([  # The TL2 receptive fields
            [0],
            [0.78539816],
            [1.57079633],
            [2.35619449],
            [3.14159265],
            [3.92699082],
            [4.71238898],
            [5.49778714],
            [0],
            [0.78539816],
            [1.57079633],
            [2.35619449],
            [3.14159265],
            [3.92699082],
            [4.71238898],
            [5.49778714],
        ])

        self.cl1_slope = 3.0  # CL1 activation slope
        self.cl1_bias = -0.5  # CL1 activation bias

        self.tb1_slope = 5.0  # TB1 activation slope
        self.tb1_bias = 0  # TB1 activation bias

        self.cpu4_slope = 5.0  # CPU4 activation slope
        self.cpu4_bias = 2.5  # CPU4 activation bias
        # CPU4 memory gain
        self.cpu4_mem_gain = 0.0005  # 0.005, default
        # CPU4 memory loss
        self.cpu4_mem_loss = 0.00026  # 0.0026, default

        self.cpu1_slope = 6.0  # CPU1 activation slope
        self.cpu1_bias = 2.0  # CPU1 activation bias

        self.W_CL1_TB1 = np.tile((np.eye(self.CX_N_TB1)), (1, 2))  # CL1 -> TB1 connections
        self.W_TB1_TB1 = self.gen_tb1_tb1_weights(self.tb1_tb1_weight)  # TB1 -> TB1 connections
        self.W_TB1_CPU1 = np.tile(np.eye(self.CX_N_TB1), (2, 1))  # TB1 -> CPU1 connections
        self.W_TB1_CPU4 = np.tile(np.eye(self.CX_N_TB1), (2, 1))  # TB1 -> CPU4 connections
        self.W_CPU4_CPU1 = np.array([  # CPU4 -> CPU1 connections
            [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
            [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
        ])
        self.W_CPU1_motor = np.array(  # CPU1 to motor output neuron connections
            [-1, -1, -1, -1, -1, -1, -1, -1,
             1,  1,  1,  1,  1,  1,  1,  1])

        self.TL2 = np.zeros((self.CX_N_TL2, 1))  # TL2 neuron activities
        self.CL1 = np.zeros((self.CX_N_CL1, 1))  # CL1 neuron activities
        self.TB1 = np.zeros((self.CX_N_TB1, 1))  # TB1 neuron activities
        self.MEM = np.full((self.CX_N_CPU4, 1), 0.5)  # Memory neuron (CPU4_{t - 1}) activities
        self.CPU4 = np.zeros((self.CX_N_CPU4, 1))  # CPU4 neuron activities
        self.CPU1 = np.zeros((self.CX_N_CPU1, 1))  # CPU1 neuron activities

        # Sigmoid activation function pointer.
        self.sigmoid = self.noisySigmoid if self.noise > 0 else self.noiselessSigmoid

    def gen_tb1_tb1_weights(self, w):
        """
        Generate intra TB1 weights.

        :param w: Weight scaling factor.
        :return: The TB1 -> TB1 weight matrix.
        """
        sinusoid = [0, 0.14644661, 0.5, 0.85355339, 1., 0.85355339, 0.5, 0.14644661]
        W = np.zeros((self.CX_N_TB1, self.CX_N_TB1))
        for i in range(self.CX_N_TB1):
            for j in range(self.CX_N_TB1):
                idx = (j - i) % self.CX_N_TB1
                idx = idx if idx >= 0 else idx + self.CX_N_TB1
                W[i, j] = sinusoid[idx] * w
        return W

    @staticmethod
    def noisySigmoid(v, slope, bias, noise):
        """
        Sigmoid activation function with added noise. Note that the result is placed in v.

        :param v: The input population.
        :param slope: slope The slope of the sigmoid.
        :param bias: bias The bias (l/r shift) of the sigmoid.
        :param noise: noise The additional noise.
        :return: v
        """
        v = 1 / (1 + np.exp(-(v * slope + bias)))
        # Add Gaussian noise
        if noise > 0:
            v += np.random.normal(0, noise, v.shape)
        v = np.clip(v, 0, 1)
        return v

    @staticmethod
    def noiselessSigmoid(v, slope, bias, noise=0):
        """
        Sigmoid activation function with added noise. Note that the result is placed in v.

        :param v: The input population.
        :param slope: slope The slope of the sigmoid.
        :param bias: bias The bias (l/r shift) of the sigmoid.
        :param noise: noise The additional noise (ignored)
        :return: v
        """
        v = 1 / (1 + np.exp(-(v * slope + bias)))
        return v

    # @staticmethod
    # def dot(a, b):
    #     """
    #     Dot product which allows Eigen Matrices to be used as input.
    #
    #     :param a: Matrix a
    #     :param b: Matrix b
    #     :return: a dot b
    #     """
    #     if a.shape[0] == 1:
    #         a = a.T
    #     if b.shape[1] == 1:
    #         b = b.T
    #     return np.dot(a.T, b).item()

    def tl2_output(self, theta, output):
        """
     Given angular input, compute the TL2 population response.

        :param theta: The angular input (in radians) denoting the agent's current direction.
        :param output: The population response.
        :return:
        """
        if output.shape != self.tl2_prefs.shape:
            raise ValueError("Output dimensions do not match TL2 tuning matrix.")
        output.fill(theta)
        output -= self.tl2_prefs
        output = np.where(np.isnan(output), np.pi/2, np.cos(output))
        output = self.sigmoid(output, self.tl2_slope, self.tl2_bias, self.noise)
        return output

    def cl1_output(self, tl2, cl1):
        """
        Compute CL1 response given a current TL2 response.

        :param tl2: The current TL2 activity matrix.
        :param cl1: The CL1 activity output.
        :return: cl1
        """
        cl1 = -tl2
        cl1 = self.sigmoid(cl1, self.cl1_slope, self.cl1_bias, self.noise)
        return cl1

    def tb1_output(self, cl1, tb1):
        """
        Compute TB1 response given a current CL1 response.

        :param cl1: The current CL1 activity matrix.
        :param tb1: The TB1 activity output.
        :return:
        """
        prop_cl1 = 0.667
        prop_tb1 = 1 - prop_cl1
        cl1_temp = self.W_CL1_TB1 @ cl1 * prop_cl1
        tb1 = self.W_TB1_TB1 @ tb1 * prop_tb1
        tb1 = cl1_temp - tb1
        tb1 = self.sigmoid(tb1, self.tb1_slope, self.tb1_bias, self.noise)
        return tb1

    def cpu4_update(self, speed, tb1, cpu4_mem):
        """
        Update the CPU4 inputs given the current TB1 (direction) response and the agent's current speed.

        note:
            This function does not sigmoid the output. It just formats
            the CPU4 input into a single vector which can be sigmoided. This is
            used to implement the t - 1 term in the CPU4 update rule


        :param speed:
        :param tb1:
        :param cpu4_mem: The CPU4 activity which will be sigmoided.
        :return: cpu4_mem
        """
        ones = np.ones(tb1.shape) - tb1
        diff_matrix = np.full(cpu4_mem.shape, speed * self.cpu4_mem_loss)
        cpu4_mem -= diff_matrix
        diff_matrix = (self.W_TB1_CPU4 @ ones) * (speed * self.cpu4_mem_gain)

        cpu4_mem += diff_matrix
        cpu4_mem = np.clip(cpu4_mem, 0, 1)
        return cpu4_mem

    def cpu4_output(self, cpu4_mem):
        """
             Compute the CPU4 layer output. Pass the CPU4 activity through the
             CPU4 sigmoid function.

        :param cpu4_mem: The CPU4 activity which will be sigmoided.
        :return: cpu4_mem
        """
        cpu4_mem = self.sigmoid(cpu4_mem, self.cpu4_slope, self.cpu4_bias, self.noise)
        return cpu4_mem

    def cpu1_output(self, tb1, cpu4, cpu1):
        """
        Compute the CPU1 layer output given the current TB1 and CPU4 activities

        :param tb1: tb1 The current TB1 activity.
        :param cpu4: cpu4 The current CPU4 activity.
        :param cpu1: The CPU1 layer to be updated.
        :return: cpu1
        """
        cpu1 = self.W_CPU4_CPU1 @ cpu4 - self.W_TB1_CPU1 @ tb1
        cpu1 = self.sigmoid(cpu1, self.cpu1_slope, self.cpu1_bias, self.noise)
        return cpu1

    def motor_output(self, cpu1):
        """
        Compute the motor output from the CPU1 layer activity.

        :param cpu1: The current CPU1 population.
        :return: The network output which will be positive or negative depending on
        whether the model is indicating a left or right turn.
        """
        output = float(np.dot(self.W_CPU1_motor, cpu1))
        return output

    def unimodal_monolithic_CX(self, theta, speed):
        """
        A helper function which wraps model usage, removing the need to call
        each individual function in sequence as in the AntBot.

        :param theta: The current angular input from available cues.
        :param speed: The agent's current speed.
        :return: The return value of CentralComplex::motor_output.
        """
        self.TL2 = self.tl2_output(theta, self.TL2)
        self.CL1 = self.cl1_output(self.TL2, self.CL1)
        self.TB1 = self.tb1_output(self.CL1, self.TB1)
        self.MEM = self.cpu4_update(speed, self.TB1, self.MEM)
        self.CPU4 = self.MEM
        self.CPU4 = self.cpu4_output(self.CPU4)
        self.CPU1 = self.cpu1_output(self.TB1, self.CPU4, self.CPU1)
        return self.motor_output(self.CPU1)

    def get_status(self):
        """
        Collects the current network activity into a single data so that it can be
        read elsewhere in the ROS sofwtware ecosystem (implemented primarily for
        visualising the CX activity).

        :return: The data structure to be filled with the network state.
        """
        activity = [
            self.TL2.flatten().tolist(),
            self.CL1.flatten().tolist(),
            self.TB1.flatten().tolist(),
            self.CPU4.flatten().tolist(),
            self.MEM.flatten().tolist(),
            self.CPU1.flatten().tolist()
        ]
        return activity


if __name__ == '__main__':
    pass
