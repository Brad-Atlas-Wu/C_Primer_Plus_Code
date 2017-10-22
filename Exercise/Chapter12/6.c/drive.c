#include<stdio.h>

unsigned long rand0(void);
void seed(void);

long count[10];

int main(void)
{
	
	for(int i=0;i<10;i++)count[i]=0;

	printf("%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d\n",1,2,3,4,5,6,7,8,9,10);
	for(int i=0;i<10;i++)
	{
		rand0();
		for(int i=0;i<10;i++)
		{
			printf("%5ld",count[i]);
		}
		printf("\n");
		seed();
		for(int i=0;i<10;i++)count[i]=0;

	}
	printf("\n");
	
	return 0;
}

