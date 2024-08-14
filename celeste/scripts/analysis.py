import circstats as cs
import models as md

import scipy.signal as ss
import numpy as np

MAX_INT = 11000.
cutoff = 0.03
fs = 2.0
order = 1


def butter_low_pass_filter(x):
    beta, alpha = ss.butter(order, cutoff, fs=fs, btype='low', analog=False)
    return ss.filtfilt(beta, alpha, x)


def compare(x, ground_truth, error_type=None, axis=None, std=False):
    ang_distance = cs.circ_norm(x - ground_truth)
    # ang_distance_org = ang_distance.copy()

    if error_type is None:
        error_type = "mean error"

    if error_type in ["mean error", "mne"]:
        result = [np.nanmean(ang_distance, axis=axis)]
    elif error_type in ["mean absolute error", "mae"]:
        ang_distance = abs(ang_distance)
        result = [np.nanmean(ang_distance, axis=axis)]
    elif error_type in ["root mean square error", "rmse"]:
        ang_distance = np.square(ang_distance)
        result = [np.sqrt(np.nanmean(ang_distance, axis=axis))]
    elif error_type in ["max error", "mxe"]:
        ang_distance = abs(ang_distance)
        result = [np.nanmax(ang_distance, axis=axis)]
    else:
        print(f"Unknown error type: '{error_type}'")
        return None

    if std:
        result += [np.nanstd(ang_distance, axis=axis)]

    return result


def compute_sensor_output_from_responses(pol, iny, yaw, pol_angles, polarisation=True, intensity=True):

    nb_samples, spatial_resolution = pol.shape
    sol_angles = cs.circ_norm(np.linspace(0, 2 * np.pi, 8, endpoint=False))
    all_pol_angles = np.zeros(nb_samples, dtype='float32')

    for s in range(nb_samples):
        pol_i = pol[s]
        int_i = iny[s]

        # calculate the SOL responses
        sol = np.zeros(8, dtype='float32')
        if polarisation and not intensity:
            sol = md.pol2sol(-pol_i, pol_prefs=pol_angles, sol_prefs=sol_angles)
        elif intensity and not polarisation:
            sol = md.pol2sol(int_i, pol_prefs=pol_angles, sol_prefs=sol_angles)
        elif intensity and polarisation:
            sol = md.pol2sol(int_i - pol_i, pol_prefs=pol_angles, sol_prefs=sol_angles)
        elif not intensity and not polarisation:
            sol_i = md.pol2sol(int_i, pol_prefs=pol_angles, sol_prefs=sol_angles)  # intensity
            sol_p = md.pol2sol(-pol_i, pol_prefs=pol_angles, sol_prefs=sol_angles)  # polarisation
            sol = (sol_i + sol_p) / 2
        all_pol_angles[s], sigma = md.sol2angle(sol)

    imu_angles = np.array(yaw)
    return np.squeeze(all_pol_angles + np.pi) % (2 * np.pi) - np.pi, np.squeeze(imu_angles)


