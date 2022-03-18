import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, T, _, EN = np.genfromtxt("../data/assignment6_2_data/E-T_combined.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.scatter(T, EN, s=2, color='C1')
ax.set(xlabel=r"Temperature $T$", ylabel=r"Energy Per Spin $\langle E \rangle/N$")

plt.tight_layout()
fig.savefig("../graphics/E-T_plot.png")
