#include<stdio.h>

int main()
{	

	const int SIZE=26;
	char alphebet[SIZE];
	for(int i=0;i<SIZE;i++)
		alphebet[i]='a'+i;

	for(int i=0;i<SIZE;i++)
	{
		printf("%c ",alphebet[i]);
		if((i+1)%6==0)printf("\n");
	}
	printf("\n");

	return 0;
}


