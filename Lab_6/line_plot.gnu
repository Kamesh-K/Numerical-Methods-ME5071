set terminal postscript eps enhanced "Helvetica" 25

set key bottom right 
set key spacing 1
set key samplen 1

set ylabel 'Yj'
set xlabel 'Xj'

set size 2.0,1.0
set output 'Stepsize.eps'
plot    'Forward_1.txt' u 1:2 w lp lt 1 lc 1 pt 1 ps 3 t 'F1', \
	'Forward_2.txt' u 1:2 w lp lt 1 lc 1 pt 2 ps 4 t 'F2', \
	'Forward_4.txt' u 1:2 w lp lt 1 lc 1 pt 3 ps 5 t 'F4', 
	





