/*
 *	任务：输出用户输入的第一个单词，丢弃后面内容，如单词全面有空白字符，应当跳过，
 *		并且限制单词的最大长度
 *
 *	伪代码：
 *		while(遇到换行符之前，且小于读取的最大字符数)接受用户输入
 *			if(遇到单词前，如果是空白字符) 跳过
 *			else if(遇到空白字符)   结束字符串
 *			else	//遇到有效字符，赋值给数组，计算字符数  
 * */


#include<stdio.h>
#include<ctype.h>
#define IN 1
#define OUT 0
#define SIZE 10
char * get_str(char * ,int);

int main(void)
{
        char *pc;
        char str[SIZE];
        pc=get_str(str,5);
        printf("The adress:%p\n",pc);
        puts(pc);
        return 0;
}

char * get_str(char * str,int limit)
{
	char * pc=str;		//因为后面有对str的操作，所以先定义指针pc指向str头地址
	char ch;
	int n=0;		//用于计算输入的字符数
	_Bool stat=OUT;		//开始的时候在单词外面
	while(n<limit)
	{
		ch=getchar();	//获取输入
		if(stat==OUT && isspace(ch))continue;	//跳过开头的空白
		else if(isspace(ch))			//单词之后遇到空白，跳出循环
		{
			break;
		}	
		else					//遇到第一个单词，把字符赋给数组
		{
			stat=IN;
			n++;
			*str++=ch;
		}
	}
	*str='\0';					//标志支付串结束，这个非常重要！！！
	return pc;					//返回数组的首地址
	
}
