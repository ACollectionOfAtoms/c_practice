#include <stdio.h>
#include <math.h>

/* Create an array that returns ln(N!)
 * another that returns Nln(N) - N
 * and then a funtion that returns their difference
 * use the main function to print out gnuplot format
 */

double * exact()
{
	static double a[99];
	double carry;
	int i;

	a[0] = 0.0;
	a[1] = log(2);
	carry = a[1];

	for (i = 2; i <= 100; i++)
	{
		a[i] = carry + log(i + 1);
		carry = a[i];
	}
	return a;
}

double * approx()
{
	static double b[99];
	double carry;
	int i;

	for (i = 0; i <= 100; i++)
	{
		b[i] = (i+1)*log((i+1)) - (i+1);
	}
	return b;
}

double * diff(double* a, double* b)
{
	static double diff[99];
	int i;

	for (i = 0; i <= 100; i ++)
	{
		diff[i] = fabs(a[i] - b[i]);
	}
	return diff;
}

double * diffpercent(double* a, double* b)
{
	static double diff[99];
	int i;

	for (i = 0; i <= 100; i ++)
	{
		diff[i] = ((fabs(a[i] - b[i]))/a[i])*100;
	}
	return diff;
}




int main()
{
	double *err, *perr, *ex, *apx;
	int i;
	ex = exact();
	apx = approx();
	err = diff(ex,apx);
	perr = diffpercent(ex,apx);
	for (i = 0; i < 100; i ++)
	{
		printf("%d ", i +1);
		printf("%f ", ex[i]);
		printf("%f ", apx[i]);
		printf("%f ", err[i]);
		printf("%f\n",perr[i]);
	}
	return 0;
}
	

