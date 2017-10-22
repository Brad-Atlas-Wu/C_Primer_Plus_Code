/*	任务：书写一个掷色子的程序，可以根据用户输入的色子面数以及投掷的次数，输出每一次的投掷结果以及最后的总数
 *	
 *	循环：直到用户推出
 *		询问用户色子面数
 *		获得并判断面数输入
 *		
 *		询问需要色子的数量
 *		获得并判断色子的数量
 *	
 *		根据色子的面数和数量，生成，累加并输出随机数
 *
 *
 * 		子函数1：获得并判断色子面数		int getsides(void)
 * 		子函数2：询问并获得色子数量		int getnum(void)
 *		子函数3：根据色子的面数和数量（当然还有时间种子），生成,累计和输出随机数	void seed()和rand0(int sides,int num)
 *
 *		子函数1，2可在同一个文件中
 *		子函数3应该独立于一个单独的文件，因为不希望其他函数访问随机数种子
 * */

#include"head.h"

int main(void)
{
	unsigned int sides;	//记录色子有多少个面
	unsigned int numbers=-1;	//记录要投掷多少个色子
 	unsigned long total;
	seed();	//根据系统时间重置随机数种子
	while(numbers==-1)	//如果输入的色子数量一直为-1，那么就不断循环（相当于实现了返回上一级的功能！！）
	{
		printf("您希望色子有多少个面？(输入0退出)\n");
		if((sides=getsides())==0)return 1;
	
		printf("您希望有多少个色子？(输入0退出，-1返回上一级)\n");
		if((numbers=getdices())==0)return 2;
	}

	total=rand0(sides,numbers);
	printf("合计总点数为%lu\n",total);
	
	return 0;
}
