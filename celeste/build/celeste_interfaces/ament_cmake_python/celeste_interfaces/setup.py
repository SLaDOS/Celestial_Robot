from setuptools import find_packages
from setuptools import setup

setup(
    name='celeste_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('celeste_interfaces', 'celeste_interfaces.*')),
)