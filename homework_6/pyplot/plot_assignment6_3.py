import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, T, _, C20 = np.genfromtxt("../data/assignment6_3_data/C-T_20.dat", unpack=True, dtype=float)
_, _, _, C50 = np.genfromtxt("../data/assignment6_3_data/C-T_50.dat", unpack=True, dtype=float)
_, _, _, C100 = np.genfromtxt("../data/assignment6_3_data/C-T_100.dat", unpack=True, dtype=float)


fig, ax = plt.subplots()

ax.plot(T, C20, color='C1', label=r"$N=20$", marker='o', markersize=3, zorder=3)
ax.plot(T, C50, color='C2', label=r"$N=50$", marker='o', markersize=3, zorder=2)
ax.plot(T, C100, color='C3', label=r"$N=100$", marker='o', markersize=3, zorder=1)

ax.set(xlabel=r"Temperature $T$", ylabel=r"Specific Heat $C$")
ax.legend()

plt.show()
