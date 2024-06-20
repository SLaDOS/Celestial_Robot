    Version Info: 
    PC: Ubuntu Desktop 22.04
    SBC: Raspberry Pi 4 Model B with Ubuntu Server 22.04

`$ sudo nano /etc/netplan/50-cloud-init.yaml`
to edit netplan and name it as `50-cloud-init.yaml`

[1] works well with no password. It doesn't work with a password.
Needs an ethernet cable connected to the PC to let the PC and SBC both access the Internet.
Edit the static IP address if needed (row 13 and 16). 

Set a hotspot on Ubuntu as following:

    Turn off the wifi, via the drop down top menu. Then go to:
    Show Applications --> Advanced Network
    
    Then in "Network Connections" dialog:

    1. Remove the Hotspot connection
    2. Add a new one (+ sign)
    3. choose WIFI for type of connection
    4. Name it and give it a SSID
    5. Change MODE to Hotspot
    6. Save Then restart the wifi via the top menu, and try to connect with your phone.


[2] uses Eduroam. Cannot set a static IP.

In Eduroam, ROS2 nodes on different machines cannot find each other with the same ROS_DOMAIN_ID.
You can control the robot by SSH.

[3] uses a third Wi-Fi, e.g. your phone hotspot or a laptop hotspot. Works well.