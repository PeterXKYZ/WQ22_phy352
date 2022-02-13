#!/usr/bin/bash

fprintf "generating images..."
for i in {2..3}
    do 
        sed 's/QED/$i/g' plot/anim_beats_template.plt > plot/temp.plt
        gnuplot plot/temp.plt
done

rm plot/temp.plt

fprintf "animating..."
# convert -delay 5 $(ls graphics/gif_img/anim_beats_*.png | sort -t '_' -k3 -n) -loop 0 img/beat.gif