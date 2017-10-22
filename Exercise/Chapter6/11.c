#include<stdio.h>
#define SIZE 8
int main()
{
	int i,num[SIZE];
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&num[i]);
	}
	
	  for(i=SIZE-1;i>=0;i--)
        {
                printf("%d  ",num[i]);
        }

}
