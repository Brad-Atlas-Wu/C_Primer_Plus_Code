/*	任务：拷贝文件，文件副本的名称为源文件.cp。用命令行获得原始文件名称
 *		要求以二进制模式读写
 *	
 *	知识点：1.为文件添加后缀
 *	 	2. 利用二进制读写进行拷贝
 *	 	3. ferror检测错误
 *			
 *	算法：
 *	检测命令行参数
 *	产生副本文件名称
 *	以二进制读模式打开并检测源文件
 *	以二进制写模式打开并检测副本文件
 *
 *	子函数：读源文件内容，写入副本文件中 copy(FILE * fp1, FILE * fp2)
 * */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 81	//定义文件名上限80个字符
#define BUFSIZE 1000	//定义一次读写100个字节
void copy(FILE * fp1,FILE * fp2);

int main(int argc,char * argv[])
{
	FILE * fp1,* fp2;	//fp1代表源文件，fp2代表副本文件
	char cpfile[SIZE];	//记录副本文件的文件名

	if(argc!=2)
	{
		fprintf(stderr,"Invalid argument!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		strncpy(cpfile,argv[1],SIZE-4);	//复制文件名
		strncat(cpfile,".cp",SIZE);	//添加后缀名
	}
	if((fp1=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr,"Can't open file:%s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen(cpfile,"wb"))==NULL)
	{
		fprintf(stderr,"Can't open file:%s\n",cpfile);
                exit(EXIT_FAILURE);
	}
	copy(fp1,fp2);

	//检测读写过程中的错误
	if(ferror(fp1))
	{
		fprintf(stderr,"Fails to read file:%s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if(ferror(fp2))
        {
                fprintf(stderr,"Fails to write file:%s\n",cpfile);
                exit(EXIT_FAILURE);
        }


	return 0;
}

void copy(FILE * fp1, FILE * fp2)
{
	long bytes;
	char * temp[BUFSIZE];
	
	while((bytes=fread(temp,sizeof(char),BUFSIZE,fp1))!=0)	//读取源文件内容
		fwrite(temp,sizeof(char),bytes,fp2);	//写入目标文件
}	
