import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, T, _, C = np.genfromtxt("../data/C-T.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.scatter(T, C, s=2, color='C1')
ax.set(xlabel=r"Temperature $T$", ylabel=r"Specific Heat $C$")

plt.show()
