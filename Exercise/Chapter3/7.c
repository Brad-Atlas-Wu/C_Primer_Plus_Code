#include<stdio.h>

int main()
{
	float feet;
	printf("please enter your height(feet):");
	scanf("%f",&feet);
	printf("%f feet is %f centimeters!\n",feet,feet*2.54);
        return 0;
}

