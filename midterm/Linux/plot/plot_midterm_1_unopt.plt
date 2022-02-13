decay = "data/midterm_1_data/unopt/combined.dat"
set terminal png size 2400,800
set output "graphics/decay_unopt.png"

set multiplot layout 1,3

set logscale xy
set xrange [1E1:1E6]
set yrange [5E-15:5E-1]
set grid
set pointsize 1

set title "Precision vs. Granularity (Unopt)"
set xlabel "t steps"
set ylabel "|relative error|" offset 5,0
plot decay using 2:4 title "euler" lt rgb "medium-blue", \
	decay using 8:10 title "rkO2" lt rgb "sea-green", \
	decay using 14:16 title "rkO4" lt rgb "dark-violet"

set title "Precision vs. Cost (Unopt)"
set xrange [1E5:1E9]
set yrange [5E-15:5E-1]
set xlabel "# of instructions"
set ylabel "|relative error|"
plot decay using 6:4 title "euler" lt rgb "medium-blue", \
	decay using 12:10 title "rkO2" lt rgb "sea-green", \
	decay using 18:16 title "rkO4" lt rgb "dark-violet"

set title "Cost vs. Granularity (Unopt)"
set xrange [1E1:1E6]
set yrange [1E5:1E9]
set xlabel "t steps"
set ylabel "# of instructions"
plot decay using 2:6 title "euler" lt rgb "medium-blue", \
	decay using 8:12 title "rkO2" lt rgb "sea-green", \
	decay using 14:18 title "rkO4" lt rgb "dark-violet"

unset multiplot
