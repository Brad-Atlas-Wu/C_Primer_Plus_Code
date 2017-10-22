#include<stdio.h>

int main()
{
	int n1,n2;
	printf("Enter an integer to serve as the second operand:\n");
	scanf("%d",&n2);
	printf("Now enter the first operand(<=0 to quit):\n");
	scanf("%d",&n1);
	printf("%d %% %d is %d\n",n1,n2,n1%n2);
	while(n1>0)
	{
		printf("Enter next number for first operand(<=0 to quit)\n");
		scanf("%d",&n1);
		printf("%d %% %d is %d\n",n1,n2,n1%n2);

	}
	return 0;
}
