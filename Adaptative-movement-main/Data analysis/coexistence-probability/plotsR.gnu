#!/usr/bin/gnuplot

reset

Nx= 200
Ny= 200
Nf= 100
Ng= 4000

############## plot densities #################

set term tikz
#set term png size 640, 360 enhanced font 'Arial, 9'

set xl'\textit{m+n}' font ",16" offset 0,-1.0,0
set yl'Coexistence Probability' font ",14" offset -1.5,0,0

set arrow from 0.28,0 to 0.28,1 nohead lt 0 lw 2 lc rgb 'black'
set arrow from 0.6,0 to 0.6,1 nohead lt 0 lw 2 lc rgb 'black'

#set xr[0:1]
#set yr[0.15:0.3]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
#set border 3 back ls 11
#set tics nomirror


# color line definitions
set style line 1 lc rgb 'black' lt -1 lw 2.5 pt 7 ps 1
set style line 2 lc rgb 'blue' lt -1 lw 2.5 pt 7 ps 1
set style line 3 lc rgb '#00ff7f' lt -1 lw 2.5 pt 7 ps 1
set style line 4 lc rgb '#ff3333' lt -1 lw 2.5 pt 7 ps 1
set style line 5 lc rgb '#ffcc00' lt -1 lw 2.5 pt 7 ps 1
set style line 6 lc rgb '#3399ff' lt -1 lw 2.5 pt 7 ps 1
set style line 7 lc rgb 'green' lt -1 lw 2.5 pt 7 ps 1
set style line 8 lc rgb '#ff3333' lt 0 lw 2.5 pt 7 ps 1


	outname = sprintf("cpr.tex")

	set out outname

set size 1.6, 1.0

set object rectangle from screen 0.105,0.147 to screen 0.512,0.965 behind fillcolor rgb '#DCDCDC' fillstyle solid noborder
set object rectangle from screen 0.513,0.147 to screen 0.974,0.965 behind fillcolor rgb '#F5F5F5' fillstyle solid noborder
set object rectangle from screen 0.9745,0.147 to screen 1.556,0.965 behind fillcolor rgb 'white' fillstyle solid noborder

plot 'statistics-std.dat' u 1:2 with lp ls 1 t'std',\
      'statistics-r1.dat' u 1:2 with lp ls 5 t'R=1',\
      'statistics-r2.dat' u 1:2 with lp ls 2 t'R=2',\
      'statistics-r3.dat' u 1:2 with lp ls 4 t'R=3',\
      'statistics-r4.dat' u 1:2 with lp ls 7 t'R=4'
