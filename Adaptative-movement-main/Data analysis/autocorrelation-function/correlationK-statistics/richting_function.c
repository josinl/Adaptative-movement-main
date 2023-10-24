#include "parameters.h"





void richting_function(){

	//int  fTrono(int Tam,int Vetor[Tam]);
	//int  fbusca_linear(int pVetor, int pValor_a_procurar, int pQuantidade);
	//int  ftaxis(int tam, int *Vetor_direcao[tam],int v_pos);


double *alloc(int);


	double *den_species1, *den_species2, *den_species3, *den_vacancies;
	double *risk_predation1;
	double *risk_predation2;
	double *risk_predation3;



	//densities of individuals and vacancies
	den_species1 = alloc(num_generations);
	den_species2 = alloc(num_generations);
  	den_species3 = alloc(num_generations);
	den_vacancies = alloc(num_generations);

	risk_predation1 = alloc(num_generations);
	risk_predation2 = alloc(num_generations);
	risk_predation3 = alloc(num_generations);



	double *phi, *phi_1, *phi_2, *phi_3, *phi_4, *phi_5;
	phi = alloc(Nx*Ny);
		phi_1 = alloc(Nx*Ny);
			phi_2 = alloc(Nx*Ny);
				phi_3 = alloc(Nx*Ny);


	// initial conditions
	init_cond(phi, phi_1, phi_2, phi_3);//phi é o grid, phi_i é o grid verdadeiro-falso da especie i


	// difinitions random GSL
        const gsl_rng_type *T;
        gsl_rng *r;
        gsl_rng_env_setup();
        T=gsl_rng_default;
        r=gsl_rng_alloc(T);


	int i,j,k; // auxiliary coordinate variables
	//int x,y, dx,dy;
	int sum_1=0;
	int sum_2=0;
	int sum_3=0;
	double xi_1=0;

	int key; // auxiliary variable for successful interactions
	double temp; // temporary variable to mobility of the species
	double gsl_action;
	double gsl_passive, gsl_dispersion, gls_antipredatory;


	int sum_1_L=0,sum_2_L=0, sum_3_L=0, sum_4_L=0, sum_5_L=0, sum_0_L=0;
	int sum_1_N=0,sum_2_N=0, sum_3_N=0, sum_4_N=0, sum_5_N=0, sum_0_N=0;
	int sum_1_S=0,sum_2_S=0, sum_3_S=0, sum_4_S=0, sum_5_S=0, sum_0_S=0;
	int sum_1_O=0,sum_2_O=0, sum_3_O=0, sum_4_O=0, sum_5_O=0, sum_0_O=0;
	int x,y, dx,dy, direction;
	double gsl_direction, gsl_antipredatory, gsl_learning, focus;



		mda1=0.0;
		mda2=0.0;
		mda3=0.0;

		mda0=0.0;

	int counter_interac = 0; // interactions counter
	int count1=0, count2=0; // auxiliary variable for successful interactions
	 counter1=initial_population;
	 counter2=initial_population;
	 counter3=initial_population;


	    // initial population for predation risk

	    int n1_0, n2_0, n3_0;
	    n1_0 = counter1;
	    n2_0 = counter2;
	    n3_0 = counter3;


	    int n_predations1, n_predations2, n_predations3;
	    n_predations1=0;
	    n_predations2=0;
	    n_predations3=0;





	while(counter_interac < num_interactions){


		// choosing the active individual
		do{
			i = gsl_rng_uniform(r)*Nx;
			j = gsl_rng_uniform(r)*Ny;

			active = j*Nx+i;

		}while(phi[active] == 0.0);


		// sorting the passive position
		gsl_passive = gsl_rng_uniform(r);








				// sorting the passive position
				gsl_passive = gsl_rng_uniform(r);


				if(gsl_passive<0.125)
					passive=((j+1)%Ny)*Nx+i;

				else if(gsl_passive>=0.125 && gsl_passive<0.250)
					passive=((j-1+Ny)%Ny)*Nx+i;

				else if(gsl_passive>=0.250 && gsl_passive<0.375)
					passive=j*Nx+(i+1)%Nx;

				else if(gsl_passive>=0.375 && gsl_passive<0.500)
					passive=j*Nx+(i-1+Nx)%Nx;

				else if(gsl_passive>=0.500 && gsl_passive<0.625)
					passive=((j+1)%Ny)*Nx+(i+1)%Nx;

				else if(gsl_passive>=0.625 && gsl_passive<0.750)
					passive=((j-1+Ny)%Ny)*Nx+(i-1+Nx)%Nx;

				else if(gsl_passive>=0.750 && gsl_passive<0.875)
					passive=((j+1)%Ny)*Nx+(i-1+Nx)%Nx;

				else
					passive=((j-1+Ny)%Ny)*Nx+(i+1)%Nx;

		    //printf("%e\n" , pa1);

				key = counter_interac;
				// sorting the action of active
				gsl_action=gsl_rng_uniform(r);
				gsl_antipredatory=gsl_rng_uniform(r);


				if(phi[active]==1.0){ // species 1

					if(gsl_action<pa){ // reproduction
						if(phi[passive]==0.0){
							phi[passive]=1.0;
							counter_interac++;
							counter1++;
						}
					}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
						if(phi[passive]==2.0){
							phi[passive]=0.0;
							counter_interac++;
							counter2--;
		          				n_predations2++;
						}
		          		}else{  // mobility
						//gsl_learning=gsl_rng_uniform(r);
						if(kappa_kinesis_1!=0.0 && radius!=0.0){
							//kinesis here
						 sum_1=0;
						 sum_2=0;
						 sum_3=0;
							// computing the values of local densities
							for(x=(i-radius); x<=(i+radius); x++)
								for(y=(j-radius); y<=(j+radius); y++)
									if((pow((x-i),2)+pow((y-j),2)) <= pow(radius,2)){
										dx = (x+Nx)%Nx;
										dy = (y+Ny)%Ny;
										if(phi[dy*Nx+dx] == 1.0)
											sum_1++;
										else if(phi[dy*Nx+dx] == 2.0)
											sum_2++;
										else if(phi[dy*Nx+dx] == 3.0)
											sum_3++;
									}
							//relative_density = (sum_3-sum_2)/(sum_1+sum_2+sum_3);
						 	xi_1 = 0.5*(1.0+tanh(kappa_kinesis_1*(sum_3-sum_2)/(sum_1+sum_2+sum_3)));
						}
						else{
							xi_1=0.5; // sem kinesis
						}

						if(gsl_antipredatory<xi_1){ //presa
							temp=phi[passive];
							phi[passive]=phi[active];
							phi[active]=temp;
							counter_interac++;
						}
					}// end of mobility
				}// end of species 1

				else if(phi[active]==2.0){ // species 2
					if(gsl_action<pa){ // reproduction
						if(phi[passive]==0.0){
							phi[passive]=2.0;
							counter_interac++;
							counter2++;
						}
					}
					else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
						if(phi[passive]==3.0){
							phi[passive]=0.0;
							counter_interac++;
							counter3--;
		          				n_predations3++;

						}
		          		}else{  // mobility
						if(kappa_kinesis_2!=0.0 && radius!=0.0){
							//kinesis here
							sum_1=0;
							sum_2=0;
							sum_3=0;
							// computing the values of local densities
							for(x=(i-radius); x<=(i+radius); x++)
								for(y=(j-radius); y<=(j+radius); y++)
									if((pow((x-i),2)+pow((y-j),2)) <= pow(radius,2)){
										dx = (x+Nx)%Nx;
										dy = (y+Ny)%Ny;
											if(phi[dy*Nx+dx] == 1.0)
												sum_1++;
											else if(phi[dy*Nx+dx] == 2.0)
												sum_2++;
											else if(phi[dy*Nx+dx] == 3.0)
												sum_3++;
									}
							//relative_density = (sum_3-sum_2)/(sum_1+sum_2+sum_3);
							xi_1 = 0.5*(1.0+tanh(kappa_kinesis_2*(sum_1-sum_3)/(sum_1+sum_2+sum_3)));
						}else{
							xi_1=0.5; // sem kinesis
						}
						if(gsl_antipredatory<xi_1){ //presa
							temp=phi[passive];
							phi[passive]=phi[active];
							phi[active]=temp;
							counter_interac++;
						}
					}
				}

				else if(phi[active]==3.0){ // species 3
					if(gsl_action<pa){ // reproduction
						if(phi[passive]==0.0){
							phi[passive]=3.0;
							counter_interac++;
							counter3++;
						}
					}else if(gsl_action>=(pa) && gsl_action<(pa+pc)){ // intercompetition
						if(phi[passive]==1.0){
							phi[passive]=0.0;
							counter_interac++;
							counter1--;
		          				n_predations1++;
						}
		          		}else{  // mobility
						if(kappa_kinesis_3!=0.0 && radius!=0.0){
							//kinesis here
							sum_1=0;
							sum_2=0;
							sum_3=0;
							// computing the values of local densities
							for(x=(i-radius); x<=(i+radius); x++)
								for(y=(j-radius); y<=(j+radius); y++)
									if((pow((x-i),2)+pow((y-j),2)) <= pow(radius,2)){
										dx = (x+Nx)%Nx;
										dy = (y+Ny)%Ny;
										if(phi[dy*Nx+dx] == 1.0)
											sum_1++;
										else if(phi[dy*Nx+dx] == 2.0)
											sum_2++;
										else if(phi[dy*Nx+dx] == 3.0)
											sum_3++;
									}
							//relative_density = (sum_3-sum_2)/(sum_1+sum_2+sum_3);
							 xi_1 = 0.5*(1.0+tanh(kappa_kinesis_3*(sum_2-sum_1)/(sum_1+sum_2+sum_3)));
						}else{
							xi_1=0.5; // sem kinesis
						}
						if(gsl_antipredatory<xi_1){ //presa
							temp=phi[passive];
							phi[passive]=phi[active];
							phi[active]=temp;
							counter_interac++;
						}
					}
				}

				// condition for a successful interaction
				if(counter_interac != key){

					// condition to the number of files allowed
					if((counter_interac % (num_interactions/num_files)) == 0.0){
						// recording the grid data
						output_grid(phi,count1);

						count1++;
					}

					// condition to the number of data allowed
					if((counter_interac % (Nx*Ny)) == 0.0){
						den_species1[count2] = (double)counter1/(Nx*Ny);
						den_species2[count2] = (double)counter2/(Nx*Ny);
		        den_species3[count2] = (double)counter3/(Nx*Ny);
						den_vacancies[count2] =(1.0-den_species1[count2]-den_species2[count2]-den_species3[count2]);

						risk_predation1[count2]=(double)n_predations1/(n1_0);
						risk_predation2[count2]=(double)n_predations2/(n2_0);
						risk_predation3[count2]=(double)n_predations3/(n3_0);

							count2++;
						n_predations1=0;
						n1_0 = counter1;
						n_predations2=0;
						n2_0 = counter2;
						n_predations3=0;
						n3_0 = counter3;



					}

				}



				if(counter1 == 0 || counter2 == 0 || counter3 == 0){

			//printf("%d %d %d %d\n" , counter1, counter2, counter3, radius);

			break;
			}


			} // while-key



 //simulation ends



//presence layer for each species
//maybe to make a function



						for(i=0; i<Nx; i++){
							for(j=0; j<Ny; j++){

							if (phi[j*Nx+i]==1.0){
								phi_1[j*Nx+i]=1;}//otherwise is 0

						else if(phi[j*Nx+i]==2.0){
								phi_2[j*Nx+i]=1;}

						else if(phi[j*Nx+i]==3.0){
								phi_3[j*Nx+i]=1;}





						}
					}

					printf("%f %f %f %f \n" , phi[47], phi_1[47],phi_2[47], phi_3[47]);


					correlation5(phi_1, phi_2, phi_3);





	// recording the densities data
	output_densities(den_species1, den_species2, den_species3,den_vacancies,risk_predation1, risk_predation2, risk_predation3);
	gsl_rng_free(r);

	free(risk_predation1);
	free(risk_predation2);
	free(risk_predation3);


	free(phi);
	free(phi_1);
	free(phi_2);
	free(phi_3);

	free(den_species1);
	free(den_species2);
    free(den_species3);
	free(den_vacancies);



}
