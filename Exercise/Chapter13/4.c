/*任务：按顺序在屏幕上显示命令行输入的文件，argc控制循环
 *
 * 算法：
 * 	检验参数
 * 	循环（argc-->0）
 * 		打开文件
 * 		读取并输出内容
 * 		关闭文件
 *
 * */
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	FILE * fp;
	char ch;
	//检测参数
	if(argc<2)
	{
		printf("Invalid argument!\n");
		return 1;
	}
	else
	{
		for(int i=1;i<argc;i++)
		{
			if((fp=fopen(argv[i],"r"))==NULL)
			{
				fprintf(stderr,"Can't open file: %s\n",argv[i]);
				exit(EXIT_FAILURE);
			}

			printf("Content of file %s:\n",argv[i]);		
			while((ch=getc(fp))!=EOF)
				putc(ch,stdout);
	
			fclose(fp);
		}
	}
	return 0;
}
