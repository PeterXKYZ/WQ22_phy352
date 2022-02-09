string_data = "data/assignment4_2_data/gaussian_.5.dat"
set terminal png size 1200,1000
set output "graphics/string_displacement.png"


set xlabel "Time (s)"
set ylabel "Amplitude"
set yrange [-.7:.7]
set title "Displacement at x = .05"

plot string_data using 2:4 with lines lt rgb "black" 
