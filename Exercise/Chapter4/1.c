#include<stdio.h>

int main()
{
	char fname[10];
	char lname[10];
	printf("Please enter your name:\v");
	scanf("%s %s",fname,lname);
	printf("Hello,%s %s\n",fname,lname);
	return 0;
}
