/*程序版本3：读入整个文件内容，借助临时文件
 *
 * 任务：用户输入一个文件名，程序读取文件内容，并把所有小写转换为大写，写回到原文件中（替代掉原来的内容）
 * 	
 * 知识点：	1. remove()删除函数		
 * 		2. rename()重命名文件
 * 		3. 借助临时文件修改文件内容(指定内容)
 *
 * 算法 ：
 * 	我的解决方案(借助临时文件)：
 * 		用r+模式打开文件
 * 		w+模式（创建）打开临时文件temp
 * 		把源文件内容转换为大写并且写入源文件（从头写入，替换内容）
 * 		关闭两个文件
 * 		删除原文件
 * 		临时文件改名为源文件
 * 		
 * 		
 * */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 81	//文件名的上限为81-1个字符
int main(void)
{
	FILE * fp;	//原文件指针
	FILE * ftemp;	//临时文件指针
	char filename[SIZE];	//记录原文件名
	int ch;

	printf("Enter a file name: ");
	scanf("%s",filename);
	while(getchar()!='\n')continue;	//因为scanf()不接受回车空格等,当然这个不是必要的，因为后面没有输入

	if((fp=fopen(filename,"r+"))==NULL)	//接下来需要同时对文件进行读写操作
	{
		fprintf(stderr,"Cant't open file:%s\n",filename);
		exit(EXIT_FAILURE);
	}
	
	//创建并打开临时文件
	if((ftemp=fopen("temp","w+"))==NULL)
	{
                fprintf(stderr,"Cant't open temp file\n");
                exit(EXIT_FAILURE);
        }

	//把源文件字符转换并写入
	while((ch=getc(fp))!=EOF)
	{
		ch=toupper(ch);
		putc(ch,ftemp);
	}
	
	fclose(fp);	
	fclose(ftemp);
	remove(filename);
	rename("temp",filename);
	return 0;

	
}
