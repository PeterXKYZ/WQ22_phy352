import matplotlib.pyplot as plt
import numpy as np

_, F_D, _, theta = np.genfromtxt("../data/assignment5_1_data/bifurcation.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()

ax.scatter(F_D, theta, s=.5, color="red")
ax.set(xlabel=r"$F_D$", ylabel=r"$\theta$")
ax.set_title("Bifurcation Diagram")

fig.tight_layout()
fig.savefig("../graphics/bifurcation.png")

# --------------------------------------------
fig2, ax2 = plt.subplots()

ax2.scatter(F_D, theta, s=.5, color="red")
ax2.set(xlabel=r"$F_D$", ylabel=r"$\theta$", xlim=(1.4575, 1.4892), ylim=(1.91, 3.11),
        title="Bifurcation Diagram Zoomed")

fig2.tight_layout()
fig.savefig("../graphics/bifur_zoomed.png")
