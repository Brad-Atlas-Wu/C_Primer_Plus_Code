/*
	要求输入一行内容，然后倒叙输出
	首先定义一个char 类型的数组,一个char变量作为中间变量；定义int i来控制数值(同时记录字符串长度)，int limit来记录字符串长度
	用while控制，循环输入字符
	倒叙输出
	
*/
#include<stdio.h>
#define SIZE 120

int main()
{
	char string[SIZE],c;
	int i,limit;
	
	i=0;
	while((c=getchar())!='\n')
	{	
		string[i]=c;
		i++;
	}
	string[i]='\0';
	

	printf("The inverse: ");
	for(;i>=0;--i)
	{
		printf("%c",string[i]);
	}
	printf("\n");
	
	return 0;
}
