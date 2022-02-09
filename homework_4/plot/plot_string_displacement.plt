string_data = "data/assignment4_2_data/gaussian_.5.dat"

set xlabel "Time (s)"
set ylabel "Amplitude"
set yrange [-.7:.7]

plot string_data using 2:4 with lines 
