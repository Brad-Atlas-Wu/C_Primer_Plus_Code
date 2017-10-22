/*
 *	任务：使用字符分类的方法实现atoi，如果输入不是纯数字，返回0
 *	分析：无疑要用到isdigit()，如果有非数字字符出现，直接返回，否则再进行转换
 *		转换的方法是利用ASCII码加差值就可以实现
 *
 *	伪代码：
 *	定义一个char字符串
 *	while(没有到文件的结尾)
 *		if(是数字)先储存字符
 *		else return 0
 *	
 *	总结：这个程序的算法不算复杂，但是有两个需要弄清楚的问题：
 *		1. 为什么while((ch=getchar())!=EOF)那里会多循环一次？
 *		2. 为什么pow函数当参数是变量的时候需要加命令行参数-lm才能正常运行？
 *		3. 为什么是n-1-i而不是n-i? i++是到什么时候才加1？（这里看估计是在遇到分号才加1）
 * */

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define SIZE 50
int myatoi(char *, int);
int main(void)
{
	
	int ch;		//这个地方必须是int类型，否则可能无法正确判读EOF!!!!!
	char str[SIZE];
	int i=0;	//顺便记录输入了多少个字符
	while((ch=getchar())!=EOF)		//疑问：不知道为什么感觉总是多循环了一次！！！
		str[i++]=(char)ch;
	str[i]='\0';		
	printf("输入的字符串是: %s",str);
	printf("对应的数字是: %d\n",myatoi(str,i-1));
	return 0;
}

int myatoi(char str[SIZE],int n)	//n代表之前输入的字符数量
{
	int sum=0;		//将要返回的对应的整型数值
	int i=0;
	while(i<n)
	{
		if(isdigit(str[i]))
		{
			sum+=(str[i++]-48)*(int)pow(10.0,(double)(n-1-i));	//先计算ASCII差值，将字符化为数值，再将数值放到正确的位上，最后求和
		}
		else return 0;
	}
	return sum;
}


