#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Compute concentrations for A, B, and C species in a sequential first order chemical reaction
 * */

double *create_anfirstorder(double initialA, double k1, double k2, int t)
{
	double *species = malloc(3 * sizeof *species);
	double A, B, C;
	A = initialA*(exp(-k1*t));
	B = ((k1*initialA)/(k2 -k1))*(exp(-k1*t) - exp(-k2*t));
	C = initialA - A - B;
	species[0] = A;
	species[1] = B;
	species[2] = C;

	return species;
}


double **create_firstorder(double h, double k1, double k2, int t)
{
	double Acarry, Bcarry, Ccarry;
	int i, len = (int)floor(t/h);
	double *a = malloc(sizeof(double)*(t/h));
	double *b = malloc(sizeof(double)*(t/h));
	double *c = malloc(sizeof(double)*(t/h));
	double **concs;
	concs =(double **) malloc(3*sizeof(double *));

	//Store size of array in first element
	a[0] = t/h;
	b[0] = t/h;
	c[0] = t/h;

	a[1] = 1.0;
	b[1] = 0.0;
	c[1] = 0.0;

	Acarry = a[1];
	Bcarry = b[1];
	Ccarry = c[1];

	for (i = 2; i <= len; i++)
	{
		a[i] = Acarry - (h*k1*Acarry);
		b[i] = Bcarry + h*(k1*Acarry - k2*Bcarry);
		c[i] = Ccarry + h*(k2*Bcarry);

		Acarry = a[i];
		Bcarry = b[i];
		Ccarry = c[i];
	}

	concs[0] = a;
	concs[1] = b;
	concs[2] = c;
	return concs;
}


int main(int argc, char *argv[])
{

	double **res, *ana, h, k1, k2, len, time;
	int i, t;
	ana = create_anfirstorder(1.0, 0.01,0.2,100);
	
	h = atof(argv[1]);
	k1 = atof(argv[2]);
	k2 = atof(argv[3]);
	t = atof(argv[4]);

	res = create_firstorder(h,k1,k2,t);
	len = (int)floor(t/h);;
	time = h;


	for (i = 1; i <= len; i ++)
	{
		printf("%f ", time);
		printf("%f ", res[0][i]);
		printf("%f ", res[1][i]);
		printf("%f \n", res[2][i]);
		time += h;
	}
	printf("\n");
	printf("Analytically Calculated Concentrations:\n");
	printf("A: %f B: %f C: %f\n", ana[0], ana[1], ana[2]);

	free(ana);
	free(res);

	return 0;
}
