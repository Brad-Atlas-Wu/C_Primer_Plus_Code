/*任务：编写一个程序，接受两个命令行参数，第一个参数为一个字符串，第二个参数为一个文件名
 * 	打印文件中所有包含该字符串的行(这个程序是通过命令行模式来输入的，所以显然有一个缺陷，那就是输入的字符串必须是连续的，不能有分隔符！而如果是使用用户界面进行输入就可以解决这个问题)
 *
 * 知识点：1. strstr查找包含的字符串
 * 	   2. fgets()字符串输入
 *
 * 算法：
 * 	获得命令行参数
 * 	判断是否为两个参数，不是则返回错误
 *	
 *	以读模式打开文件
 *	按行读取并储存（假定每行255个字符），直到末尾
 *		strstr检验是否出现指定字符串
 *			有，则打印整行
 *
 *	关闭文件
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256	//假定每行最长为255个字符

int main(int argc,char * argv[])
{
	FILE * fp;
	char temp[SIZE];
	if(argc!=3)
	{
		printf("Usage: ./aout string filename\n");
		return 1;
	}
	
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[2]);
		exit(EXIT_FAILURE);
	}

	while(fgets(temp,SIZE,fp)!=NULL)
	{
		if(strstr(temp,argv[1]))
			fputs(temp,stdout);
	}
	fclose(fp);
	return 0;
}
