#!/usr/bin/gnuplot

reset

set term tikz
#set term png size 670,500

set xl'Radius'
set yl'Mean Density'

#set xr[0:5.8] 
#set yr[0.15:0.3]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
set border 3 back ls 11
set tics nomirror

# define grid
#set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
#set grid back ls 12

# color line definitions
set style line 1 lc rgb 'red' lt 1 lw 4 pt 4.5 ps 1.0 #  orange    
set style line 2 lc rgb 'blue' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 3 lc rgb 'green' lt 1 lw 4 pt 4.5 ps 1.0 #  orange    
set style line 4 lc rgb 'yellow' lt 1 lw 4 pt 2.5 ps 1.0 #  orange
set style line 5 lc rgb 'purple' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
set style line 6 lc rgb 'pink' lt 1 lw 4 pt 2.5 ps 1.0 #  orange    
    
	outname = sprintf("densities.tex")

	set out outname

set size 1.2, 1.0

plot 'densities.dat' u 1:2 ls 1 t 'Empty space',\
      'densities.dat' u 1:3 ls 2 t '1',\
	'densities.dat' u 1:4 ls 3 t '2',\
	'densities.dat' u 1:5 ls 4 t '3',\
	'densities.dat' u 1:6 ls 5 t '4',\
	'densities.dat' u 1:7 ls 6 t '5'



	

