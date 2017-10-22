#include<stdio.h>

int main()
{
	int year;
	double sec;
	printf("Please enter your age:");
	scanf("%d",&year);
	printf("%d years equal to %.0lf seconds!\n",year,year*3.156e7);
        return 0;
}

