#include<stdio.h>

int main()
{
	int upper,lower;
	printf("Please enter the upper num:\n");
	scanf("%d",&upper);
	printf("Please enter the lower num:\n");
	scanf("%d",&lower);
	for(int i=lower;i<=upper;i++)
	{
		printf("%d\t%d\t%d\n",i,i*i,i*i*i);
	}
	return 0;
	
}


