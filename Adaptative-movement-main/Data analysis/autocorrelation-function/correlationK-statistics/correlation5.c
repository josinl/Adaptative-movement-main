
#include "parameters.h"

//Calculating the direction


void correlation5(double *phi_1,double *phi_2,double *phi_3){

	//if(argc != 6){
	//	printf("\nplease, type:\n\n %s file_1.dat file_2.dat size_of_Nx size_of_Ny output.dat\n\n", argv[0]);
		//exit(0);
	//}

	int i, j, l;
	int *nor;
	double *p_1, *p_2, *p_3, *c_r_11, *c_r_22, *c_r_33, *c_r_12, *c_r_13;
	double mu;
	FILE *file;
	char name[100];

//	Nx= atoi(argv[3]);
//	Ny= atoi(argv[4]);

	nor= (int    *) calloc(2*Nx,  sizeof(int   ));
	p_1= (double *) calloc(Nx*Ny, sizeof(double));
	p_2= (double *) calloc(Nx*Ny, sizeof(double));
	p_3= (double *) calloc(Nx*Ny, sizeof(double));
	c_r_11= (double *) calloc(2*Nx,  sizeof(double));
	c_r_22= (double *) calloc(2*Nx,  sizeof(double));
	c_r_33= (double *) calloc(2*Nx,  sizeof(double));
	c_r_12= (double *) calloc(2*Nx,  sizeof(double));
	c_r_13= (double *) calloc(2*Nx,  sizeof(double));



	fftw_complex *i_1= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_1= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *i_2= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_2= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *i_3= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_3= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));

	fftw_complex *o_12= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_13= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));

	fftw_complex *o_11= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_22= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *o_33= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));

	fftw_complex *i_12= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *i_13= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));

	fftw_complex *i_11= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *i_22= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));
	fftw_complex *i_33= (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*(Nx*Ny));




	mu= gsl_stats_mean(phi_1, 1, Nx*Ny);
	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			phi_1[i*Ny+j]-= mu;
			i_1[i*Ny+j]= phi_1[i*Ny+j] + 0.0*I;
		}
	}

	//phi_2
	mu= gsl_stats_mean(phi_2, 1, Nx*Ny);
	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			phi_2[i*Ny+j]-= mu;
			i_2[i*Ny+j]= phi_2[i*Ny+j] + 0.0*I;
		}
	}

	//phi_3
	mu= gsl_stats_mean(phi_3, 1, Nx*Ny);
	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			phi_3[i*Ny+j]-= mu;
			i_3[i*Ny+j]= phi_3[i*Ny+j] + 0.0*I;
		}
	}



	fftw_plan FT1= fftw_plan_dft_2d(Nx, Ny, i_1, o_1, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(FT1);
	fftw_plan FT2= fftw_plan_dft_2d(Nx, Ny, i_2, o_2, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(FT2);
	fftw_plan FT3= fftw_plan_dft_2d(Nx, Ny, i_3, o_3, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(FT3);


	double SUM_11= 0.0;			double SUM_12= 0.0;
	double SUM_22= 0.0;     double SUM_13= 0.0;
	double SUM_33= 0.0;



	for(i= 0; i< (Nx*Ny); i++){
		o_12[i]= o_1[i]*conj(o_2[i]);
  	o_13[i]= o_1[i]*conj(o_3[i]);
		o_11[i]= o_1[i]*conj(o_1[i]);
		o_22[i]= o_2[i]*conj(o_2[i]);
		o_33[i]= o_3[i]*conj(o_3[i]);


		SUM_12+= o_12[i];
		SUM_13+= o_13[i];


		SUM_11+= o_11[i];
		SUM_22+= o_22[i];
		SUM_33+= o_33[i];



	}

	fftw_plan FTB_11= fftw_plan_dft_2d(Nx, Ny, o_11, i_11, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(FTB_11);
	fftw_plan FTB_22= fftw_plan_dft_2d(Nx, Ny, o_22, i_22, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(FTB_22);
	fftw_plan FTB_33= fftw_plan_dft_2d(Nx, Ny, o_33, i_33, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(FTB_33);
	fftw_plan FTB_12= fftw_plan_dft_2d(Nx, Ny, o_12, i_12, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(FTB_12);
	fftw_plan FTB_13= fftw_plan_dft_2d(Nx, Ny, o_13, i_13, FFTW_BACKWARD, FFTW_ESTIMATE);
	fftw_execute(FTB_13);






	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			l= i+j;
			c_r_11[l]+= creal(i_11[i*Ny+j]);
			c_r_22[l]+= creal(i_22[i*Ny+j]);
			c_r_33[l]+= creal(i_33[i*Ny+j]);


			c_r_12[l]+= creal(i_12[i*Ny+j]);
			c_r_13[l]+= creal(i_13[i*Ny+j]);


			nor[l]++;
		}
	}

	for(l= 0; l< (2*Nx); l++){

		c_r_11[l]/= nor[l];
		c_r_22[l]/= nor[l];
		c_r_33[l]/= nor[l];



		c_r_12[l]/= nor[l];
		c_r_13[l]/= nor[l];



	}


	for(l= 0; l< (2*Nx); l++){

 		CR[0][l] = c_r_11[l]/c_r_11[0];
		CR[1][l] = c_r_22[l]/c_r_22[0];
		CR[2][l] = c_r_33[l]/c_r_33[0];
		CR[3][l] = c_r_12[l]/c_r_12[0];
		CR[4][l] = c_r_13[l]/c_r_13[0];

}

printf("%f\n" , CR[1][1]);

/*
	sprintf(name, "%s", argv[5]);
	if(!(file= fopen(name, "w"))){
		printf("cannot open file %s/dat/c_r.dat\n", argv[1]);
		exit(0);
	}
	for(l= 0; l< (2*Nx-1); l++){
		fprintf(file, "%e\n", c_r[l]/c_r[0]);
	}
	fclose(file);
*/

	free(c_r_11);
	free(c_r_22);
	free(c_r_33);
	free(c_r_12);
	free(c_r_13);

	free(nor);
	fftw_destroy_plan(FT1);
	fftw_destroy_plan(FT2);
	fftw_destroy_plan(FTB_11);
	fftw_destroy_plan(FTB_22);
	fftw_destroy_plan(FTB_33);

	fftw_destroy_plan(FTB_12);
	fftw_destroy_plan(FTB_13);

	fftw_free(i_1);
	fftw_free(o_1);
	fftw_free(i_2);
	fftw_free(o_2);
	fftw_free(i_3);
	fftw_free(o_3);

  fftw_free(i_11);
	fftw_free(o_11);
	fftw_free(i_22);
	fftw_free(o_22);
	fftw_free(i_33);
	fftw_free(o_33);

	fftw_free(i_12);
	fftw_free(o_12);
	fftw_free(i_13);
	fftw_free(o_13);


	fftw_cleanup();
	//return 0;
}
