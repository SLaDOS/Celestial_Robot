from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'my_experiment'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nash',
    maintainer_email='nashdrovin@gmail.com',
    description='a experiment to return to the starting point after some movement',
    license='GPL-3.0-only',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'return_action_server = my_experiment.return_action_server:main',
            'teleop_keyboard = my_experiment.teleop_keyboard:main',
            'inspector = my_experiment.inspector:main',
        ],
    },
)
