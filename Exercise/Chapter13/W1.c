/*程序修改例题13.1（统计文件字符数量），要求不使用命令行模式，获取用户输入的文件名
 *
 * 	知识点：
 * 	1. fgets()会把结尾的'\n'都读入并且储存！所以需要下面一点程序来处理'\n'或者是多余的字符
        	if(find=strchr(filename,'\n'))
                	*find='\0';
        	else
                	while(getchar()!='\n')continue; 

 * 例题13.1：演示了如何用标准I/O读取文件和统计文件中的字符数,
 * 利用命令行获得参数(参数是一个文件名,程序读取并统计里面的字符)
 *
 * 尝试：
 * 	1.注释掉fclose(fp)语句，即不关闭文件
 * 		结果：我的结果是什么都没有改变。据网上说，当把东西写入文件的时候，是要写满了缓冲区（当然应该还有遇到			空格）之后，才会把内容存进文件中。所以如果缓冲区没满程序就结束了，那么刚刚写入的数据就会丢失！
 * 		而fclose提示程序在把缓冲区中的内容写入文件之后再释放文件指针，避免数据丢失。因此要养成关闭文件的习惯
 *
 * 	2.在其他目录文件下创建一个文件，比如在/root下创建文件word，然后运行./a.out word结果无法打开文件。但是使用绝		对路径/root/word可以顺利打开文件。所以，当文件和程序在同一个目录时，直接可以用文件名打开；否则就要输入绝对		路径
 **/
#include<stdio.h>
#include<stdlib.h>	//提供exit()的原型
#include<string.h>
#define SIZE 31		//文件名长度加一
int main(void)	
{
	int ch;	//读取文件时，储存每个字符的地方
	FILE * fp;	//FILE类型的指针，用来记录文件打开的地址
	unsigned long count=0;	//用来累计字符数量
	char  filename[SIZE];	//定义数组记录文件名
	char * find;

	//获得用户输入的文件名
	printf("Enter the file name: ");
	if(fgets(filename,SIZE,stdin)==NULL)
	{
		fprintf(stderr,"Enter filename error!\n");
		exit(EXIT_FAILURE);	
	}
/********************************************************/
	if(find=strchr(filename,'\n'))
		*find='\0';
	else
		while(getchar()!='\n')continue; 
/**********************************************************/

	if((fp=fopen(filename,"r"))==NULL)	//检验文件打开是否失败（比如找不到文件）
	{						//fopen(文件名的字符串地址，打开模式），直接的字符串字面量也是地址
		printf("Can't open %s\n",filename);
		exit(EXIT_FAILURE);
	}
	while((ch=getc(fp))!=EOF)	//getc()的参数fp告诉函数是要从这个地址中获取输入，EOF代表文件结尾
	{
		putc(ch,stdout);	//第二个参数代表把字符输出到屏幕，这个语句相当于putchar()
		count++;		//实际上，getchar()和putchar()就是通过getc()和putc()来实现的!
	}
	fclose(fp);			//关闭文件(尝试1：不关闭文件)
	printf("File %s has %lu characters\n",filename,count);
	
	return 0;

}
