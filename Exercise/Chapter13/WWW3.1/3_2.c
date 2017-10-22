/*程序版本2（一次读取，转换一个字符）
 *
 * 任务：用户输入一个文件名，程序读取文件内容，并把所有小写转换为大写，写回到原文件中（替代掉原来的内容）
 * 	(试图不借助任何临时文件！！！)
 *
 *	程序版本1发现无法不借助其它临时文件而实现删除文件中一部分内容的功能
 *      	因此程序版本2采取一次读取一个字符，转换为大写，然后再替换掉原来字符的方法
 *      	而不像程序版本1那样先读取完文件的所有内容再进行转换
 *
 *知识点：1.替换文件内容	
 *
 * 算法 ： 
 * 	我的解决方案(试图不借助任何临时文件！)：
 * 			用r+模式打开文件
 * 			while(程序遇到结尾之前)
 * 				读取一个字符
 * 				回退1位到原来的位置
 * 				写入转换后的字符，替换掉原来的字符
 * 				关闭文件
 *
 * 显然要简洁大方好多！！！
 * */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 81	//文件名的上限为81-1个字符
int main(void)
{
	FILE * fp;	//文件指针
	char filename[SIZE];	//记录文件名
	int ch;

	printf("Enter a file name: ");
	scanf("%s",filename);
	while(getchar()!='\n')continue;	//因为scanf()不接受回车空格等,当然这个不是必要的，因为后面没有输入

	if((fp=fopen(filename,"r+"))==NULL)	//接下来需要同时对文件进行读写操作
	{
		fprintf(stderr,"Cant't open file:%s\n",filename);
		exit(EXIT_FAILURE);
	}
	

	while((ch=getc(fp))!=EOF) //每次读取一个字符，直到结束
	{

		ch=toupper(ch);		//转换为大写
		fseek(fp,ftell(fp)-1L,SEEK_SET);	//回退1位到原来的位置
		putc(ch,fp);			//替换原来的字符
	}

	fclose(fp);	
	return 0;

	
}
