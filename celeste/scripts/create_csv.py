import pandas
from rosbags.rosbag2 import Reader
from rosbags.typesys import Stores, get_typestore
from matplotlib import pyplot as plt
import numpy as np
from skylight import ephemeris, observer
from datetime import datetime
import time
import os
import glob

BAG = ('../my_bags/saved/'
       'test_2024_07_24-14_19'
       '/')

bagfiles = glob.glob(BAG+"pol_op*")
print(bagfiles)
MAX_INT = 11000.0
# Edinburgh
LAT = 55.945011324580385
LON = -3.1867749119995956

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
df_lst = []

for i_b, bagname in enumerate(bagfiles):
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
    sun = ephemeris.Sun(observer.Observer(LON, LAT, date=record_time, degrees=True))

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

            new_pol_row = {'time': record_time, 'unit_type': 'POL', 'response': p,
                           'sun_azimuth': np.degrees(sun.az), 'sun_elevation': np.degrees(sun.alt),
                           'yaw': np.degrees(yaw[_data_id]),
                           'device_yaw': np.degrees(angles['pol_op_' + str(_pol_id)]),
                           'rotation': i_b+1,
                           'session': 'session1'
                           }
            df_lst.append(new_pol_row)
            new_int_row = {'time': record_time, 'unit_type': 'INT', 'response': i,
                           'sun_azimuth': np.degrees(sun.az), 'sun_elevation': np.degrees(sun.alt),
                           'yaw': np.degrees(yaw[_data_id]),
                           'device_yaw': np.degrees(angles['pol_op_' + str(_pol_id)]),
                           'rotation': i_b+1,
                           'session': 'session1'
                           }
            df_lst.append(new_int_row)

df = pandas.DataFrame(df_lst)
df.to_csv(f'./csv/{BAG[-22:-1]}.csv', index=False)
