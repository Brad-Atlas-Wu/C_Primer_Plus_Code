/*
 *	这是一个非常有趣，值得完善的程序
 *	原题任务：编写一个名儿string_in的程序，第一个参数是一个预定字符串，第二个参数是由用户输入的字符串
 *		在第一个字符串中搜索第二个字符串的内容，如果搜索到就返回第一个字符串中找到位置的地址，
 *		找不到就返回一个NULL
 *
 *	而我将任务进行了修改，string_in包含了四个参数，前两个参数与原题要求的一样，第三第四个参数类型为
 *		指向指针的指针，目的是储存在第一个字符串中找到的第二个字符串内容的开始地址和结束地址。
 *		最后打印出搜索到的字符串。这样问题就变得更加有难度了哈哈哈
 *
 *
 *
 *	这个程序相比于程序WWW8.c，解决了bug,
 *	程序的重点在于：1.使用指向指针的指针
 *			2.如何利用输入流来循环检查字符串的内容！
 *	
 * */

#include<stdio.h>
#define SIZE 50
#define CONTENT "Whatareyoudoing"
int string_in(char * container,char * str,char ** pp_s,char ** pp_d);	//用于储存字符串2在字符串1中的开始结束位置
void output(char * p_start , char * p_end);//输出				

int main(void)
{
	char container[SIZE]=CONTENT;			//初始化字符串1
	char str[SIZE];						
	char ch;		
	char * p=str;					//指向符合的字符串的开头
	char * p_start=str;				//指向符合的字符串的结尾
	char * p_end=str;
	char ** pp_s=&p_start;				//定义两个指向指针的指针，把p_start和p_end的地址传给子函数
	char ** pp_d=&p_end;				
	int stat;					//为0代表到了字符串的结尾
	int stat_tot=0;					//用来控制每次字符串传递给子函数的开始位置

	while((ch=getchar())!='\n')			//输入另一个搜索字符串
	{
		*p++=ch;
	}
	*p='\0';	//标志字符串结束
		
//	if(stat=string_in(container,str,pp_s,pp_d)) output(p_start,p_end);
//	else puts("Not found!");
	
	stat=string_in(container,str,pp_s,pp_d);
	while(stat)		//重点：利用循环控制输入流！
	{
		output(p_start,p_end);
		stat_tot+=stat;
		stat=string_in(container+stat_tot,str,pp_s,pp_d);
	}
	return 0;
}

int string_in(char * container,char * str,char ** pp_s, char ** pp_d)	//这个子函数要能够对比两个字符串
{									//并且能记录开始匹配和匹配结束的位置
	_Bool isstart=1;	//	代表刚刚遇到第一个匹配的字符
	int n=0;
	while(*container!='\0')
	{	
		n++;
		
		if(isstart==1 && *container==*str)	//遇到的第一个匹配字符，标志地址
		{	
			*pp_s=container;
			isstart=0;
		}
		container++;
		
		if(isstart==0)				
		{
			if(*container!=*++str || *container=='\0')	//遇到第一个不匹配的字符或到了container结尾
			{	
				*pp_d=container;			//实际指向结束的后一位
				return n;
			}		
		}
	}
	return 0;
	
}

void output(char * p_start, char * p_end)
{
	while(p_start<p_end)
	{
		putchar(*p_start++);
	}
	printf("\n");
}
