set terminal postscript eps enhanced "Helvetica" 25

set key bottom right 
set key spacing 1
set key samplen 1

set ylabel 'Y(i)'
set xlabel 'X(i)'

set size 1.0,1.0
set output 'Plot_50.eps
plot 'Solutions.txt' u 1:2 w lp lt 1 pt 5 ps 1 t 'Y(i) vs. X(i)'
