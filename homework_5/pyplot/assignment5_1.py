import matplotlib.pyplot as plt
import numpy as np

_, F_D, _, theta = np.genfromtxt("data/assignment5_1_data/bifurcation.dat", unpack=True, dtype=float)

fig, ax = plt.subplots()


ax.scatter(F_D, theta, s=.5, color="red")
ax.set(xlabel=r"$F_D$", ylabel=r"$\theta$")

plt.tight_layout()
plt.show()
