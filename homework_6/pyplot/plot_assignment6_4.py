import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, i1, _, corr1 = np.genfromtxt("../data/assignment6_4_data/corr_.5_.dat", unpack=True, dtype=float)
_, i2, _, corr2 = np.genfromtxt("../data/assignment6_4_data/corr_.95_.dat", unpack=True, dtype=float)
_, i3, _, corr3 = np.genfromtxt("../data/assignment6_4_data/corr_2_.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.plot(i1, corr1, marker='o', markersize=2)
ax.plot(i2, corr2, marker='o', markersize=2)
ax.plot(i3, corr3, marker='o', markersize=2)
ax.set(xlabel=r"Distance $i$", ylabel=r"Correlation")

plt.show()
