standing_1 = "data/assignment4_1_data/standing_wave_2.dat"
standing_2 = "data/assignment4_1_data/standing_wave_5.dat"

set terminal png size 1500,1000
set output "graphics/standing_waves.png"

set multiplot layout 1,2

set xlabel "Position"
set ylabel "Amplitude"
plot standing_1 using 1:12 with lines title "m = 2" lt rgb "blue"

plot standing_2 using 1:12 with lines title "m = 5" lt rgb "violet"

unset multiplot
