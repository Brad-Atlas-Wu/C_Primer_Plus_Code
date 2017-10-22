#include<stdio.h>

int main()
{
	double a,b;
	printf("Please enter two double num:\n");
	while(scanf("%lf %lf",&a,&b)==2)
	{
		printf("the result is %lf\n",(a-b)/(a*b));
	}
	return 0;
}
