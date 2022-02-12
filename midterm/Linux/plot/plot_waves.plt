data_k1="data/midterm_2_data/fft_k1.dat"
data_k2="data/midterm_2_data/fft_k2.dat"

# 1  2    3  4    5  6    7   8    9   10
# t: tval a: aval f: fval re: rval im: ival

set multiplot layout 2,1

set yrange [-1:1]
set xrange [0:.007]
set xlabel "time (s)"
set ylabel "amplitude"
plot data_k1 using 2:4 with lines title "f=1200 Hz" lt rgb "dark-violet", \
    data_k2 using 2:4 with lines title "f=1320 Hz" lt rgb "sea-green"

set yrange [0:400]
set xrange [1000:2000]
set xlabel "frequency (Hz)"
set arrow from 1200, graph 0 to 1200, graph 1 nohead 
set arrow from 1300, graph 0 to 1300, graph 1 nohead 
plot data_k1 using 6:(abs($8)) with lines title "Re(f)=1200 Hz" lt rgb "dark-violet", \
    data_k1 using 6:(abs($10)) with lines title "Im(f)=1200 Hz" lt rgb "dark-goldenrod", \
    data_k2 using 6:(abs($8)) with lines title "Re(f)=1320 Hz" lt rgb "sea-green", \
    data_k2 using 6:(abs($10)) with lines title "Re(f)=1320 Hz" lt rgb "medium-blue"

unset multiplot
