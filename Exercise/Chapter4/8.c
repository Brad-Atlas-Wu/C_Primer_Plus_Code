#include<stdio.h>
#define GtoL 3.785	// convert Gallon to Liter
#define MtoK 1.609	// conver Mile to Km
int main()
{
	float mile,oil;
	printf("Please enter the mile（英里）:\n");
	scanf("%f",&mile);
	printf("Please enter the amount of oil you consume（加仑）:\n");
	scanf("%f",&oil);

	printf("The milage is %f miles per gallon\n",mile/oil);
	
	oil*=3.785;
	mile*=1.609;
	printf("Which is %f liters each 100km\n",100.0*(oil/mile));
	return 0;

}
