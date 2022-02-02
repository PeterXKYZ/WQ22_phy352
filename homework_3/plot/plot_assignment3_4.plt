omega_d_dat = "data/assignment3_4_data/assignment3_4_Omega.dat"
q_dat = "data/assignment3_4_data/assignment3_4_q.dat"
set terminal png size 1500,1000
set output "png/assignment3_4.png"

set multiplot layout 2,1

set xrange[0:7]
set title "Omega = 3.132, F_d = .2, q = 1"
set xlabel "Omega_d"
set ylabel "steady-state amplitude"
plot omega_d_dat using 1:2 lt rgb "blue" title "numerical solution", .2 / sqrt((9.81 - x**2)**2 + x**2) lt rgb "red" title "analytical solution"

set xrange[.05:8.5]
set title "Omega = 3.132, F_d = .2, Omega_d = 3.132"
set logscale y
set xlabel "q"
set ylabel "steady-state amplitude
plot q_dat using 1:2 lt rgb "blue" title "numerical solution", .2 / (x*3.132) lt rgb "red" title "analytical solution"

unset multiplot
