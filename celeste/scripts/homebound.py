from cProfile import label
from unicodedata import decimal

import numpy as np
from scipy.optimize import least_squares
import pandas as pd
import os


def residuals(params, x, y):
    xc, yc, r = params
    return (x - xc)**2 + (y - yc)**2 - r**2


df = pd.read_csv('homebound.csv')


x = np.array(df.x)
y = np.array(df.y)

x_center_guess = np.mean(x)
y_center_guess = np.mean(y)

# r_guess = np.std(x)
# initial_guess = [x_center_guess, y_center_guess, r_guess]
# result = least_squares(residuals, initial_guess, args=(x, y))
# x_center, y_center, r = result.x

# print(f"Circle Center: ({x_center}, {y_center})")
# print(f"Radius: {r}")
# print(f'Distance: {np.sqrt(x_center**2 + y_center**2)}')

print(df)
# df.index = np.arange(1, len(df)+1)
df.index = ['U-turn '+str(i) for i in range(1,len(df)+1)]
df.loc['fitted center'] = [x_center_guess,y_center_guess]
df['distance'] = np.sqrt(df['x']**2 + df['y']**2)
print(df.T)
df = df.T
df.to_latex('homebound.tex',
            caption='Fitted Center according to critical vectors',
            float_format="{:0.2f}".format,
            label="tab:vectors",
            )

