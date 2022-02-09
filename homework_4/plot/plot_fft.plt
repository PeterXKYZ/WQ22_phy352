fft_data = "data/assignment4_2_data/fft_test.dat"

set xrange [0:3000]
plot fft_data using 1:(($2*$2)+($3*$3)) with lines
