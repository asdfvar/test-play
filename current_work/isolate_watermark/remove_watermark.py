#!/usr/bin/python3

# Remove the Soundstripe watermark

import numpy as np
from numpy import linalg as la
from matplotlib import pyplot as plt
import soundfile as sf
import os

#desired_music, _ = sf.read (os.path.join ('samples', 'watermarked_Adrian_Walther_TPS_Report_background_vocals_3_24.mp3'))
#desired_music, _ = sf.read (os.path.join ('samples', 'watermarked_Sounds_Like_Sander_Paper_Dreams_background_vocals_2_36.mp3'))
#desired_music, _ = sf.read (os.path.join ('samples', 'watermarked_Rest_Settle_Autumn_05_instrumental_2_39.mp3'))

sampling_rate = 44100

#input_file = 'samples/watermarked_Alsever_Lake_What_Can_I_Say_background_vocals_2_55.mp3'
#output_file = 'Alsever_Lake_What_Can_I_Say_background_vocals_2_55.mp3'

#input_file = 'samples/watermarked_Alsever_Lake_Time_Gone_By_instrumental_3_23.mp3'
#output_file = 'Alsever_Lake_Time_Gone_By_instrumental_3_23.mp3'

#input_file = 'samples/watermarked_Alsever_Lake_Through_Space_And_Time_instrumental_3_33.mp3'
#output_file = 'Alsever_Lake_Through_Space_And_Time_instrumental_3_33.mp3'

input_file = 'samples/watermarked_Alsever_Lake_Ride_The_Pacific_background_vocals_3_18.mp3'
output_file = 'Alsever_Lake_Ride_The_Pacific_background_vocals_3_18.mp3'

desired_music, _ = sf.read (input_file)

watermark = np.fromfile ("watermark")
watermark = np.reshape (watermark, (int (len (watermark) / 2), 2))
M = min (len (desired_music), len (watermark))

desired_music[0:M, :] -= watermark[0:M, :]

sf.write (output_file, desired_music, sampling_rate)
