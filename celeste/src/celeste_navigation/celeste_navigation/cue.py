from celeste_interfaces.msg import CueMsg


class Cue:
    """
    Global Cue class to keep representation consistent.

    """

    def __init__(self, cue_type: str, sensitivity: float, contrast: float, azimuth: float):
        """
        Constructor.

        Essentially this class represents a cue as a polar vector with
        some additional conceptual wrapping. Generally, the important
        parameters are contrast (magnitude, expected to be between 0
        and 1) and azimuth (angle, assumed to be in radians).

        :param cue_type: The type of cue, this is primarily used to determine equality.
        :param sensitivity: The agent's sensitivity to this cue.
        :param contrast: The contrast of the cue (following Mitchell et al. (2023))
        :param azimuth: The angle of the cue.
        """
        self.type = cue_type
        self.sensitivity = sensitivity
        self.contrast = contrast
        self.theta = azimuth

    def get_contrast(self) -> float:
        """Get the contrast parameter"""
        return self.contrast

    def get_type(self) -> str:
        """Get the type parameter"""
        return self.type

    def get_theta(self) -> float:
        """Get the azimuth of the cue"""
        return self.theta

    def get_sensitivity(self) -> float:
        """Get the sensitivity parameter"""
        return self.sensitivity

    def set_contrast(self, r: float):
        """
        Set the contrast parameter
        :param r: The desired contrast (between 0 and 1 inclusive).
        :warning: If r > 1 or r < 0 then the function quietly ignores
        r and the contrast will not be updated.
        """
        if 0 <= r <= 1:
            self.contrast = r

    def set_azimuth(self, t: float):
        """
        Set the cue azimuth.
        :param t: The angle of the cue.
        :warning: It is assumed that the value is in radians. Note also
        that the passed angle is not mapped into 0, 2pi or -pi, pi.
        It is up to the caller to be consistent with angular representations.
        """
        self.theta = t

    @staticmethod
    def to_cue(cue_msg: CueMsg):
        """
        Translate a cue_msg to a Cue object.
        :param cue_msg: The message containing cue information.
        :return: An equivalent Cue object
        """
        result = Cue(
            cue_msg.type,
            cue_msg.sensitivity,
            cue_msg.contrast,
            cue_msg.theta
        )
        return result

    def to_string(self):
        return f"\nType: {self.type}\nSens: {self.sensitivity}\nCtst: {self.contrast}\nThta: {self.theta}\n"

    def to_msg(self):
        """
        Translate a Cue object into an equivalent message format.
        :param cue: The Cue object.
        :return: An equivalent message object.
        """
        return CueMsg(
            type=self.get_type(),
            sensitivity=float(self.get_sensitivity()),
            contrast=float(self.get_contrast()),
            theta=float(self.get_theta()),
        )

    def __eq__(self, other):
        """
        Equality check. Two Cue objects are defined as equal if they
        are of the same type.
        """
        return self.type == other.type

    def __copy__(self):
        """
        Assignment overload (creates a copy of other).
        """
        return Cue(self.type, self.sensitivity, self.contrast, self.theta)
