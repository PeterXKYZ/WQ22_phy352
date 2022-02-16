#!/usr/bin/bash

rm graphics/gif_img/*

printf "generating images...\n"
for i in {2..801}
    do 
        sed "s/QED/$i/g" plot/anim_beats_template.plt > plot/temp.plt
        gnuplot plot/temp.plt
done

rm plot/temp.plt
if [ -f graphics/beats.gif ]
then
	rm graphics/beats.gif
fi

printf "animating...\n"
convert -delay 5 `printf "$(ls graphics/gif_img/anim_beats_*.png)\n" | sort -t '_' -k4 -n | head -n 305` -loop 0 graphics/beats.gif
