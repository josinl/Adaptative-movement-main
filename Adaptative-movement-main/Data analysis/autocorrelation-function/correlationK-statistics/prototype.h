
// ============ Prototypes ============

int active, passive, seed;

void init_cond(double *, double *, double *, double *);

void output_grid(double *, int);

void output_densities(double *, double *, double *, double *, double *, double *, double *);

void put_species(double *, int, double);

void richting_function ();

void correlation5(double *, double *, double *);

int counter1, counter2, counter3, counter4, counter5;

double v_radius;

double mda1, mda2, mda3, mda4, mda5, mda0;

double CR[5][2*Nx];
