import matplotlib.pyplot as plt
import numpy as np

_, time, _, y1, _, y2 = np.genfromtxt("data/midterm_1_data/test.dat", dtype=float, unpack=True)

fig, ax = plt.subplots()

ax.plot(time, y1)
ax.plot(time, y2)

plt.show()