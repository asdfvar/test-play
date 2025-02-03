#!/usr/bin/bash

ffmpeg -safe 0 -f concat -i filelist -c copy $1
