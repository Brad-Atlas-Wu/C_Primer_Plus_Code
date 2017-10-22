#include<stdio.h>
void order(double * ,double * ,double *);
int main(void)
{
	double a=1.22;
	double b=21.2;
	double c=11.2;
	printf("a=%lf,b=%lf,c=%lf\n",a,b,c);
	order(&a,&b,&c);
	printf("a=%lf,b=%lf,c=%lf\n",a,b,c);

	return 0;
}

void order(double * a ,double * b,double * c)
{
	double t;
	if(*a>*b)
	{
		t=*a;*a=*b;*b=t;
	}
	if(*a>*c)
	{
		t=*a;*a=*c;*c=t;
	}
	if(*b>*c)
	{
		t=*b;*b=*c;*c=t;
	}
	return;
}
