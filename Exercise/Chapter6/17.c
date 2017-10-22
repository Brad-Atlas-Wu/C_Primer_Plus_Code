/*
	变量:int year记录时间，宏定义RATE,ORIGIN，WITHDRAW分别保存利率，原始资金和每年年尾取出的钱 
	
*/

#include<stdio.h>
#define RATE 0.08
#define ORIGIN 1000000
#define WITHDRAW 100000



int main()
{	
	int year;
	long origin=ORIGIN;
	for(year=0;origin>=0;origin-=WITHDRAW,year++)
	{
		origin+=origin*RATE;
	}
	printf("After %d years, the man will bankrupt\n",year);
	return 0;		
}












