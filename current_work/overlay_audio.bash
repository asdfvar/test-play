#!/usr/bin/bash

ffmpeg -i chumash.MP4 -i playlist.mp3 -c copy -map 0:v:0 -map 1:a:0 chumash_with_playlist.mp4
