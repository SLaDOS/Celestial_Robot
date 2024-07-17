from rosbags.rosbag2 import Reader
from rosbags.typesys import Stores, get_typestore
from matplotlib import pyplot as plt
import numpy as np


# Create a typestore and get the string class.
typestore = get_typestore(Stores.LATEST)

# Create reader instance and open for reading.
with Reader('../my_bags/success-pol_op_tester_2024_07_17-13_10_57') as reader:
    # Topic and msgtype information is available on .connections list.
    for connection in reader.connections:
        print(connection.topic, connection.msgtype)

    # Iterate over messages.
    yaw = []
    t = []
    pols = [[] for x in range(8)]
    outs = []
    t_pol = [[] for x in range(8)]
    angles = {
        'pol_op_0': (np.pi/4),
        'pol_op_1': (np.pi/4)*2,
        'pol_op_2': (np.pi/4)*4,
        'pol_op_3': (np.pi/4)*6,
        'pol_op_4': (np.pi/4)*1,
        'pol_op_5': (np.pi/4)*3,
        'pol_op_6': (np.pi/4)*5,
        'pol_op_7': (np.pi/4)*7,
    }
    count = 0
    for connection, timestamp, rawdata in reader.messages():
        msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
        if connection.topic == 'yaw':
            msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
            yaw.append(msg.data)
            t.append(timestamp)
        elif connection.topic[:-1] == 'pol_op_':
            pol_id = int(connection.topic[-1])
            pols[pol_id].append(msg.data)
            t_pol[pol_id].append(timestamp)

    assert (len(pols[0])) == len(yaw)

    for n in range(len(pols[0])):
        z = 0
        for a in range(len(pols)):
            pol = pols[a][n]
            i0 = abs(pol[2])
            i90 = abs(pol[3])
            i = (i0+i90)/2.0
            p = (i0-i90)/(2*i)
            assert 1 > p > -1, f'p = {p}'
            c = i - p
            z += c*np.exp(1j*angles['pol_op_'+str(a)])
        out = np.angle(z)
        outs.append(out)
    assert len(outs) == len(yaw)
    fig, ax = plt.subplots()
    ax.plot(t, yaw)
    ax.plot(t, outs)
    ax.set(xlabel='time', ylabel='yaw',
           title='title')
    ax.grid()
    plt.show()

    # # The .messages() method accepts connection filters.
    # connections = [x for x in reader.connections if x.topic == '/imu_raw/Imu']
    # for connection, timestamp, rawdata in reader.messages(connections=connections):
    #     msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
    #     print(msg.header.frame_id)
