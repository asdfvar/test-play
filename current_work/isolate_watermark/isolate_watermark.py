#!/usr/bin/python3

# Isolate the Soundstripe watermark

import numpy as np
from matplotlib import pyplot as plt
import soundfile as sf
import os

samples = os.listdir ('samples')

sampling_rate = 44100
N = sampling_rate * 60 * 20
sample_length = sampling_rate * 1
averaged_signal = np.zeros ((N, 2))
weights = np.zeros ((N, 2))

print ("processing %d samples" % len (samples))
for ind, sample in enumerate (samples):
   y, sr = sf.read (os.path.join ('samples', sample))
   M = min (N, len (y))
   averaged_signal[0:M, :] += y[0:M, :]
   weights[0:M, :] += 1.0
   if ind % int (0.1 * len (samples)) == 0: print (str (ind / len (samples)) + "%f complete")

weights[weights < 1.0] = 1.0
averaged_signal /= weights

# Poor-man noise removal
# Zero the areas that obviously don't have signal
mask = la.norm (watermark, axis = 1) > 0.1
for ind in range (25000):
   if ind % 2500 == 0: print (str (ind / 25000) + " right dialation completion")
   mask[1:]   |= mask[0:-1] # dialates to the right
for ind in range (11000):
   if ind % 1100 == 0: print (str (ind / 11000) + " left dialation completion")
   mask[0:-1] |= mask[1:]   # dialates to the left
mask = ~mask
watermark[mask] = 0.0

averaged_signal.tofile ("watermark")
