#include<stdio.h>
double count(double a,double b);

int main()
{
	double a,b;
	double result;
	
	while(scanf("%lf %lf",&a,&b)==2)
	{
	result=count(a,b);
	printf("the result is %lf\n",result);
	}	
}

double count(double a, double b)
{
	return (a-b)/(a*b);
}
