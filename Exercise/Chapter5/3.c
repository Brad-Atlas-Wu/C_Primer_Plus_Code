#include<stdio.h>
#define D_PER_W 7
int main(void)
{
	int week,day,time;
	printf("Please enter days:\n");
	scanf("%d",&time);
	while(time>0)
	{
		week=time/D_PER_W;
		day=time%D_PER_W;
		printf("%d days are %d weeks and %d days\n",time,week,day);
		scanf("%d",&time);
	}
	return 0;
	
	
}
