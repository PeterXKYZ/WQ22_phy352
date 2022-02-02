ang_35 = 'data/assignment3_2_data/assignment3_2_35.dat'
ang_45 = 'data/assignment3_2_data/assignment3_2_45.dat'

set terminal png size 1000,1000
set output "png/assignment3_2.png"

set xlabel "x position (m)"
set ylabel "y position (m)"
plot ang_35 using 1:2 with lines title "angle = 35 degrees", ang_45 using 1:2 with lines title "angle = 45 degrees" lt rgb "blue"
