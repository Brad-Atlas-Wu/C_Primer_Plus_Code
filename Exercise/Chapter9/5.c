#include<stdio.h>
void larger_of(double *,double *);
int main(void)
{
	double a=12.4;
	double b=10.3;
	larger_of(&a,&b);
	printf("a=%lf,b=%f\n",a,b);
	return 0;
}

void larger_of(double * a, double * b)
{
	(*a>*b)?(*b=*a):(*a=*b);
	
}
