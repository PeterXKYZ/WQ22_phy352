import matplotlib.pyplot as plt
import numpy as np

energy, N, _ = np.genfromtxt("../data/assignment5_2_data/higgs.dat", dtype=float, unpack=True)

fig, ax = plt.subplots()

ax.scatter(energy, N, marker="+", color="purple", label="Higgs Data", zorder=1)

Ab = 1691.89866
tau = -20.36964

x = np.linspace(energy[0], energy[-1], 100)
y = Ab * np.exp((x - 100) / tau)
ax.plot(x, y, color="C2", zorder=0, label=fr"$A_b = {Ab:.3f}$" + "\n" + fr"$\tau = {tau:.3f}$")

ax.set(xlabel="Energy (GeV)", ylabel="N", title="Background Fit Only")
ax.legend()

plt.tight_layout()
plt.savefig("../graphics/bg_only.png")
