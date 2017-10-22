#include<stdio.h>
#define SIZE 10
int getmax(int *,int n);

int main(void)
{
	int array[SIZE]={200,12,32,43,12,42,12,53,43,-99};
	int max;
	max=getmax(array,SIZE);
	printf("最大值是：%d\n",max);

	return 0;
}

int getmax(int * p,int n)
{
	int max=*p;
	for(int i=0;i<n;i++)
	{
		if(*(p+i)>max)max=*(p+i);
	}
	
	return max;
}
