#!/usr/bin/gnuplot

reset

set term tikz
#set term png size 670,500

set xtics font ", 14"
set ytics font ", 14"

set xl't\,' font ", 16" offset 0,-1.25,0
#set yl'$\zeta_i$' font ", 19" offset -1.5,0,0
set yl'$\zeta_i\,(\%)$' font ", 19" offset -1.5,0,0

set xr[0:5000] 
set yr[0.01:0.09]
#set yr[0.5:8]

# define axis
set style line 11 lc rgb '#2f4f4f' lt 1
#set border 3 back ls 11
#set tics nomirror

#set key bottom left Left reverse samplen 1 at -10,0.6

# define grid
#set style line 12 lc rgb '#2f4f4f' lt 0 lw 1
#set grid back ls 12

# color line definitions
set style line 1 lc rgb '#f43169' lt 1 lw 4.5 pt 5 ps 1.0 #  green      (species 1)
set style line 2 lc rgb '#ffb6c1' lt 1 lw 4.5 pt 5 ps 1.0 #  red	(species 2)
set style line 3 lc rgb '#0b0404' lt 1 lw 4.5 pt 5 ps 1.0 #  orange     (species 3)
set style line 4 lc rgb '#949494' lt 1 lw 4.5 pt 5 ps 1.0 #  dark blue  (species 4)
set style line 5 lc rgb '#FF9100' lt 1 lw 4.5 pt 5 ps 1.0 #  cyan	(species 5)
#set style line 6 lc rgb 'grey' lt 1 lw 4.5 pt 5 ps 1.0 #  black	(empty space)

    


	outname = sprintf("risks.tex")

	set out outname

set size 2.8, 2.0







################################# Start multiplot (2x3 layout) ##################

set multiplot layout 2,3 rowsfirst
###here begin the densisities ####
### GRAPH a #####
#set xr[0:100] 
set yr[1.0:6.0]

set label 1 '\bf{a}' at graph 0.1, 0.85 font ',25'

set label 2 'standard' at graph 0.385, 0.85 font ',15'

#set key bottom right Right samplen 0 at 0.5, 0.5

set origin 0, 1.0
set size 1.0, 1.0

plot 'risk-std.dat' u (($1)*50):(($2)*100) with lines ls 1 t '1',\
     'risk-std.dat' u (($1)*50):(($3)*100) with lines ls 2 t '2',\
     'risk-std.dat' u (($1)*50):(($4)*100) with lines ls 3 t '3'
	
	
### GRAPH b ####

set label 1 '\bf{b}' at graph 0.1, 0.85 font ',25'

set label 2 '$\epsilon$ = 2.0' at graph 0.35, 0.85 font ',15'


set origin 1.0, 1.0
set size 1.0, 1.0

plot 'risk-e2.dat' u (($1)*50):(($2)*100) with lines ls 1 t '1',\
     'risk-e2.dat' u (($1)*50):(($3)*100) with lines ls 2 t '2',\
     'risk-e2.dat' u (($1)*50):(($4)*100) with lines ls 3 t '3'

### GRAPH c ###

set label 1 '\bf{c}' at graph 0.1, 0.85 font ',25'
set label 2 '$\epsilon$ = 4.0' at graph 0.35, 0.85 font ',15'

set origin 2.0, 1.0
set size 1.0, 1.0

plot 'risk-e4.dat' u (($1)*50):(($2)*100) with lines ls 1 t '1',\
     'risk-e4.dat' u (($1)*50):(($3)*100) with lines ls 2 t '2',\
     'risk-e4.dat' u (($1)*50):(($4)*100) with lines ls 3 t '3'


#### Here begin the statistcs #### 
set xr[0:5000] 
set yr[2.2:4.0]
set key at 4,2.9
### GRAPH d #####
set style line 11 lc rgb '#2f4f4f' lt 1
set xtics font ", 14"
set ytics font ", 14"
set yr[2.2:4.0] 
set xr[-0.25:4.25] 

set xl'$\epsilon$' font ", 16" offset 0,-1.25,0

set label 1 '\bf{d}' at graph 0.1, 0.85 font ',25'
set label 2 ' ' at graph 0.35, 0.85 font ',15'

#set key bottom right Right samplen 0 at 0.5, 0.5

set origin 0, 0.0
set size 1.0, 1.0
#set key at 4,0.028

#plot 'risk-std.dat' u (($1)*100):(($2)*100)  with lines ls (i-1) t' '.(i-1)

     
plot 'statistics-epsilon.dat' u 1:(($6)*100):(($13)*100) with errorbars axes x1y1 ls 1 t'1',\
     'statistics-epsilon.dat' u 1:(($7)*100):(($14)*100) with errorbars axes x1y1 ls 2 t'2',\
     'statistics-epsilon.dat' u 1:(($8)*100):(($15)*100) with errorbars axes x1y1 ls 3 t'3',\
     'statistics-epsilon.dat' u 1:(($6)*100) with lp ls 1 notitle,\
     'statistics-epsilon.dat' u 1:(($7)*100) with lp ls 2 notitle,\
     'statistics-epsilon.dat' u 1:(($8)*100) with lp ls 3 notitle
     
     
     
		
### GRAPH e ####

set label 1 '\bf{e}' at graph 0.1, 0.85 font ',25'

set xl'$R$' font ", 16" offset 0,-1.25,0

set label 2 ' ' at graph 0.35, 0.85 font ',15'

set xtics 0,1,4

set origin 1.0, 0.0
set size 1.0, 1.0
#set key at 4,0.028

 plot 'statistics-radius.dat' u 1:(($6)*100):(($13)*100) with errorbars ls 1 t'1',\
     'statistics-radius.dat' u 1:(($7)*100):(($14)*100) with errorbars ls 2 t'2',\
     'statistics-radius.dat' u 1:(($8)*100):(($15)*100) with errorbars ls 3 t'3',\
     'statistics-radius.dat' u 1:(($6)*100) with lp ls 1 notitle,\
     'statistics-radius.dat' u 1:(($7)*100) with lp ls 2 notitle,\
     'statistics-radius.dat' u 1:(($8)*100) with lp ls 3 notitle

### GRAPH f ###
set xl'$\alpha$' font ",16" offset 0,-1.0,0
#set yl'$\rho_i$'  font ", 18" offset -1.7,0,0
set key at 1,2.9
set xr [-0.1:1.10]

set xtics 0,0.2,1

set label 1 '\bf{f}' at graph 0.1, 0.85 font ',25'
set label 2 ' ' at graph 0.35, 0.85 font ',15'

#set key at 1,0.028
#set label 2 '$\epsilon$ = 4.0' at graph 0.35, 0.85 font ',15'
#set yr[0.022:0.04] 
set origin 2.0, 0.0
set size 1.0, 1.0
 
 plot 'statisticslearn.dat' u 1:(($6)*100):(($13)*100) with yerrorbars ls 1 t '1',\
	'statisticslearn.dat' u 1:(($7)*100):(($14)*100) with yerrorbars ls 2 t '2',\
	'statisticslearn.dat' u 1:(($8)*100):(($15)*100) with yerrorbars ls 3 t '3',\
	'statisticslearn.dat' u 1:(($6)*100) with lp ls 1 notitle,\
	'statisticslearn.dat' u 1:(($7)*100) with lp ls 2 notitle,\
	'statisticslearn.dat' u 1:(($8)*100) with lp ls 3 notitle

unset multiplot

### End multiplot


