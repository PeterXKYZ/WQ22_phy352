#!/usr/bin/bash

printf "generating images...\n"
for i in {2..30}
    do 
        sed "s/QED/$i/g" plot/anim_beats_template.plt > plot/temp.plt
        gnuplot plot/temp.plt
done

rm plot/temp.plt

printf "animating...\n"
convert -delay 5 $(ls graphics/gif_img/anim_beats_*.png | sort -t '_' -k4 -n) -loop 0 graphics/beat.gif
