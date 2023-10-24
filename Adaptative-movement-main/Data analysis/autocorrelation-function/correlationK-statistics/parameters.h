#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_rng.h>


// control parameters
#define Nx 300
#define Ny 300
#define num_generations 500
#define initial_population Nx*Ny/3
#define num_files 1
#define num_interactions (num_generations*Nx*Ny)

#define Seed 501
#define dispersion 0.0

#define key_out 3 // grid →  1, layers →  2, both choices →  3

#define radius 2


#define kappa_kinesis_1 2.0
#define kappa_kinesis_2 0
#define kappa_kinesis_3 0


#define enters 500000



// control keys

#define ic_key       0 	// (0 → randomic, 1 →  specific initial condition)
#define c_key        0 	// correlation key (1 → on, 0 →  off)
#define mobility_5ey 0  // (0 → constant, 1 → taxis active, 2 → clever)



//  keys of directional moviment strategy

#define taxis_key 3		// (11 → randomic, 0 → empty space, 1 → prey, 2 → anticipation, 3 → refuge)


// intrinsic rate of growth of species

#define a1 1.0
#define a2 1.0
#define a3 1.0
#define a4 1.0
#define a5 1.0

// intraspecific competition parameter

#define b1 0.000
#define b2 0.000
#define b3 0.000

// interspecific competition parameter

#define c1 1.0
#define c2 1.0
#define c3 1.0
#define c4 1.0
#define c5 1.0


// mobility

#define mb 1.0
#define m1 mb
#define m2 mb
#define m3 mb
#define mi mb
#define m5 mb

// _____________statistics experiment:________________________________________________________

#define n 2  //41 // n*n is the number of simulations v_radius (nao tem mais esse v_radius nesse codigo)
#define N 20  //20 // N is the number of simulations varying the seed


//________________________________________________________________________________________



// Probability


// probability parameters - species 1
#define pa1 a1/(a1+c1+mb)
#define pm1 mb/(a1+c1+mb)
#define pc1 c1/(a1+c1+mb)

// probability parameters - species 2
#define pa2 a2/(a2+c2+mb)
#define pm2 mb/(a2+c2+mb)
#define pc2 c2/(a2+c2+mb)

// probability parameters - species 3
#define pa3 a2/(a3+c3+mb)
#define pm3 mb/(a3+c3+mb)
#define pc3 c3/(a3+c3+mb)

// probability parameters - species 4
#define pa4 a4/(a4+c4+mb)
#define pm4 mb/(a4+c4+mb)
#define pc4 c4/(a4+c4+mb)

// probability parameters - species 4
#define pa5 a5/(a5+c5+mb)
#define pm5 mb/(a5+c5+mb)
#define pc5 c5/(a5+c5+mb)

#include "prototype.h"

#define pa 0.1 //utilizando essas probabilidades aqui <---
#define pc 0.1 //utilizando essas probabilidades aqui <---
