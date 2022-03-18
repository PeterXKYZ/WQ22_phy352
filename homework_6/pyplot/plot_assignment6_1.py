import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, T, _, M = np.genfromtxt("../data/M-T.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.scatter(T, M, s=2)
ax.set(xlabel=r"Temperature $T$", ylabel=r"Magnetization $\langle M \rangle$", title="Magnetization vs Temperature")

plt.tight_layout()
fig.savefig("../graphics/M-T_plot.png")
