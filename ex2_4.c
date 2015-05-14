#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Compute concentrations for A, B, and C species in a sequential first order chemical reaction with back reactions
 * */

double **create_firstorder(double h, double kf1, double kb1, double kf2, double kb2, int t)
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
		a[i] = Acarry - kf1*h*Acarry + kb1*h*Bcarry;
		b[i] = Bcarry - kf2*h*Bcarry + kb2*h*Ccarry + kf1*h*Acarry;
		c[i] = Ccarry + kf2*h*Bcarry - kb2*h*Bcarry;
		
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

	double **res, *ana, h, kf1, kb1, kf2, kb2, len, time;
	int i, t;
	//ana = create_anfirstorder(1.0, 0.01,0.2,100);
	
	h = atof(argv[1]);
	kf1 = atof(argv[2]);
	kb1 = atof(argv[3]);
	kf2 = atof(argv[4]);
	kb2 = atof(argv[5]);
	t = atof(argv[6]);

	res = create_firstorder(h,kf1,kb1,kf2,kb2,t);
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
	free(res);

	return 0;
}

