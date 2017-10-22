/*
 *	任务：设计一个简单的计算器
 *
 *	伪代码：
 *	输出选项列表
 *	用户输入选择加减乘除
 *		如果选择合法，对应相应的算法
 *		如果选择非法，输出列表要求重新输入
 *
 *	用户输入第一个数字
 *		如果不是数字，要求重新输入
 *	用户输入第二个数字
 *		如果不是数字，要求重新输入
 *		如果是除法，这个数字不可以为0，否则要求重新输入
 *
 *	根据算法和数字计算并输出结果
 *
 *
 *
 *
 *
 * */

#include<stdio.h>
char get_operand();		//获取运算符选项
float get_num();		//获取运算数字
float count(float,float,char);			//进行运算


int main()
{
	char operand,symbol;
	float num1,num2;
	operand=get_operand();
	if(operand==0)return 1;		//输入为q结束程序
	while(getchar()!='\n')continue;		//下面还有输入流，所以要养成跳过多余字符的习惯
	
	printf("Please enter the first number:\n");
	num1=get_num();
	printf("Please enter the second number:\n");
	while(!(num2=get_num()))	//如果输入的第二个数为0
	{	
		if(operand=='d')	//检验是不是除法，如果是，就提示并要求重新输入
		printf("除数2不能为0，重新输入\n");	//否则跳出循环
		else break;
	}
	
	switch(operand)			//这里选项转换为具体的运算符号表示
	{
		case 'a':symbol='+';break;
		case 's':symbol='-';break;
		case 'm':symbol='*';break;
		case 'd':symbol='/';break;
		default:break;
	}

	printf("%.3f %c %.3f = %.3f\n",num1,symbol,num2,count(num1,num2,operand));
	
	return 0;
}


char get_operand()
{
	char ch;
	printf("Enter the operation of your choice:\n");
        printf("%-16s %-16s\n%-16s %-16s\n%-16s\n","a.add","s.subtract","m.multiply","d.divide","q.quit");

	while((ch=getchar())!='a' && ch!='s' && ch!='m' && ch!='d'&& ch!='q' )
	{	
		printf("请输入列表中提供的选项\n");	
		printf("Enter the operation of your choice:\n");
		printf("%-16s %-16s\n%-16s %-16s\n%-16s\n","a.add","s.subtract","m.multiply","d.divide","q.quit");
		while(getchar()!='\n')continue;		
		
	}	
	if(ch=='q')return 0;
	return ch;

}

float get_num()
{	
	float n;
	char ch;
	while(scanf("%f",&n)!=1)
	{
		while((ch=getchar())!='\n')
		{
			putchar(ch);
		}
		printf(" is not a number,try again!\n");
	}
	return n;
}

float count(float num1,float num2,char operand)
{
	float result;
	switch(operand)
	{
		case 'a':result=num1+num2;break;
		case 's':result=num1-num2;break;
		case 'm':result=num1*num2;break;
		case 'd':result=num1/num2;break;
		default:break;
	}

	return result;
}


