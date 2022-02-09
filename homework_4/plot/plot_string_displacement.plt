string_data = "data/assignment4_2_data/string_data.dat"

set xlabel "Time (s)"
set ylabel "Amplitude"
set yrange [-.7:.7]

plot string_data using 1:2 with lines
