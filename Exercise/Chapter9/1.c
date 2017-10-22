#include<stdio.h>
double min(double,double);
int main()
{
	double a,b;
	a=10.5;
	b=12.3;
	printf("%lf\n",min(a,b));
	return 0;
}


double min(double a,double b)
{
return a>b?b:a;
}
