import glob
import os
import matplotlib.pyplot as plt

import numpy as np
import analysis
import circstats as cs
import pandas as pd

data_base = os.path.abspath(os.path.join(os.getcwd(), '.', 'csv'))
out_base = os.path.abspath(os.path.join(os.getcwd(), '.', 'plots'))
if not os.path.exists(out_base):
    os.makedirs(out_base)

cmap_dict = {
    "ring_size": "viridis",
    "ele_bins": "viridis",
    "sun_elevation": "viridis",
    "cloud_status": "tab10",
    "canopy_status": "Dark2"
}
i_colour = '#ff5555ff'
p_colour = '#cd55ffff'
c_colour = '#557dffff'
z_colour = '#ffffffff'
e_colour = '#555555ff'
box_colour = {
    "INT": i_colour,
    "POL": p_colour,
    "INT-POL": c_colour,
    "FZ": z_colour,
    "EIG": e_colour
}

solar_elevation_selected = [
    'Monday_14-11-22_07-35-27_SAST',
]


def plot_circ_error_bars(theta, rho, errors, color='black', edge_color='black', alpha=1., axis=None):
    q25, q75 = cs.circ_norm(np.asanyarray(errors))
    assert not (np.isnan(q25) or np.isnan(q75)), f'{errors}'
    q25 += 2 * np.pi
    q75 -= 2 * np.pi
    while q75 < theta and not np.isclose(q75, theta):
        q75 += 2 * np.pi
    while q25 > theta and not np.isclose(q25, theta):
        q25 -= 2 * np.pi

    nb_samples = int(np.rad2deg(q75 - q25))

    if nb_samples % 2 == 0:  # ensure its odd
        nb_samples += 1

    ang = np.linspace(q25, q75, nb_samples)

    axis.plot(ang, rho * np.ones_like(ang), color=edge_color, lw=1, alpha=alpha, zorder=1)
    axis.plot(theta, rho, color=edge_color, markerfacecolor=color, alpha=alpha, zorder=1,
              marker=(3, 0, -np.rad2deg(theta)), markersize=3)


def plot_responses_over_imu(x, y, sun=None, negative=False, prediction=None, error=None, axis=None,
                            c=0, color="red", y_padding=.1, x_ticks=True, y_min=-1, y_max=1, filtered=False):
    if axis is None:
        axis = plt.subplot(111)

    max_recording = 15

    axis.set_theta_direction(-1)
    axis.set_theta_zero_location("N")

    x = (x + np.pi) % (2 * np.pi) - np.pi
    i_sort = np.argsort(x)

    x = x[i_sort]
    r = y[i_sort]

    if filtered and len(r) > 10:
        r = analysis.butter_low_pass_filter(np.r_[r[-50:], r, r[:50]])[50:-50]

    axis.plot(x, r, color=color[:-2] + '88', lw=0.5, alpha=1 - c / max_recording, zorder=2)

    if sun is not None:
        axis.quiver(sun, -1, np.sin(sun), np.cos(sun), scale=.02, width=.02, color='lightgreen', zorder=0)

    if prediction is None:
        arrow = np.mean(np.exp(1j * x) * r * np.power(-1, float(negative)))
    else:
        arrow = np.exp(1j * prediction)

    if error is None:
        axis.quiver(np.angle(arrow), 1, np.imag(arrow) / abs(arrow), np.real(arrow) / abs(arrow),
                    scale=6 - 6 * c / max_recording, color=f"{1 - c / max_recording:.2f}", zorder=1)
    else:
        plot_circ_error_bars(prediction, c / max_recording + 1, error,
                             color=color, edge_color=color, alpha=1 - c / max_recording, axis=axis)

    # ax.scatter((x - np.pi) % (2 * np.pi) - np.pi, y[:, 0], s=20, facecolor=f'C{c+2}', marker='.')
    # ax.scatter((x - np.pi) % (2 * np.pi) - np.pi, y[:, 1], s=20, facecolor=f'C{c+4}', marker='.')
    # ax.scatter((x - np.pi) % (2 * np.pi) - np.pi, y[:, 2], s=20, facecolor=f'C{c+6}', marker='.')
    # ax.scatter((x - np.pi) % (2 * np.pi) - np.pi, y[:, 3], s=20, facecolor=f'C{c+8}', marker='.')

    axis.set_yticks([-1, 0])
    axis.set_yticklabels([""] * 2)
    axis.set_xticks([-3 * np.pi / 4, -np.pi / 2, -np.pi / 4, 0, np.pi / 4, np.pi / 2, 3 * np.pi / 4, np.pi])
    axis.set_xticklabels(["", "W", "", "N", "", "E", "", "S"])
    axis.spines["polar"].set_visible(False)

    if not x_ticks:
        axis.set_xticks([])

    # ax.set_ylim([-y_padding, 2 * np.pi + y_padding])
    axis.set_ylim([y_min - y_padding, y_max + 1 + y_padding])
    axis.set_xlim([-np.pi, np.pi])

    return axis, np.angle(arrow)


