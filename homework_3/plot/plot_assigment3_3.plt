angle_data = "data/assignment3_3_data/assignment3_3_angle.dat"
energy_data = "data/assignment3_3_data/assignment3_3_energy.dat"
error_data = "data/assignment3_3_data/assignment3_3_error.dat"

set multiplot layout 2,3 columnsfirst

set xlabel 'Time (s)'
set ylabel 'Angular Position (rad)'
plot angle_data using 2:4 with lines title "euler method", angle_data using 2:10 with lines title "exact" linetype 3

set xlabel 'Time (s)'
set ylabel 'Angular Position (rad)'
plot angle_data using 2:6 with lines title "rkO2 method", angle_data using 2:8 with lines title "rkO4 method" lt rgb "black"

set xlabel 'Time (s)'
set ylabel 'Total Energy'
plot energy_data using 2:4 with lines title "euler"

set xlabel 'Time (s)'
set ylabel 'Total Energy'
plot energy_data using 2:6 with lines title "rkO2", energy_data using 2:8 with lines title "rkO4"

set xlabel 'Time (s)'
set ylabel 'Relative Error'
plot error_data using 2:4 with lines title "euler"

set xlabel 'Time (s)'
set ylabel 'Relative Error'
plot error_data using 2:6 with lines title "rkO2", error_data using 2:8 with lines title "rkO4"

unset multiplot
