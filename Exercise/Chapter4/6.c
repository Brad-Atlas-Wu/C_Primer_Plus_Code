#include<stdio.h>
#include<string.h>

int main()
{
	char name1[10];
	char name2[10];

	printf("Please enter your name:");
	scanf("%s",name1);
	scanf("%s",name2);
	printf("%10s  %10s\n",name1,name2);
	printf("%10zd  %10zd\n",strlen(name1),strlen(name2));


	printf("%-10s  %-10s\n",name1,name2);
        printf("%-10zd  %-10zd\n",strlen(name1),strlen(name2));

	return 0;

}
