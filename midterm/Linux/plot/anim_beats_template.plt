prop_k1="data/midterm_2_data/wave_prop_k1.dat"
prop_k2="data/midterm_2_data/wave_prop_k2.dat"
add_k12="data/midterm_2_data/wave_add_k12.dat"
prop_k12="data/midterm_2_data/wave_prop_k12.dat"

set terminal png size 1400,1000
set output "graphics/gif_img/anim_beats_QED.png"

set multiplot layout 2,1

set xrange [0:4]
set yrange[-1:1]
set xlabel "position"
set ylabel "amplitude"
plot prop_k1 using 1:QED with lines title "y1, f=1200 Hz" lt rgb "sea-green", \
    prop_k2 using 1:QED with lines title "y2, f=1320 Hz" lt rgb "dark-violet"

set xrange [0:4]
set yrange [-2.2:2.2]
plot prop_k12 using 1:QED with lines title "y1 + y2" lt rgb "dark-goldenrod", \
    add_k12 using 1:QED title "y3" lt rgb "medium-blue"

unset multiplot
