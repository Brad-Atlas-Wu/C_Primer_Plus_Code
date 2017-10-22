/*
	任务：求幂。利用命令行模式直接输入幂的底数（double类型）和指数(整数)

	因为argv储存的是char的类型，所以需要进行强制类型转换

	伪代码：
	//首先是判断输入的参数是否合法（包括个数和类型），调用一个子函数吧
	if(没有输入参数)提示输入参数
	else if(只输入了一个参数)提示输入第二个参数
	
	if(参数类型不符合)提示			//这里涉及到两个问题：1.如何判断参数是不是纯数字的问题
	else 将值分别给底数和指数 			              2. 如何将char字符串数字转换为double和int
						//注意：在输入中，所有字符都是字符类型
							//所以需要判断输入的每个字符(用isdigit())


	//最后,if(子函数判断并赋值成功)再由主函数计算幂		
	
BUG：这个程序比第一个版本简化了很多，利用的是atoi和atof的返回值，当他们的参数不是数字的时候，会返回0,
	但是程序只会提取出开头遇到的数字。如果输入，aa11，那么返回未0，可是如果输入的是11aa,那么返回的是11，而不是0！这样就导致程序无法判断参数中的非法字符！头痛！

	可能是思路是用atof/atoi遍历字符串，如果输出都有效，那么就可以，当然还有一个BUG:如果我输入的数字为0呢？
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>		//包含了atoi(),atof()
int examine(double * base, int * expo,char **);		//判断输入类型是否正确，如果正确，就赋值，否则退出
int main(int argc,char ** agrv)
{
	double base;	//底数
	int expo;	//指数
	if(argc!=3)		//判断参数个数是否正确
	{
		printf("参数个数不正确!\n");
		return -1;	
	}
	else if(examine(&base,&expo,agrv))			//参数都没有问题,可以计算幂了
	{
			long double result=1.0;
			for(int i=0;i<expo;i++)
			{
				result*=base;
			}
		printf("%lf的%d次幂是%llf\n",base,expo,result);
	}
	else 			//参数类型有问题
	{
		printf("参数类型不正确！\n参数应该为一个浮点数（底数）和一个整型数（指数）\n");
		return -2;
	}
	return 0;
}


int examine(double * base,int * expo, char ** agrv)
{
	int stat=0;
	if((*base=atof(agrv[1])) && (*expo=atoi(agrv[2])))		//表示这两个参数类型合法，可以赋值了
	{
		stat=1;
	}

	return stat;		//如果两个参数类型都没问题，就返回1，提示主函数计算幂
}
