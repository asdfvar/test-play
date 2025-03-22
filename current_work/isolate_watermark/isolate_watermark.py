#!/usr/bin/python3

# Isolate the Soundstripe watermark

import numpy as np
from matplotlib import pyplot as plt
import soundfile as sf
import os
import sys

samples_dir = sys.argv[1]

attributes = {'sample rate':44100}

def average_samples (samples_dir, attributes):
   samples = os.listdir (samples_dir)
   N = attributes['sample rate'] * 60 * 20

   averaged_signal = np.zeros ((N, 2))
   weights = np.zeros ((N, 2))
   print ("processing %d samples" % len (samples))
   max_length = 0
   for ind, sample in enumerate (samples):
      y, sr = sf.read (os.path.join (samples_dir, sample))
      M = min (N, len (y))
      if M > max_length: max_length = M
      averaged_signal[0:M, :] += y[0:M, :]
      weights[0:M, :] += 1.0
      if ind % int (0.1 * len (samples)) == 0: print ("%.2f/1.0 complete" % (float (ind) / float (len (samples))))
      if ind > 10: break
   averaged_signal = averaged_signal[0:max_length,:]
   weights = weights[0:max_length,:]
   averaged_signal /= weights
   return averaged_signal

def compute_power (signal, interval, attributes):
   width = int (interval * attributes['sample rate'])
   power = np.zeros ((np.shape (signal)[0] - width, 2))
   signal_sq = signal**2
   for ind in range (width):
      print (str (ind / width))
      power += signal_sq[ind:ind-width,:]
   return power

averaged_signal = average_samples (samples_dir, attributes)

plt.figure ()
plt.plot (averaged_signal)

power = compute_power (averaged_signal, 0.05, attributes)

plt.figure ()
plt.plot (power)

plt.show ()

'''
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
'''
