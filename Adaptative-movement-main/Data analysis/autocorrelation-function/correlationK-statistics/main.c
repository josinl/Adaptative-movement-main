#include "parameters.h"
double m_eff, done;
double *alloc(int size){
double *vector;

	// allocated lines
	vector=(double *) malloc(sizeof(double) *size);

	// always test if the allocation was successful
	if(!vector){
		fprintf(stderr, "Error allocating vector !\n");
		exit(1);
	}

	return vector;
}

int main(){


	int i, j, k, w, ij, l, percent=0, xx, yy;

//	double coexist[n][13]; // media, p, sigma;
	double mean_CR[5][2*Nx], p_CR[5][2*Nx], sigma_CR[5][2*Nx]; //
//	[0] - c_r_11 ... [8] - c_r_15


	for(k=0; k<5; k++){
		for(l=0; l<2*Nx; l++){
		mean_CR[k][l] = 0.0;
		 p_CR[k][l] = 0.0;
		 sigma_CR[k][l] = 0.0;
	}
}




	seed = Seed;


			for(i=0; i<N; i++){//seed


				richting_function();

				percent++;

				done = 100.0*percent/(N);

				//printf("%e %d %d \n ", auxiliary[k],k,seed);

				printf("%e \n ", done);




				for(k=0; k<5; k++){
					for(l=0; l<2*Nx; l++){
					mean_CR[k][l] += CR[k][l]/N;
				}
			}


			seed++;



		} // i

			for(k=0; k<5; k++){
				for(l=0; l<2*Nx; l++){
				p_CR[k][l] += pow (CR[k][l]-mean_CR[k][l],2);
				sigma_CR[k][l] = sqrt(p_CR[k][l]/(N-1));
			}
		}












        FILE *out = fopen("statistics.dat", "w");

	fprintf(out,"# Table \n");

	for(i=0; i<2*Nx; i++){

                    fprintf(out,"%d %g %g %g %g %g %g %g %g %g %g", i, mean_CR[0][i], sigma_CR[0][i], mean_CR[1][i], sigma_CR[1][i], mean_CR[2][i], sigma_CR[2][i], mean_CR[3][i], sigma_CR[3][i], mean_CR[4][i], sigma_CR[4][i]);

		fprintf(out,"\n");
	}

        fclose(out);
}
