#include<stdio.h>

int main()
{	
	int n;
	printf("Please enter an int:\n");
	scanf("%d",&n);
	for(int i=0;i<=10;i++)
	{
		printf("%d\t",n+i);
	}
	printf("\n");
	return 0;
}
