#!/usr/bin/gnuplot

reset

Nx= 200
Ny= 200
Nf= 100
Ng= 4000

############## plot densities #################
set term png size 560,370 enhanced font 'Verdana, 9'

set xl'Radius'
set yl'Mean Density'

set xr[0:50] 
#set yr[-0.02:0.5]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
set border 3 back ls 11
set tics nomirror

# define grid
#set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
#set grid back ls 12

# color line definitions
set style line 1 lc rgb 'red' lt 1 lw 3 pt 1.5 ps 0.5 #  orange    
set style line 2 lc rgb 'blue' lt 1 lw 3 pt 1.5 ps 0.5 #  orange    
set style line 3 lc rgb 'green' lt 1 lw 3 pt 1.5 ps 0.5 #  orange    
set style line 4 lc rgb 'yellow' lt 1 lw 3 pt 1.5 ps 0.5 #  orange
set style line 5 lc rgb 'purple' lt 1 lw 3 pt 1.5 ps 0.5 #  orange    
set style line 6 lc rgb 'pink' lt 1 lw 3 pt 1.5 ps 0.5 #  orange    
    

set out'statistics.png'

plot 'statistics.dat' u 1:2:3  with yerrorbars ls 1 t 'C_11',\
      'statistics.dat' u 1:4:5 with yerrorbars ls 2 t 'C_12',\
	'statistics.dat' u 1:6:7 with yerrorbars ls 3 t 'C_33'

