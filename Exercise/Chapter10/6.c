#include<stdio.h>
#define SIZE 10
void order(double *,int n);

int main(void)
{
	double array[SIZE]={1.2,3.2,4.3,7.5,92.3,12.5,21.8,32.9,43.6,21.3};
	for(int i=0;i<SIZE;i++)printf("%lf ",array[i]);
	printf("\n");

	order(array,SIZE);
	for(int i=0;i<SIZE;i++)printf("%lf ",array[i]);
        printf("\n");
	return 0;
}

void order(double * p, int n)
{
	int i,j;
	double temp;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE-i;j++)
		{
			if(*(p+j)<*(p+j+1))
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;

			}
		}
	}
}

	
