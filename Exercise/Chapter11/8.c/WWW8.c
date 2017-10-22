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
 *	致命bug:  程序只能搜索首次遇见的匹配字符串，后面即便还有匹配的字符串程序也无法发现！！！ 
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
	int stat;

	while((ch=getchar())!='\n')			//输入另一个搜索字符串
	{
		*p++=ch;
	}
	*p='\0';	//标志字符串结束
		
	if(stat=string_in(container,str,pp_s,pp_d)) output(p_start,p_end);
	else puts("Not found!");

	return 0;
}

int string_in(char * container,char * str,char ** pp_s, char ** pp_d)
{

	_Bool isstart=1;	//	代表刚刚遇到第一个匹配的字符
	while(*container!='\0')
	{	
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
				return 1;
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
