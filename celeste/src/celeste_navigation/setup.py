from setuptools import find_packages, setup

package_name = 'celeste_navigation'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Nash Xu',
    maintainer_email='nashdrovin@gmail.com',
    description='TODO: Package description',
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pol_op_tester = celeste_navigation.multi_pol_op_tester:main',
            'cmd_vel = celeste_navigation.cmd_vel_node:main',
            'pol_cue_detector = celeste_navigation.pol_cue_detector_node:main',
            'pi = celeste_navigation.pi_node:main',
            'teleop = celeste_navigation.teleop_keyboard:main',
            'simple_pub = celeste_navigation.simple_pub:main',
            'simple_sub = celeste_navigation.simple_sub:main',
        ],
    },
)
