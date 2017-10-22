/*
	程序更具用户的类型和收入多少计算税金
	
	宏定义不同的税率
	输出选项表，然用户选择类别
		如果输入合法，继续程序
		如果输入不合法，提示，并重新输出选项表
	用户输入收入
	判断收入范围，从而计算交税多少
 */


#include<stdio.h>
#define BASE_RATE 0.15
#define EXTRA_RATE 0.28

int main()
{
	int n;	//记录用户类别
	long margin;	//税收分界
	double tax;	//要交的税金 
	long salary;
	_Bool t=0;	//记录是否进入第一个循环

	/*输出选项表*/
	printf("**************************************\n");
	printf("Please enter the number corresponding to your type(q to quite):\n");
	printf("1)单身\t\t2)\t\t户主\t\t3)已婚，共有\t\t4)已婚，离异\n");
	printf("**************************************\n");

	while((scanf("%d",&n))==1)
	{	
		t=1;
		if(n>=1 && n<=4)
		{
			switch(n)
			{
				case 1:margin=17850;break;
				case 2:margin=23900;break;
				case 3:margin=29750;break;
				case 4:margin=14875;break;
				default:return -1;break;
			}
			break;
		}
		else
		{	
			printf("非法输入！请重新输入！\n");
			printf("**************************************\n");
     			printf("Please enter the number corresponding to your type(q to quit):\n");
        	       	printf("1)单身\t\t2)\t\t户主\t\t3)已婚，共有\t\t4)已婚，离异\n");
	       		printf("**************************************\n");

		}
		
	}
	
	if(t==0 && scanf("%d",&n)!=1)return 1;
/*这里非常有趣，我希望如果输入的为非法字符，比如字母，那么就退出程序
	在之前的循环中，如果输入的是字母，比如q,那么当然是不会进入循环
	而这个q也会继续在内存中，作为这一个循环的输入。
	因此这个程序可以实现的是输入非法字符的时候推出程序
 */


	printf("Please enter your salary:\n");
	scanf("%d",&salary);
	if(salary<=margin)
	{
		tax=salary*BASE_RATE;
	}
	else
	{
		tax=margin*BASE_RATE+(salary-margin)*EXTRA_RATE;
	}
	printf("with %ld salary,you need to pay %lf tax\n",salary,tax);
	

	return 0;

}	








			
