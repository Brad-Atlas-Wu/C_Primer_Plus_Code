/*
	宏定义dunbar数，宏定义原始朋友数量， int friend记录朋友数量 ,int week记录周数
	while循环条件：当friend小于dunbar
*/
#include<stdio.h>
#define DUNBAR 150
#define ORIGIN 5
int main()
{
	int friend=ORIGIN;
	int week=1;
	while(DUNBAR>friend)
	{
		friend=(friend-1)*2;
		printf("On the %dth week, He has %d friends\n",week,friend);
		week++;
	}
	return 0;
}
