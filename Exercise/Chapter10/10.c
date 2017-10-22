#include<stdio.h>
#define SIZE 3
void sum(int *,int *, int *,int);
int main(void)
{
	int var1[SIZE]={1,2,3};
	int var2[SIZE]={1,2,3};
	int result[SIZE];
	sum(var1,var2,result,SIZE);
	for(int i=0;i<SIZE;i++)printf("%d ",result[i]);
	printf("\n");


	return 0;
}

void sum(int * var1,int * var2,int * result,int n)
{
	for(int i=0;i<n;i++)
	{
		*(result+i)=*(var1+i)+*(var2+i);
	}
}
