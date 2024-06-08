PASSWORD = celestial

ROS_DOMAIN_ID = 30

MAC_ADDRESS = D8:3A:DD:58:91:B1

To get ip address:
`sudo arp-scan -l | sort`, then look for MAC address.

## Bringup

SBC: `ros2 launch turtlebot3_bringup robot.launch.py` or `bringup`

PC: `ros2 run turtlebot3_teleop teleop_keyboard`


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

