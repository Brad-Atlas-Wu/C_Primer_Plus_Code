/*
	程序对比两种利息模式
	变量: int year记录时间， double investA和ivestB记录两个投资额
	宏定义两个利息率
	判断对比两个投资额，最后输出投资额和时间

*/


#include<stdio.h>
#define RATEA 0.1
#define RATEB 0.05
#define ORIGIN 100.0	//发现不论原始资金怎么改，都不会影响B超越A花的时间（因为他们有相同的启动资金）
int main()
{
	int year;
	double investA=ORIGIN;
	double investB=ORIGIN;
	double or=ORIGIN;	
	
	for(year=0;investA>=investB;year++)
	{
		investA+=RATEA*ORIGIN;
		investB+=RATEB*investB;
		
	}
	printf("With $%lf start capital\nAfter %d years, B would have $%lf ,while A only have $%lf\n",or,year,investB,investA);
	
	return 0;

}
