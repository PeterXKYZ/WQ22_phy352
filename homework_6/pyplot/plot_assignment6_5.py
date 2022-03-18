import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

mpl.rcParams['font.family'] = 'serif'
mpl.rcParams['mathtext.fontset'] = 'cm'

lattice1 = np.genfromtxt("../data/assignment6_5_data/snap_1000.dat", dtype=float)
lattice2 = np.genfromtxt("../data/assignment6_5_data/snap_5000.dat", dtype=float)
lattice3 = np.genfromtxt("../data/assignment6_5_data/snap_10000.dat", dtype=float)
lattice4 = np.genfromtxt("../data/assignment6_5_data/snap_50000.dat", dtype=float)

fig1, ax1 = plt.subplots()
fig2, ax2 = plt.subplots()
fig3, ax3 = plt.subplots()
fig4, ax4 = plt.subplots()

lattices = [lattice1, lattice2, lattice3, lattice4]
figs = [fig1, fig2, fig3, fig4]
axs = [ax1, ax2, ax3, ax4]
num = [1000, 5000, 10000, 50000]

for i in range(0, 4):
    img = axs[i].imshow(lattices[i])
    figs[i].colorbar(img, ax=axs[i])
    axs[i].set(title=fr"Lattice after {num[i]} sweeps at $T = .95 \times T_c$")
    figs[i].tight_layout()
    figs[i].savefig(f"../graphics/lattice_snap_{num[i]}.png")
