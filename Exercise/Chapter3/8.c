#include<stdio.h>

int main()
{
	float n;
	printf("Please enter the num of cups:");
	scanf("%f",&n);
	printf("In the US, %.0f cups is euqal to %f pint,%f ounce, %f spoon, and %f tea spoon!\n",n,0.5*n,(1.0/8.0)*n,(1.0/8.0)*n*2.0,(1.0/8.0)*n*6.0);
        return 0;
}

