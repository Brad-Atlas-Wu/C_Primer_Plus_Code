#include<stdio.h>
#define SIZE 10
int maxsub(double *,int n);

int main(void)
{
	int sub;
	double array[SIZE]={1.2,3.2,4.3,7.5,92.3,12.5,21.8,32.9,43.6,21.3};
	sub=maxsub(array,SIZE);
	printf("最大值下标是%d,最大值是%lf\n",sub,array[sub]);
	
	return 0;
}

int maxsub(double * p,int n)
{
	double max=p[0];
	int sub=0;
	for(int i=0;i<n;i++)
	{
		if(p[i]>max)
		{
			max=p[i];
			sub=i;
		}
	}
	return sub;
	
}
