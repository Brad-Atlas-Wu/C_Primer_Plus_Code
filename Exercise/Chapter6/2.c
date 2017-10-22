#include<stdio.h>

int main()
{
	int i,j;
	char note='$';
	for(i=0;i<5;i++)
	{
		for(j=0;j<i+1;j++)
			printf("%c",note);
		printf("\n");
	}
	return 0;
}
