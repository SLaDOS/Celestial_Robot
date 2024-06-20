`ssh nash@10.42.0.133`
`ros2 run turtlebot3_teleop teleop_keyboard`


PASSWORD = celestial\
ROS_DOMAIN_ID = 133\
TurtleBot3_MAC_ADDRESS = D8:3A:DD:58:91:B1

To get ip address:\
check hotspot panel\
or `$ sudo hostname -I`\
or `$ sudo arp-scan -l | sort`, then look for MAC address.

TurtleBot static IP address: \
`192.168.137.133` on 'TurtleBotBurger'(Windows)\
`10.42.0.133` on 'turtlebot_remote_ubuntu'

To copy a file from B to A while logged into B:\
`scp /path/to/file username@a:/path/to/destination`\
To copy a file from B to A while logged into A:\
`scp username@b:/path/to/file /path/to/destination`


## Bring up

SBC: `ros2 launch turtlebot3_bringup robot.launch.py` or `bringup`


## SSH TurtleBot by WSL 

solving reference:
https://superuser.com/questions/1764148/ssh-into-device-through-wsl-when-connected-via-hotspot?newreg=ee5035b5bbba4b90b391249d9ff4969a

- edit `.wslconfig` in `C:\Users\Nash Xu` with:
  ```
  [wsl2]
  networkingMode=mirrored
  ```

- open WSL

- ```bash
    ssh "nash xu"@localhost
    ssh nash@<turtlebot_ip>
    ```


## Troubles:

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

