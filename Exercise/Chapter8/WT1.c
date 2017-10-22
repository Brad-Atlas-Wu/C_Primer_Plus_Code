/*	P252，程序清单8.7
 *	任务：用户输入两个整数（范围在-10000000到10000000），程序输出以这两个整数为上限下限的所有整数的平方和
 *	
 *	伪代码： 
 *	1.要求用户输入一个整数：
 *		如果输入不是整数，提示并重新输入
 *
 *	
 *	2.验证上限下限是否有效：
 *		如果输入上限小于下限，无效重新输入
 *		如果上限大于10000000,无效重新输入
 *		如果下限小于-10000000，无效重新输入
 *
 *	3.计算平方和： 	
 *		以上限下限为界计算平方，记录累加和
 *
 *	错误：我的程序编写需要用到指针，需要进行修改！或者参考例题。
 *
 *	例题的思路是：
 *		用子函数1获得一个整数（验证是否为整数）  （这样就不需要函数传回两个值，不需要用到指针）
 *		
 *		用子函数2验证这个整数是不是合法范围
 *			如果是合法范围，就计算平方和
 *			如果不在合法范围，就要求重新输入
 * */

#include<stdio.h>
#define UPPER 10000000
#define LOW -10000000
void getnum(long,long);		//用于获得范围，验证输入是整数，并且数字在上限和下限的范围内
long long sqrsum(long,long);	//计算平方和,返回平方和
int main()
{
	long start,end;
	long long sum;
	void getnum();
	sum=sqrsum(start,end);
	printf("The sum of squre %ld to %ld is %lld\n",start,end,sum);
	return 0;
}

void getnum(long start,long end)
{	
	_Bool state=1;		//表示start是否大于end

	printf("请输入下限：\n");
        while((scanf("%ld",&start))!=1 || start<LOW || start>UPPER)             //当输入不是整数
        {
    	    	printf("请输入一个大于%ld小于%ld的整数下限！\n",LOW,UPPER);
                while(getchar()!='\n')continue;		//关键仍然是这里，跳过空格等其他符号
        }

	while(state==1)
	{			
		printf("请输入一个上限：\n");
		while((scanf("%ld",&end))!=1 || end>UPPER || end<LOW) 
		{
			printf("请输入一个大于%ld小于%ld的整数上限!\n",LOW,UPPER);
			while(getchar()!='\n')continue;
		}
		if(start>end)
		{
			state=1;
			printf("输入的下限大于上限，无效输入！\n");
		}
		else state=0;	
	}

}


long long sqrsum(long start,long end)
{
	int i;
	long long sum=0;
	for(i=start;i<=end;i++)
	{	
		sum+=i*i;
	}
	return sum;
}






