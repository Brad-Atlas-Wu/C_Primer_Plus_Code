/*	这个例子是递归方法处理倒叙问题的典型例子, P281程序清单9.8
 *	任务：输入一个十进制，输出二进制，用递归方法实现
 *
 * 	伪代码：
 * 	输入一个十进制数n
 * 	递归循环
 * 		n%2
 * 		n/2
 * 	直到n==0
 *
 *
 * */


#include<stdio.h>
void tran(int);		//输出二进制
int main()
{	
	int n;
	printf("Please enter a decimal num:\n");
	scanf("%d",&n);
	tran(n);
	printf("\n");
	return 0;
}

void tran(int n)
{
	if(n>=2)tran(n/2);
	printf("%d",n%2);
}
