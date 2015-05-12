#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Create an array A(t+h) = A(t) - hkA(t)
 * Compute concentration at t = 100 
 * */

double anfirstorder(double initial, double k, int t)
{
	double conc;
	conc = initial*(exp(-k*t));
	return conc;
}


double * firstorder(double h, double k, int t)
{
	double *a = malloc(sizeof(double)*(t/h));
	double carry;
	int i;
	
	//Store size of array in first element
	a[0] = t/h;
	a[1] = 1.0;
	carry = a[1];

	for (i = 2; i <= t/h; i++)
	{
		a[i] = carry - (h*k*carry);
		carry = a[i];
	}
	return a;
}

int main(int argc, char *argv[])
{

	double *res, h, k, ana, len, time;
	int i, t;
	ana = anfirstorder(1.0, 0.05,100);
	
	h = atof(argv[1]);
	k = atof(argv[2]);
	t = atof(argv[3]);
	res = firstorder(h,k,t);
	len = res[0];
	time = h;


	for (i = 1; i <= len; i ++)
	{
		printf("%f ", time);
		printf("%f \n", res[i]);
		time += h;
	}

	printf("\n");
	printf("The analytical solution at t = 100 is: %f\n", ana);
	return 0;
}
	

