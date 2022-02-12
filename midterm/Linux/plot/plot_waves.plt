data_k1="data/midterm_2_data/fft_4.dat"
data_k2="data/midterm_2_data/fft_4.4.dat"

# 1  2    3  4    5  6    7   8    9   10
# t: tval a: aval f: fval re: rval im: ival

set multiplot layout 2,1

set yrange [-1:1]
set xrange [0:.03]
plot data_k1 using 2:4 with lines title "omega=1200 rad/s" lt rgb "dark-violet", \
    data_k2 using 2:4 with lines title "omega=1320 rad/s" lt rgb "sea-green"

set yrange [0:350]
set xrange [1000:2000]
plot data_k1 using 6:8 with lines title "Re(omega)=1200 rad/s" lt rgb "dark-violet", \
    data_k1 using 6:10 with lines title "Im(omega)=1200 rad/s" lt rgb "orange", \
    data_k2 using 6:8 with lines title "Re(omega)=1320 rad/s" lt rgb "sea-green", \
    data_k2 using 6:10 with lines title "Re(omega)=1320 rad/s" lt rgb "medium-blue"

unset multiplot
