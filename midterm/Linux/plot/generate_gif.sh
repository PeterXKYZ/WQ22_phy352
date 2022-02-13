#!/usr/bin/bash

printf "generating images...\n"
for i in {2..801}
    do 
        sed "s/QED/$i/g" plot/anim_beats_template.plt > plot/temp.plt
        gnuplot plot/temp.plt
done

rm plot/temp.plt
rm graphics/beat.gif

printf "animating...\n"
convert -delay 5 `printf "$(ls graphics/gif_img/anim_beats_*.png)\n" | sort -t '_' -k4 -n | head -n 305` -loop 0 graphics/beat.gif
