import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, i1, _, corr1 = np.genfromtxt("../data/assignment6_4_data/corr_.5_.dat", unpack=True, dtype=float)
_, i2, _, corr2 = np.genfromtxt("../data/assignment6_4_data/corr_.95_.dat", unpack=True, dtype=float)
_, i3, _, corr3 = np.genfromtxt("../data/assignment6_4_data/corr_2_.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.plot(i1, corr1, marker='o', markersize=2, label=r"$.5 \times T_c$")
ax.plot(i2, corr2, marker='o', markersize=2, label=r"$.95 \times T_c$")
ax.plot(i3, corr3, marker='o', markersize=2, label=r"$2 \times T_c$")
ax.set(xlabel=r"Distance $i$", ylabel=r"Correlation")
ax.legend()

# ----------------------------------


def exp_func(x, a, l):
    y = a * np.exp(-x / l)
    return y


alpha = curve_fit(exp_func, i3, corr3)[0]
print(alpha)
ax.plot(i3, exp_func(i3, alpha[0], alpha[1]), color='k', linestyle='--')

plt.show()


