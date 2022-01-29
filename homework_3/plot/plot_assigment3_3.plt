set multiplot layout 1,3

set xlabel 'Time (s)'
set ylabel 'Angular Position (rad)'
plot 'data/assignment3_3_data/assignment3_3_angle.dat' using 2:4 with lines title "euler method", 'data/assignment3_3_data/assignment3_3_angle.dat' using 2:6 with lines title "rkO2 method", 'data/assignment3_3_data/assignment3_3_angle.dat' using 2:8 with lines title "rkO4 method", 'data/assignment3_3_data/assignment3_3_angle.dat' using 2:10 with lines title "exact"

set xlabel 'Time (s)'
set ylabel 'Total Energy'
plot 'data/assignment3_3_data/assignment3_3_energy.dat' using 2:4 with lines title "euler", 'data/assignment3_3_data/assignment3_3_energy.dat' using 2:6 with lines title "rkO2", 'data/assignment3_3_data/assignment3_3_energy.dat' using 2:8 with lines title "rkO4"

set xlabel 'Time (s)'
set ylabel 'Relative Error'
plot 'data/assignment3_3_data/assignment3_3_error.dat' using 2:4 with lines title "euler", 'data/assignment3_3_data/assignment3_3_error.dat' using 2:6 with lines title "rkO2", 'data/assignment3_3_data/assignment3_3_error.dat' using 2:8 with lines title "rkO4"

unset multiplot
