#include <stdio.h>

/* Write a computer program to compute the factorial of every integer
between 1 and 100, and compare the results that are given by a simple form
of Sterling's approximation.

ln(N!) = Nln(N)-N

Plot the difference and estimate the point at which Sterling's approximation will be within 0.1% of
the exact result.
*/
int fact(int x)
{
	int i, fact;
	int counter = x-1;
	if (x == 1){
		return 1;
	}else{
		while (counter > 1)
		{
			fact = x*(counter);
			counter -= 1;
		}
	}
	return fact;
}

int main()
{
	int i,x;
	for (i = 1; i <101; i ++)
	{
		printf("%i\n",fact(i));
	}
	return 0;
}
