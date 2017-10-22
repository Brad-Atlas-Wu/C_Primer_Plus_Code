/*复习题5：
 * 
 * 任务：编写一个程序接受两个命令行参数，第一个参数是字符，第二个参数是文件名，程序只打印文件中包含指定字符的行
 *
 * 	算法：
 * 		打开并检测文件
 * 			while(不是EOF ,读入文件的一行，存进缓存（数组))
 * 				用strchr判断行是否包含指定的字符，如果存在就打印
 *
 * 	知识点：1.strchr 判断是否包含某个字符	2. feof判断是否到文件结尾
 * */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 256	//假设每行不超过256个字符
int main(int argc,char * argv[])
{
	char arr[SIZE];	
	FILE * fp;
	if(argc<3)
	{
		printf("Invalid argument!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		//打开文件
		if((fp=fopen(argv[2],"r"))==NULL)
		{
			fprintf(stderr,"Can't open file %s\n",argv[2]);
			exit(EXIT_FAILURE);
		}
		
		while(!feof(fp) && fgets(arr,SIZE,fp))	//但文件不到结尾的时候，一行行地读入
		{
			if(strchr(arr,*argv[1]))	//寻找是否有指定的字符
				fputs(arr,stdout);	//有就整行输出
		}
		
		fclose(fp);
	}
	return 0;
}
