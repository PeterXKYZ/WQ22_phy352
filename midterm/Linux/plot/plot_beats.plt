data_k12="data/midterm_2_data/fft_add_k12.dat"
set terminal png size 1400,1000
set output "graphics/fft_beats.png"


# 1  2    3  4    5  6    7   8    9   10
# t: tval a: aval f: fval re: rval im: ival

set multiplot layout 2,1

set yrange [-2.2:2.2]
set xrange [0:.01]
set xlabel "time (s)"
set ylabel "amplitude"
plot data_k12 using 2:4 with lines title "f=1200 + 1320 Hz" lt rgb "dark-violet"

set yrange [0:400]
set xrange [1000:2000]
set xlabel "frequency (Hz)"
set arrow from 1200, graph 0 to 1200, graph 1 nohead 
set arrow from 1300, graph 0 to 1300, graph 1 nohead 
plot data_k12 using 6:(abs($8)) with lines title "Re(f)" lt rgb "sea-green", \
    data_k12 using 6:(abs($10)) with lines title "Im(f)" lt rgb "dark-goldenrod"

unset multiplot
