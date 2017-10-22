#include<stdio.h>
long double cube(double);

int main()
{
	double n;
	long double result;
	printf("Please enter a double num:\n");
	scanf("%lf",&n);
	result=cube(n);
	printf("cubic %lf is %llf\n",n,result);
	return 0;
}

long double cube(double n)
{
	long double result;
	result=n*n*n;
	return result;
}
