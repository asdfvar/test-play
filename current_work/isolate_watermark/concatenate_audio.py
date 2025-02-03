#!/usr/bin/python3

import numpy as np
from numpy import linalg as la
from matplotlib import pyplot as plt
import soundfile as sf
import os

input_files = ('Alsever_Lake_What_Can_I_Say_background_vocals_2_55.mp3',
               'Alsever_Lake_Ride_The_Pacific_background_vocals_3_18.mp3',
               'Alsever_Lake_Through_Space_And_Time_instrumental_3_33.mp3',
               'Alsever_Lake_Time_Gone_By_instrumental_3_23.mp3')

output_file = 'playlist.mp3'

sampling_rate = 44100

desired_music = np.zeros ((1, 2))

for file in input_files:
   audio, _ = sf.read (file)
   desired_music = np.concatenate ((desired_music, audio))

sf.write (output_file, desired_music, sampling_rate)
