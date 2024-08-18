# Celestial_Robot

## TODO:
- clear, cloud, very cloud, near building, near grass 


## Information

    Raspberry Pi Version: Raspberry Pi 4 Model B
    Robot: TURTLEBOT3 Burger (2022)
    Raspberry Pi OS: Ubuntu 22.04 Server
    Host PC OS: Ubuntu 22.04 Desktop
    ROS: Humble

    Raspberry Pi PASSWORD = celestial
    ROS_DOMAIN_ID = 133
    TurtleBot3_MAC_ADDRESS = D8:3A:DD:58:91:B1
    Suitable MIN_TURN_SPEED = 0.1

To get ip address:\
check hotspot panel\
or `$ sudo hostname -I`\
or `$ sudo arp-scan -l | sort`, then look for MAC address.

TurtleBot static IP address: \
`192.168.137.133` when connect to 'TurtleBotBurger'(Windows)\
`10.42.0.133` when connect to 'turtlebot_remote_ubuntu' on Ubuntu

## Troubleshooting:

###  Set static IP on Ubuntu Server 22.04

``` `gateway4` has been deprecated, use default routes instead```
https://unix.stackexchange.com/questions/681220/netplan-generate-gateway4-has-been-deprecated-use-default-routes-instead

### Cannot connect robot to hotspot on Ubuntu Server 22.04

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

#### Further: Use more than two I2C buses   

*This has been tested without pulling up and failed.

##### Bit-bang I2C on the GPIO: 
edit `/boot/firmware/overlays/README` 
with new line `dtoverlay=i2c-gpio,bus=2,i2c_gpio_sda=17,i2c_gpio_scl=27`
More information see`/boot/firmware/overlays/README`

##### Need pull up
> You need to ensure that you have suitable pulls to 3V3 on all the GPIO used to bit bang I2C. 
> For information GPIO 2/3 have 1k8 pulls to 3V3. 
> 
> Reference: https://forums.raspberrypi.com/viewtopic.php?t=108653#p1563253
>
> Also see https://forums.raspberrypi.com/viewtopic.php?t=353041 for pull up

