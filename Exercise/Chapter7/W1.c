#include<stdio.h>

int main()
{
	while((putchar(getchar()))!='@')  //这里真TM的太神奇了！证明编译器是先运算getchar后putchar，最后进行值比较
	;
	//当然上面的问题是会输出最后一个结束符. 要解决这个问题，就需要引入变量char ch
	return 0;
}

