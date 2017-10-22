/*
	文件包含两个函数：
		1. unsigned long rand0()
			生成随机数
		2. void seed() 
			修改随机数种子
*/
#include<stdio.h>
static unsigned long next=1;	//将next(随机数种子定义为内部链接的静态变量，以便文件内的其他函数访问
extern long count[];
void rand0()
{
	unsigned long roll;	//随机数
	for(int i=0;i<1000;i++)
	{
		next=next*1103515245+12345;
		roll=(unsigned long)(next/65536)%32768%10+1;
		count[roll-1]++;
	}
	
}
void seed()
{
	extern unsigned long next;
	next=next*2;
}
