set multiplot layout 1,2

plot 'data/assignment3_3_data/assignment3_3.dat' using 2:4 with lines, 'data/assignment3_3_data/assignment3_3.dat' using 2:6 with lines, 'data/assignment3_3_data/assignment3_3.dat' using 2:8 with lines

plot 'data/assignment3_3_data/assignment3_3.dat' using 2:12 with lines, 'data/assignment3_3_data/assignment3_3.dat' using 2:14 with lines

unset multiplot
