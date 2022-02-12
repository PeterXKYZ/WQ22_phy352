import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as anime


data = np.genfromtxt("data/midterm_2_data/test.dat", dtype=float)
print(data.shape)
x = data[:, 0]
tlen = np.size(data, axis=1)
print(tlen)

fig, ax = plt.subplots()
line, = ax.plot([], [], color='b', zorder=6)


def init():
    ax.set(xlim=(0, 16), ylim=(-1.2, 1.2), xlabel="Position", ylabel="Amplitude")
    return line


def anim(i):
    line.set_data(x, data[:, i])

    return line


fanim = anime.FuncAnimation(fig, anim, frames=range(tlen), init_func=init, blit=False, interval=10)
mywriter = anime.FFMpegWriter(fps=100)
fanim.save("wave.mp4", writer=mywriter)
# plt.show()
