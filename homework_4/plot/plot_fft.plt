fft_data_1 = "data/assignment4_2_data/gaussian_.5.dat"
fft_data_2 = "data/assignment4_2_data/gaussian_.45.dat"

set terminal png size 1600,1000
set output "graphics/power_spectra.png"

set multiplot layout 1,2

set xrange [0:3000]
set xlabel "Frequency (Hz)"
set ylabel "Amplitude"
set title "Power Spectra"
plot fft_data_1 using 6:(($8*$8)+($10*$10)) with lines title "mu = .5" lt rgb "black"


plot fft_data_1 using 6:(($8*$8)+($10*$10)) with lines title "mu = .5", fft_data_2 using 6:(($8*$8)+($10*$10)) with lines title "mu = .45" lt rgb "blue"

unset multiplot
