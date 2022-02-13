#!/usr/bin/bash

# ffmpeg -framerate 200 -i graphics/gif_img/anim_beats_%d.png -vsync 0 graphics/beats2.gif
convert -delay 5 `printf "$(ls graphics/gif_img/anim_beats_*.png)\n" | sort -t '_' -k4 -n | head -n 305` -loop 0 graphics/beat.gif