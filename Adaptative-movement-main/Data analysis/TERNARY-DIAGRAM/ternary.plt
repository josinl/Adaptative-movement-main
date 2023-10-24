#!/usr/bin/gnuplot

reset

set term tikz
#set term png size 670,500
	outname = sprintf("s14.tex")
	set out outname
set size 1.4, 1.0
set bmargin 1
set lmargin 1
set rmargin 1
set tmargin 1
set size ratio 0.866
set yrange [0:0.866]
set xrange [0:1]
set noborder
set noxtics
set noytics
set label '$\rho_2$' at -0.03, -0.02 center tc 'yellow'
set label '$\rho_3$' at 1.03, -0.02 center tc 'red'
set label '$\rho_1$' at 0.5, 0.896 center tc 'blue'

set style line 1 lc rgb 'red' lt 0 lw 1.5 pt 6 #  green      (species 1)
set style line 2 lc rgb 'blue' lt 0 lw 1.5 pt 6 #  red	     (species 2)
set style line 3 lc rgb 'yellow' lt 0 lw 1.5 pt 6 #  orange     (species 3)
set style line 4 lc rgb 'orange' lt 0 lw 1.5 pt 6 #  dark blue  (species 4)
set style line 5 lc rgb 'grey' lt 0 lw 1.5 pt 6 #  cyan	     (species 5)
set style line 6 lc rgb '#03c04a' lt 3 lw 1.5 pt 2 #  grey	     (empty space)
set style line 8 lc rgb '#013220' lt 1 lw 3 pt 2 #  kappa-2-radius-2
set style line 9 lc rgb '#00FF00' lt 1 lw 3 pt 2 #  kappa-4-radius-2
set style line 10 lc rgb 'pink' lt 2 lw 3 pt 2 # kappa-2-radius-4
set style line 11 lc rgb 'gray' lt 1 lw 3 pt 2 # standard
set style line 12 lc rgb 'brown' lt 2 lw 3 pt 2 # kappa-4-radius-4

# x
set arrow 1 from 0,0 to 1, 0.0 nohead linestyle 1
set arrow 2 from 0.1,0 to 0.55, 0.779 nohead linestyle 1
set arrow 3 from 0.2,0 to 0.60, 0.693 nohead linestyle 1
set arrow 4 from 0.3,0 to 0.65, 0.606 nohead linestyle 1
set arrow 5 from 0.4,0 to 0.70, 0.520 nohead linestyle 1
set arrow 6 from 0.5,0 to 0.75, 0.433 nohead linestyle 1
set arrow 7 from 0.6,0 to 0.80, 0.346 nohead linestyle 1
set arrow 8 from 0.7,0 to 0.85, 0.260 nohead linestyle 1
set arrow 9 from 0.8,0 to 0.90, 0.173 nohead linestyle 1
set arrow 10 from 0.9,0 to 0.95, 0.0866 nohead linestyle 1

# Numeros x

set label '0.1' at 0.1, -0.03 center tc rgb "red"
set label '0.2' at 0.2, -0.03 center tc rgb "red"
set label '0.3' at 0.3, -0.03 center tc rgb "red"
set label '0.4' at 0.4, -0.03 center tc rgb "red"
set label '0.5' at 0.5, -0.03 center tc rgb "red"
set label '0.6' at 0.6, -0.03 center tc rgb "red"
set label '0.7' at 0.7, -0.03 center tc rgb "red"
set label '0.8' at 0.8, -0.03 center tc rgb "red"
set label '0.9' at 0.9, -0.03 center tc rgb "red"

# z
set arrow 11 from 1, 0 to 0.50, 0.866 nohead linestyle 2
set arrow 12 from 0.95, 0.0866 to 0.05, 0.0866 nohead linestyle 2
set arrow 13 from 0.90, 0.173 to 0.10, 0.173 nohead linestyle 2
set arrow 14 from 0.85, 0.260 to 0.15, 0.260 nohead linestyle 2
set arrow 15 from 0.80, 0.346 to 0.20, 0.346 nohead linestyle 2
set arrow 16 from 0.75, 0.433 to 0.25, 0.433 nohead linestyle 2
set arrow 17 from 0.70, 0.520 to 0.30, 0.520 nohead linestyle 2
set arrow 18 from 0.65, 0.606 to 0.35, 0.606 nohead linestyle 2
set arrow 19 from 0.60, 0.693 to 0.40, 0.693 nohead linestyle 2
set arrow 20 from 0.55, 0.779 to 0.45, 0.779 nohead linestyle 2

# Numeros z

set label '0.1' at 0.99, 0.0866 center tc rgb "blue"
set label '0.2' at 0.94, 0.173 center tc rgb "blue"
set label '0.3' at 0.89, 0.260 center tc rgb "blue"
set label '0.4' at 0.84, 0.346 center tc rgb "blue"
set label '0.5' at 0.79, 0.433 center tc rgb "blue"
set label '0.6' at 0.74, 0.520 center tc rgb "blue"
set label '0.7' at 0.69, 0.606 center tc rgb "blue"
set label '0.8' at 0.64, 0.693 center tc rgb "blue"
set label '0.9' at 0.59, 0.779 center tc rgb "blue"

# y
set arrow 21 from 0.50, 0.866 to 0,0 nohead linestyle 3
set arrow 22 from 0.05, 0.0866 to 0.1,0 nohead linestyle 3
set arrow 23 from 0.10, 0.173 to 0.2,0 nohead linestyle 3
set arrow 24 from 0.15, 0.260 to 0.3,0 nohead linestyle 3
set arrow 25 from 0.20, 0.346 to 0.4,0 nohead linestyle 3
set arrow 26 from 0.25, 0.433 to 0.5,0 nohead linestyle 3
set arrow 27 from 0.30, 0.520 to 0.6,0 nohead linestyle 3
set arrow 28 from 0.35, 0.606 to 0.7,0 nohead linestyle 3
set arrow 29 from 0.40, 0.693 to 0.8,0 nohead linestyle 3
set arrow 30 from 0.45, 0.779 to 0.9,0 nohead linestyle 3

# Numeros y

set label '0.1' at 0.41, 0.779 center tc rgb "yellow"
set label '0.2' at 0.36, 0.693 center tc rgb "yellow"
set label '0.3' at 0.31, 0.606 center tc rgb "yellow"
set label '0.4' at 0.26, 0.520 center tc rgb "yellow"
set label '0.5' at 0.21, 0.433 center tc rgb "yellow"
set label '0.6' at 0.16, 0.346 center tc rgb "yellow"
set label '0.7' at 0.11, 0.260 center tc rgb "yellow"
set label '0.8' at 0.06, 0.173 center tc rgb "yellow"
set label '0.9' at 0.01, 0.0866 center tc rgb "yellow"

#set key inside right center Left
set key font ",5"
#set key top left Right samplen 2 at 0.25, 0.57



plot "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densitiesk4r2.dat" t 'k=4-r=2' with lines ls 9,\
     "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densitiesk4r4.dat" t 'k=4-r=4' with lines ls 12,\
     "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densitiesk2r2.dat" t 'k=2-r=2' with lines ls 8,\
     "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densitiesk2r4.dat" t 'k=2-r=4' with lines ls 10,\
     "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densitiesR1k2.dat" t 'k=2-r=1' with lines ls 4,\
     "<awk '{print ($3+2*$5)/(2*($3+$4+$5)), sqrt(3)*$3/(2*($3+$4+$5))}' densities-std.dat" t 'std' with lines ls 11          