def plot_responses(dataset_path, sessions=None, figure=None, figsize=(9, 2)):
    dataset_base = os.path.dirname(dataset_path)
    df = pd.read_csv(dataset_path)

    if sessions is None:
        sessions = solar_elevation_selected

    if sessions is not None:
        mosaic = [[f"{image_file} int", f"{image_file} pol", f"{image_file} int-pol"]
                  for image_file in sessions]

        fig, ax = plt.subplot_mosaic(mosaic, figsize=(figsize[0], figsize[1] * len(sessions)),
                                     subplot_kw={'projection': 'polar'})

        for i_s, session in enumerate(sessions):
            dfs = df[df["session"] == session]

            sun_azi = np.deg2rad(np.mean(dfs["sun_azimuth"].to_numpy()))

            dfs_ = dfs.groupby(
                ["time", "unit_type", "sun_azimuth", "sun_elevation", "yaw", "device_yaw", "rotation", "session"],
                as_index=False
            ).mean()

            pol_res = dfs_[dfs_["unit_type"] == "POL"]
            int_res = dfs_[dfs_["unit_type"] == "INT"]

            rotations = dfs_["rotation"].unique()

            for r in rotations:
                # Check these two:
                pol_res_df = pol_res[pol_res["rotation"] == r].pivot_table(index="yaw", columns="device_yaw",
                                                                           values="response")
                int_res_df = int_res[int_res["rotation"] == r].pivot_table(index="yaw", columns="device_yaw",
                                                                           values="response")
                pol_res_ = pol_res_df.to_numpy()
                int_res_ = int_res_df.to_numpy()

                yaws = np.radians(pol_res_df.index.to_list())
                device_yaw = np.radians(pol_res_df.columns.to_list())

                # nb_recordings x nb_samples
                ang_pol, x_pol = analysis.compute_sensor_output_from_responses(
                    pol_res_, int_res_, yaws, device_yaw, polarisation=True, intensity=False)
                ang_int, x_int = analysis.compute_sensor_output_from_responses(
                    pol_res_, int_res_, yaws, device_yaw, polarisation=False, intensity=True)
                ang_inp, x_inp = analysis.compute_sensor_output_from_responses(
                    pol_res_, int_res_, yaws, device_yaw, polarisation=True, intensity=True)

                pol_q25, pol_q50, pol_q75 = cs.circ_quantiles(ang_pol - x_pol, axis=-1)
                int_q25, int_q50, int_q75 = cs.circ_quantiles(ang_int - x_int, axis=-1)
                inp_q25, inp_q50, inp_q75 = cs.circ_quantiles(ang_inp - x_inp, axis=-1)

                x_imu = (device_yaw[None, :] - yaws[:, None]).flatten() % (2 * np.pi)
                y_pol = pol_res_.flatten()
                y_iny = int_res_.flatten()
                y_inp = (int_res_ - pol_res_).flatten()

                plot_responses_over_imu(
                    x_imu, y_pol, axis=ax[f"{session} pol"], color=p_colour,
                    prediction=pol_q50, error=(pol_q25, pol_q75),
                    c=r, sun=sun_azi, x_ticks=False, filtered=False, negative=True)
                plot_responses_over_imu(
                    x_imu, y_iny, axis=ax[f"{session} int"], color=i_colour,
                    prediction=int_q50, error=(int_q25, int_q75),
                    c=r, sun=sun_azi, x_ticks=False, filtered=False)
                plot_responses_over_imu(
                    x_imu, y_inp, axis=ax[f"{session} int-pol"], color=c_colour,
                    prediction=inp_q50, error=(inp_q25, inp_q75),
                    c=r, sun=sun_azi, x_ticks=False, filtered=False)

        # Add text
        ax[f"{sessions[0]} pol"].set_title("p", fontsize=20, fontstyle='italic')
        ax[f"{sessions[0]} int"].set_title("I", fontsize=20, fontstyle='italic')
        ax[f"{sessions[0]} int-pol"].set_title("c", fontsize=20, fontstyle='italic')
        fig.tight_layout()
    else:
        print(f"Figure {figure} is not supported for this type of plot.")
        fig = None

    return fig


if __name__ == '__main__':
    csv_path = './csv/'
    csv_paths = glob.glob(csv_path+"*.csv")
    plt.rcParams['font.family'] = 'serif'

    for csv_path in csv_paths:
        outfile = 'png'
        out_extensions = ['png', 'jpeg', 'jpg', 'svg', 'pdf']

        if outfile is not None and outfile.lower() in out_extensions:
            outfile = os.path.join(out_base, f"{csv_path[-25:-4]}.{outfile.lower()}")

        fig_out = plot_responses(figure=4,
                                 figsize=(6, 3),
                                 dataset_path=csv_path,
                                 sessions=['session1']
                                 )

        if fig_out is not None and outfile is not None:
            fig_out.savefig(outfile, bbox_inches="tight")

        print('Done: ', csv_path)
