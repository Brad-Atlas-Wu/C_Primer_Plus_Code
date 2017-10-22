/*任务：程序通过命令行参数接受一个字符和任意个文件名，一次报告每个文件中该字符出现的次数
 *
 *算法：
	for(循环访问所有文件)
		打开并检测文件
		while(文件结尾之前)
			按字符读取文件，如果字符是指定字符，++
		打印字符出现次数
		初始化字符出现次数
 *
 * */

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	FILE * fp;
	char ch;
	int count=0;

	if(argc<3)
	{
		printf("Usage: ./a.out character file1 file2.....\n");
		return 1;
	}
	for(int i=2;i<argc;i++)
	{
		if((fp=fopen(argv[i],"r"))==NULL)
		{
			fprintf(stderr,"Can't open file: %s\n",argv[i]);
			exit(EXIT_FAILURE);
		}
		
		while((ch=getc(fp))!=EOF)
			if(ch==argv[1][0])count++;
		printf("%c has occured %d times in the file %s\n",argv[1][0],count,argv[i]);
		count=0;	//初始化字符出现次数
		fclose(fp);	//释放指针
	}
	return 0;
}

