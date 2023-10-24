compiler = gcc
#compiler = gcc-4.9

flags = -O3

lib = -lm -lgsl -lgslcblas -lfftw3

arc = main.c  richting_function.c  alloc_i.c  alloc_d.c  init_cond.c output_densities.c output_grid.c correlation5.c
     

all:
	 @${compiler} ${flags} ${arc} ${lib} -o executable
