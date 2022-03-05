import matplotlib.pyplot as plt
import numpy as np

energy, N, _ = np.genfromtxt("../data/assignment5_2_data/higgs.dat", dtype=float, unpack=True)

fig, ax = plt.subplots()

ax.scatter(energy, N, marker="+", color="purple", label="Higgs Data", zorder=1)

# parameters
As = 133.27180
mu = 126.17821
sigma = 1.63200
Ab = 1686.91947
tau = -20.08968

# plotting
x = np.linspace(energy[0], energy[-1], 100)
y1 = Ab * np.exp((x - 100) / tau)
y2 = As * np.exp(-.5*(x - mu)**2 / sigma**2)
ax.plot(x, y1 + y2, color="C2", zorder=0, label=fr"$A_b = {Ab:.3f}$" + "\n" + fr"$\tau = {tau:.3f}$" + "\n"
        fr"As = {As:.3f}" + "\n" + fr"$\mu = {mu:.3f}$" + "\n" + fr"$\sigma = {sigma:.3f}$")

ax.set(xlabel="Energy (GeV)", ylabel="N", title="Background + Signal")
ax.legend()

plt.tight_layout()
plt.savefig("../graphics/bg+sig.png")
