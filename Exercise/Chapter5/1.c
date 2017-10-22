#include<stdio.h>

int main()
{
	const int M_PER_H=60;
	int hour,min,time;
	
	printf("please enter the minutes(enter 0 to quit):\n");
	scanf("%d",&time);
	while(time>0)
	{
		hour=time/M_PER_H;
		min=time%M_PER_H;
		printf("%d minutes is equal to %d hours and %d minutes\n",time,hour,min);
		scanf("%d",&time);
	}		
	return 0;	
}
