import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

lattice = np.genfromtxt("../data/assignment6_5_data/test.dat", dtype=float)

fig, ax = plt.subplots()

img = ax.imshow(lattice)
plt.colorbar(img)

plt.show()
