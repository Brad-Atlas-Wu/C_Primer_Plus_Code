/*
 * 	定义字符串数组
 *	while(没有到文件末尾，读取字符)将字符赋予给对应的字符串元素
 *	末尾添加‘‘\0’
 *
 *	if(命令行参数是-p)顺序打印字符   //用strncmp()函数来对比
 *	else if(参数是-u)全部大写打印
 *	else if (参数是-l) 全部小写打印
 *	else 提示参数错误 
 *
 * */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

int main(int argc,char ** argv)
{
	char str[SIZE];
	int ch;
	int i=0;
	while((ch=getchar())!=EOF)str[i++]=ch;
	str[i]='\0';
	
//	printf("%c\n",str[i-1]);		//这里为了实验而加入一行，但是结果更让人费解，开头居然有两行空行！！
	
	if(argc>=2)
	{
		if(strncmp(argv[1],"-p",SIZE)==0)printf("%s\n",str);	//非常不解为什么输出中会多出一个换行符？？？
		else if(strncmp(argv[1],"-u",SIZE)==0)
		{
			int i=0;
			while(str[i]!='\0')printf("%c",toupper(str[i++]));
		}
		else if(strncmp(argv[1],"-l",SIZE)==0)
		{
			int i=0;
                	while(str[i]!='\0')printf("%c",tolower(str[i++]));

		}	
		else printf("请输入正确的参数!\n-p:顺序输出\t-u全部大写输出\t-l全部小写输出\n");
	}
	else printf("请输入参数!\n-p:顺序输出\t-u全部大写输出\t-l全部小写输出\n");
	return 0;
}
