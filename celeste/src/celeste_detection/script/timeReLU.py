from scipy.spatial.transform import Rotation

rot = Rotation.from_quat([0,0,0.04,0.99])

rot_euler = rot.as_euler('xyz')
print(rot_euler)

