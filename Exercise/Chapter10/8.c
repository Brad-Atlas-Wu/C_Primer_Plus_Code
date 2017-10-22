#include<stdio.h>
#define SIZE 7
void copy_arr(double a[],double b[],int n);


int main(void)
{
	double source[SIZE]={1.0,2.0,3.0,4.0,5.0,6.0,7.0};
	double target[3];
	copy_arr(target,source+2,3);
	for(int i=0;i<3;i++)
	{
		printf("%lf ",target[i]);
	}
	printf("\n");
	return 0;
}


void copy_arr(double * t,double * s,int n)
{
	for(int i=0;i<n;i++)*(t+i)=*(s+i);
}