def get_sensor_responses(data, imu_samples=360, imu_drift=0., nb_nearest=11):

    i_valid = [[0, 1, 2, 3, 6]]
    # i_valid = [[1, 2]]

    imu_angles = (np.linspace(0, 2 * np.pi, imu_samples, endpoint=False) + np.pi) % (2 * np.pi) - np.pi
    all_pol_res = np.zeros(imu_samples, dtype='float32')
    all_int_res = np.zeros(imu_samples, dtype='float32')
    all_000_res = np.zeros(imu_samples, dtype='float32')
    all_045_res = np.zeros(imu_samples, dtype='float32')
    all_090_res = np.zeros(imu_samples, dtype='float32')
    all_135_res = np.zeros(imu_samples, dtype='float32')

    if 'device' in data.columns.to_list():
        data_rec = data[np.any(data["device"].to_numpy()[:, None] == i_valid, axis=1)]

        imu_pol = np.deg2rad(data_rec["IMU"].to_numpy())
        imu_iny = imu_pol
        imu_000 = imu_pol
        imu_045 = imu_pol
        imu_090 = imu_pol
        imu_135 = imu_pol
        pol = data_rec["POL"].to_numpy()
        iny = data_rec["INT"].to_numpy()
        s000 = np.clip(data_rec["I000"].to_numpy() / MAX_INT, np.finfo(float).eps, 1)
        s045 = np.clip(data_rec["I045"].to_numpy() / MAX_INT, np.finfo(float).eps, 1)
        s090 = np.clip(data_rec["I090"].to_numpy() / MAX_INT, np.finfo(float).eps, 1)
        s135 = np.clip(data_rec["I135"].to_numpy() / MAX_INT, np.finfo(float).eps, 1)
    else:
        imu_pol = np.deg2rad(data[data["unit_type"] == "POL"]["direction"].to_numpy())
        imu_iny = np.deg2rad(data[data["unit_type"] == "INT"]["direction"].to_numpy())
        imu_000 = np.deg2rad(data[data["unit_type"] == "I000"]["direction"].to_numpy())
        imu_045 = np.deg2rad(data[data["unit_type"] == "I045"]["direction"].to_numpy())
        imu_090 = np.deg2rad(data[data["unit_type"] == "I090"]["direction"].to_numpy())
        imu_135 = np.deg2rad(data[data["unit_type"] == "I135"]["direction"].to_numpy())

        pol = data[data["unit_type"] == "POL"]["response"].to_numpy()
        iny = data[data["unit_type"] == "INT"]["response"].to_numpy()
        s000 = data[data["unit_type"] == "I000"]["response"].to_numpy()
        s045 = data[data["unit_type"] == "I045"]["response"].to_numpy()
        s090 = data[data["unit_type"] == "I090"]["response"].to_numpy()
        s135 = data[data["unit_type"] == "I135"]["response"].to_numpy()

    for s in range(imu_samples):
        # get the desired absolute rotation of the compass (with respect to north)
        rotate = imu_angles[s] + imu_drift

        # calculate the distance between the orientation of each unit in the desired compass orientation
        # and the orientation of each unit in the dataset
        p_dist = abs((imu_pol + rotate + np.pi) % (2 * np.pi) - np.pi)
        i_dist = abs((imu_iny + rotate + np.pi) % (2 * np.pi) - np.pi)
        s0_dist = abs((imu_000 + rotate + np.pi) % (2 * np.pi) - np.pi)
        s1_dist = abs((imu_045 + rotate + np.pi) % (2 * np.pi) - np.pi)
        s2_dist = abs((imu_090 + rotate + np.pi) % (2 * np.pi) - np.pi)
        s3_dist = abs((imu_135 + rotate + np.pi) % (2 * np.pi) - np.pi)

        # keep the dataset entries with the nearest orientations for each sensor
        p_nearest = np.argsort(p_dist, axis=0)[:nb_nearest]
        i_nearest = np.argsort(i_dist, axis=0)[:nb_nearest]
        s0_nearest = np.argsort(s0_dist, axis=0)[:nb_nearest]
        s1_nearest = np.argsort(s1_dist, axis=0)[:nb_nearest]
        s2_nearest = np.argsort(s2_dist, axis=0)[:nb_nearest]
        s3_nearest = np.argsort(s3_dist, axis=0)[:nb_nearest]

        # calculate the median response of the POL and INT units on the preferred angles
        all_pol_res[s] = np.median(pol[p_nearest], axis=0)
        all_int_res[s] = np.median(iny[i_nearest], axis=0)
        all_000_res[s] = np.median(s000[s0_nearest], axis=0)
        all_045_res[s] = np.median(s045[s1_nearest], axis=0)
        all_090_res[s] = np.median(s090[s2_nearest], axis=0)
        all_135_res[s] = np.median(s135[s3_nearest], axis=0)

    return all_pol_res, all_int_res, all_000_res, all_045_res, all_090_res, all_135_res


def get_sensor_responses_per_rotation(data, imu_samples=360, imu_drift=0., nb_nearest=11):
    ang_x = data.groupby("rotation").apply(lambda x: get_sensor_responses(
        x, imu_samples=imu_samples, imu_drift=imu_drift, nb_nearest=nb_nearest))

    pol_res = np.array([x[0] for x in ang_x.to_numpy()], dtype='float64')
    int_res = np.array([x[1] for x in ang_x.to_numpy()], dtype='float64')
    p00_res = np.array([x[2] for x in ang_x.to_numpy()], dtype='float64')
    p45_res = np.array([x[3] for x in ang_x.to_numpy()], dtype='float64')
    p90_res = np.array([x[4] for x in ang_x.to_numpy()], dtype='float64')
    m45_res = np.array([x[5] for x in ang_x.to_numpy()], dtype='float64')

    return pol_res, int_res, p00_res, p45_res, p90_res, m45_res
