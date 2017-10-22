/*	任务：程序打开若干个源文件和一个目标文件，把源文件的内容追加到源文件末尾
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

int main(void)
{
	FILE * fa, * fs;	//fa指向目标文件，fs指向源文件
	int files=0;		//记录附加的文件数量
	char file_app[SLEN];	//目标文件名
	char file_src[SLEN];	//源文件名
	int ch;
	
	puts("ENTER name of destination file: ");
	s_gets(file_app,SLEN);		//获得目标文件的文件名
	if((fa=fopen(file_app,"a+"))==NULL)	//以追加模式打开目标文件
	{
		fprintf(stderr,"Can't open %s\n",file_app);
		exit(EXIT_FAILURE);
	}
	
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)	//为目标文件建立一个4096字节的缓冲区，所以下面的每次读写都是4096字节
	{
		fputs("Can't create output buffer\n",stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Enter name of first source file(empty line to quit): ");
	while(s_gets(file_src,SLEN) && file_src[0]!='\0')//获取源文件名且不为空行，循环
	{
		if(strcmp(file_src,file_app)==0)	//如果源文件=目标文件，不能添加
			fputs("Can't append file to itself\n",stderr);	
		else if((fs=fopen(file_src,"r"))==NULL)	//以读的模式打开源文件，并判断
			fprintf(stderr,"Can't open %s\n",file_src);
		else 
			{
				if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
				{
					fputs("Can't create input buffer\n",stderr);
					continue;
				}

				append(fs,fa);
				if(ferror(fs)!=0)	//检测是否出错
					fprintf(stderr,"Error in reading file %s.\n",file_src);
				if(ferror(fa)!=0)
					fprintf(stderr,"Error in writing file %s.\n",file_app);
				fclose(fs);
				files++;
				printf("File %s appended.\n",file_src);
				puts("Next file(empty line to quit): ");
			}
	}
	printf("Done appending. %d files appended.\n",files);
	rewind(fa);
	printf("%s contents:\n",file_app);
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

char * s_gets(char * st,int n)
{
	char * ret_val;	//返回值
	char * find;

	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');	//查找换行符
		if(find)		//如果地址不是NULL,也就是说如果有换行符
			*find='\0';		//那么就把换行符换成\0
		else 
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}

