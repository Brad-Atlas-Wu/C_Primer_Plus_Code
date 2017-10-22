#include<stdio.h>

int main()
{
	int bin[8];
	int n=1;
	for(int i=0;i<8;i++)
	{
		n*=2;
		bin[i]=n;
	}
	
	
	int i=0;
	do
	{
		printf("%d ",bin[i]);
		i++;
	}
	while(i<8);	//记得吼吼有一个；
	printf("\n");
}
