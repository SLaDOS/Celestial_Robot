from rosbags.rosbag2 import Reader
from rosbags.typesys import Stores, get_typestore
from matplotlib import pyplot as plt
import numpy as np
from skylight import ephemeris, observer
from datetime import datetime
import time
import os
import glob
from pathlib import Path




BAG = '../my_bags/saved/test_2024_07_30-15_49/'

bagfiles = glob.glob(BAG+"pol_op*")
print(bagfiles)
MAX_INT = 11000.0
# Edinburgh
LON = 55.945011324580385
LAT = -3.1867749119995956

angles = {
    'pol_op_0': np.radians(0),
    'pol_op_1': np.radians(90),
    'pol_op_2': np.radians(180),
    'pol_op_3': np.radians(270),
    'pol_op_4': np.radians(45),
    'pol_op_5': np.radians(135),
    'pol_op_6': np.radians(225),
    'pol_op_7': np.radians(315),
}


# Create a typestore and get the string class.
typestore = get_typestore(Stores.LATEST)

for bagname in bagfiles:
    yaw = []
    t = []
    pols = [[] for x in range(8)]
    outs = []
    t_pol = [[] for x in range(8)]

    with Reader(bagname) as reader:
        # for connection in reader.connections:
        #     print(connection.topic, connection.msgtype)
        # Iterate over messages.
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
    assert len(yaw) == len(pols[0]) == len(pols[1]) == len(pols[2]) == len(pols[3]) \
           == len(pols[4]) == len(pols[5]) == len(pols[6]) == len(pols[7])

    record_time = datetime.fromtimestamp(t[0]/10**9)
    sun = ephemeris.Sun(observer.Observer(LON, LAT, date=record_time))

    data_num = len(pols[0])
    P, I, C = np.zeros((3, data_num, len(pols)))
    js = [0, 2, 4, 6, 1, 3, 5, 7]
    for _data_id in range(len(pols[0])):
        z = 0
        for _pol_id in range(len(pols)):
            pol = pols[_pol_id][_data_id]
            i90 = np.clip(abs(pol[2]) / MAX_INT, np.finfo(float).eps, 1)
            i0 = np.clip(abs(pol[3]) / MAX_INT, np.finfo(float).eps, 1)
            i = (i0 + i90) / 2.0
            p = (i0 - i90) / (2 * i)
            assert 1 > p > -1, f'p = {p}'
            c = i - p
            P[_data_id, js[_pol_id]] = p
            I[_data_id, js[_pol_id]] = i
            C[_data_id, js[_pol_id]] = c
            z += c * np.exp(1j * angles['pol_op_' + str(_pol_id)])

        out = np.angle(z) + sun.az
        outs.append(out)

        # # The .messages() method accepts connection filters.
        # connections = [x for x in reader.connections if x.topic == '/imu_raw/Imu']
        # for connection, timestamp, rawdata in reader.messages(connections=connections):
        #     msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
        #     print(msg.header.frame_id)

    assert len(outs) == len(yaw)

    yaw_uw = np.unwrap(np.degrees(yaw), period=360) - np.degrees(yaw[0]) + np.degrees(outs[0])
    out_uw = np.unwrap(np.degrees(outs), period=360)
    print(out_uw[0])
    fig, ax = plt.subplots()
    ax.plot(np.array(t) - t[0], yaw_uw)
    ax.plot(np.array(t) - t[0], out_uw)
    ax.set(xlabel='time', ylabel='yaw',
           title=f'{bagname[-19:]}')
    ax.grid()
    plot_directory = BAG+'plots/'
    Path(plot_directory).mkdir(parents=False, exist_ok=True)
    plt.savefig(plot_directory+os.path.basename(bagname)+'-plot1')

    # plt.figure('P', figsize=(10, 6))
    # plt.subplot(311)
    # plt.imshow(-P.T)
    # plt.subplot(312)
    # plt.imshow(I.T)
    # plt.subplot(313)
    # plt.imshow(C.T)
    # plt.tight_layout()
    # plt.savefig(bagname+'plot2')

    rmse = np.sqrt(np.mean(np.square((yaw_uw - out_uw + 180) % 360 - 180)))
    print(f"RMSE: {rmse:.2f}")
