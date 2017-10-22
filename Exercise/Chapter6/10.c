#include<stdio.h>

int main()
{
	int upper,lower;
	long sum=0;
	printf("Please enter the lower and upper:\n");
	scanf("%d %d",&lower,&upper);
	while(upper>lower)
	{	
		sum+=lower*lower;
		lower++;
	}
	if(sum==0)printf("Done!\n");
	else
	{
	sum+=lower*lower;
	printf("the sum is %ld\n",sum);
	}
	return 0;

}
