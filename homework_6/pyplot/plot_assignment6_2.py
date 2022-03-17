import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

_, T, _, EN = np.genfromtxt("../data/E-T.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.scatter(T, EN, s=2, color='C1')
ax.set(xlabel=r"Temperature $T$", ylabel=r"Energy Per Spin $E/N$")

plt.show()
