Version Info:

    Raspberry Pi Version: Raspberry Pi 4 Model B
    Robot: TURTLEBOT3 Burger
    Raspberry Pi System: Ubuntu 22.04 Server
    Host PC System: Ubuntu 22.04 Desktop

    Pi PASSWORD = celestial
    ROS_DOMAIN_ID = 133
    TurtleBot3_MAC_ADDRESS = D8:3A:DD:58:91:B1

To get ip address:\
check hotspot panel\
or `$ sudo hostname -I`\
or `$ sudo arp-scan -l | sort`, then look for MAC address.

TurtleBot static IP address: \
`192.168.137.133` on 'TurtleBotBurger'(Windows)\
`10.42.0.133` on 'turtlebot_remote_ubuntu'

## Troubleshooting:

### When set static IP on Ubuntu Server 22.04 (solved):

``` `gateway4` has been deprecated, use default routes instead```
https://unix.stackexchange.com/questions/681220/netplan-generate-gateway4-has-been-deprecated-use-default-routes-instead

### Connect robot to ubuntu server (solved)

Similar problems: https://bugs.launchpad.net/ubuntu/+source/wpa/+bug/1972790

**Solution**:

TL;DR: do not use a password
https://askubuntu.com/a/1407833
    
    Turn off the wifi, via the drop down top menu. Then go to:
    Show Applications --> Advanced Network
    
    Then in "Network Connections" dialog:

    1. Remove the Hotspot connection
    2. Add a new one (+ sign)
    3. choose WIFI for type of connection
    4. Name it and give it a SSID
    5. Change MODE to Hotspot
    6. Save Then restart the wifi via the top menu, and try to connect with your phone.
    
    I didn't mess much with a passwords as I don't need them.

### SSH the original System in WSL 

solving reference:
https://superuser.com/questions/1764148/ssh-into-device-through-wsl-when-connected-via-hotspot?newreg=ee5035b5bbba4b90b391249d9ff4969a

1. edit `.wslconfig` in `C:\Users\Nash Xu` with:
  ```
  [wsl2]
  networkingMode=mirrored
  ```
2. open WSL
3. `$ ssh "nash xu"@localhost`

### I2C-0 pins not working on Raspberry Pi 4B: "Error: Could not open file `/dev/i2c-0' or `/dev/i2c/0': No such file or directory"
edit `/boot/firmware/overlays/README`
add new line `dtparam=i2c_vc=on`

### Further: Add more I2C pins 

This has not been tested.

Bit bang I2C on the GPIO: edit `/boot/firmware/overlays/README` 
with new line `dtoverlay=i2c-gpio,bus=2,i2c_gpio_sda=17,i2c_gpio_scl=27`
More information see`/boot/firmware/overlays/README`
> You need to ensure that you have suitable pulls to 3V3 on all the GPIO used to bit bang I2C. 
> For information GPIO 2/3 have 1k8 pulls to 3V3. \
> Reference: https://forums.raspberrypi.com/viewtopic.php?t=108653#p1563253


## ROS 2

### Create a package dedicated to ROS2 custom messages
https://roboticsbackend.com/ros2-create-custom-message/#Create_a_package_dedicated_to_ROS2_custom_messages

> In theory you could create custom messages in any package you want, but this could lead to many problems. For example, if you create the message in package A and you need this message in package B, you’ll have to add a dependency to package A. This will quickly result in a dependency mess with unneeded and cycling dependencies.
> 
> So, the best practice here is to create a package dedicated to ROS2 custom messages, and only that. Then you’ll be able to add a dependency to this package, from any package requiring your custom interfaces.


