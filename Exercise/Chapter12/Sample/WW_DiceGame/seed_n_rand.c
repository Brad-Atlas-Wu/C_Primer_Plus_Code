/*
	文件包含两个函数：
		1. unsigned long rand0(unsigned int sides,unsigned int numbers)
			根据用户输入的面数和色子数量生成.输出和累加随机数，返回累加结果
		2. void seed() 
			修改随机数种子
	

*/
#include<time.h>
#include<stdio.h>
static unsigned long next;	//将next(随机数种子定义为内部链接的静态变量，以便文件内的其他函数访问)

unsigned long rand0(unsigned int sides, unsigned int numbers)
{
	unsigned long roll;
	unsigned long total=0;

	printf("你投掷的点数分别是:\n");
	for(int i=0;i<numbers;i++)
	{
		next=next*1103515245+12345;
		roll=(unsigned long)(next/65536)%32768%sides+1;	     //这里是（随机数%面数）+1，获得（1~面数）的数字
		printf("%lu ",roll);		//注意：unsigned long 的转换说明是ul而不是lu
		total+=roll;
	}
	printf("\n");
	return (unsigned long)total;
}

void seed()
{
	next=(unsigned int)time(0);
}
