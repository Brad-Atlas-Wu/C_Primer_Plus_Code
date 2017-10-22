/*本程序将例题13.5有用户输入界面更改为命令行界面。第一个参数为目标文件，后面的参数为源文件名
 * 最少要求输入两个参数
 * 任务：程序打开若干个源文件和一个目标文件，把源文件的内容追加到源文件末尾
 *
 *	知识点：1： 利用fwrite()和fread()进行拷贝（保证了拷贝的精度）
 *		2:  setvbuf()函数建立缓冲区
 *		3： ferror()处理错误
 *		4:  strchr()查找字符（程序中提供了新的把为字符串结尾\0的办法）
 *		5.  rewind()回到文件开头
 *		6.  其它各种输入输出函数演示
 *
 *
 * 	算法：	
 * 		获得并检验目标文件名
 * 			打开并检验目标文件（写入模式）
 * 			为目标文件建立并检验缓冲区
 *
 * 		循环获得并检验源文件名
 * 			检验源文件名是否等于目标文件名
 * 			打开并检验源文件（读模式）
 * 			为源文件建立并检验缓冲区
 *		
 *		从源文件中读出内容到源文件缓冲区
 *		把缓冲区中内容追加到目标文件中
 * 			
 * 		定位到目标文件开头
 * 		读取并输出内容
 *
 * 	问题1：发现在目标文件打开失败的时候（文件不存在），程序并没有像编写的那样应该输出：无法打开文件，而是继续向下执行
 *	猜想：是不是因为a+模式的缘故？
 *	回答：但以写/附加模式打开一个不存在的文件时，就会自动创建一个文件，因此并不会报错。只有当文件无法创建的时候（可能是因为权限不够），那么才会报错
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096	//缓冲区的大小，为4096字节
#define SLEN 81		//文件名字符数+1
void append(FILE * source,FILE * dest);		//用于把源文件中的内容附加到目标文件中
char * s_gets(char * st,int n);			//用于获得文件名，第二个参数限制文件名长度

int main(int argc, char * argv[])	//argv[1]作为目标文件，其余的作为源文件附加在目标文件后面
{
	FILE * fa, * fs;	//fa指向目标文件，fs指向源文件
	int files=0;		//记录附加的文件数量
	int ch;
	
	if(argc<3)
	{
		fprintf(stderr,"At least 3 argument!\n");
		return 1;
	}
	else
	{
		if((fa=fopen(argv[1],"a+"))==NULL)	//以追加模式打开目标文件
		{
			fprintf(stderr,"Can't open %s\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	
		if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)	//为目标文件建立一个4096字节的缓冲区，所以下面的每次读写都是4096字节
		{
			fputs("Can't create output buffer\n",stderr);
			exit(EXIT_FAILURE);
		}
	
		for(int i=2;i<argc;i++)
		{
			if(strcmp(argv[i],argv[1])==0)	//如果源文件=目标文件，不能添加
				fputs("Can't append file to itself\n",stderr);	
			else if((fs=fopen(argv[i],"r"))==NULL)	//以读的模式打开源文件，并判断
				fprintf(stderr,"Can't open %s\n",argv[i]);
			else 
			{
				if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
				{
					fputs("Can't create input buffer\n",stderr);
					continue;
				}

				append(fs,fa);
				if(ferror(fs)!=0)	//检测是否出错
				fprintf(stderr,"Error in reading file %s.\n",argv[i]);
				if(ferror(fa)!=0)
				fprintf(stderr,"Error in writing file %s.\n",argv[1]);
				fclose(fs);
				files++;
				printf("File %s appended.\n",argv[i]);
				puts("Next file(empty line to quit): ");
			}
		}
	}
	printf("Done appending. %d files appended.\n",files);
	rewind(fa);
	printf("%s contents:\n",argv[1]);
	while((ch=getc(fa))!=EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);

	return 0;
}

void append(FILE * source,FILE * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];	//只分配一次
	while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),bytes,dest);
}
