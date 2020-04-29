import numpy as np
import sounddevice as sd
from math import pi
from scipy.signal import butter, filtfilt, lfilter
from matplotlib import pyplot as plt

b, a = butter(5, 0.2)
delta = [0 for i in range(200)]
delta[0] = 1
delta[4] = 0.5
delta[9] = 0.2
delta[19] = 1

h = lfilter(b, a, delta)
plt.stem(delta)
plt.show()
plt.plot(h)
plt.show()