import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, i1, _, corr1 = np.genfromtxt("../data/assignment6_4_data/corr_.5_.dat", unpack=True, dtype=float)
_, i2, _, corr2 = np.genfromtxt("../data/assignment6_4_data/corr_.95_.dat", unpack=True, dtype=float)
_, i3, _, corr3 = np.genfromtxt("../data/assignment6_4_data/corr_2_.dat", unpack=True, dtype=float)

# ---------exponential fitting--------------


def exp_func(x, a, l):
    y = a * np.exp(-x / l)
    return y


alpha1 = curve_fit(exp_func, i1, corr1)[0]
alpha2 = curve_fit(exp_func, i2, corr2)[0]
alpha3 = curve_fit(exp_func, i3, corr3)[0]

# --------------------------------------------

fig, ax = plt.subplots()

ax.plot(i1, corr1, marker='o', markersize=2, label=r"$.5 \times T_c$" + "\n" + rf"$\xi={alpha1[1]:.4f}$")
ax.plot(i2, corr2, marker='o', markersize=2, label=r"$.95 \times T_c$" + "\n" + rf"$\xi={alpha2[1]:.4f}$")
ax.plot(i3, corr3, marker='o', markersize=2, label=r"$2 \times T_c$" + "\n" + rf"$\xi={alpha3[1]:.4f}$")
ax.set(xlabel=r"Distance $i$", ylabel=r"Correlation $f(i) - \langle s \rangle^2$")
ax.legend()

plt.tight_layout()
fig.savefig("../graphics/corr_func.png")


