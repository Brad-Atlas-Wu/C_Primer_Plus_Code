/*任务：用户输入两个文件名，交替打印两个文件的每一行(行号相同的输出在同一行)
 *
 * 知识点：交替输出两个文件的行 
* 
 * 算法：
 * 	提示用户输入两个文件名
 * 	以读模式打开两个文件并且检测
 * 	while(任意一个文件没有到结尾)
 * 		没到结尾，按行输出文件1
 * 		没到结尾，按行输出文件2		
 *
 * 	关闭两个文件
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81	//文件名长度80
char * s_gets(char * file, int n);
int main(void)
{
	FILE * fp1,*fp2;
	char file1[LEN];
	char file2[LEN];
	int ch;
	int stat1,stat2;	//表示两个文件是不是到结尾了
	
	//获取文件并且打开
	printf("Enter the file one: ");
	s_gets(file1,LEN);	
	while((fp1=fopen(file1,"r"))==NULL)
	{
		fprintf(stderr,"Can't open file: %s\n",file1);
		exit(EXIT_FAILURE);
	}
	
	printf("Now enter the file two: ");
	s_gets(file2,LEN);
        while((fp2=fopen(file2,"r"))==NULL)
        {
                fprintf(stderr,"Can't open file: %s\n",file2);
                exit(EXIT_FAILURE);
        
	}

	//交替输出两个文件的行
	stat1=feof(fp1);
	stat2=feof(fp2);

	//交替输出，如果其中一个文件结尾，另一个文件还没有EOF,那么没有结束的文件继续保持输出，知道两个文件都EOF
	while(stat1==0 || stat2==0)	//在两个文件都结束之前，保持循环
	{
		if(stat1==0)	
		{
			while((ch=getc(fp1))!=EOF && ch!='\n')putchar(ch);
			if(ch=='\n')
			{
				if(stat2==0)putchar('\t');	//文件2还没有到EOF
				else putchar('\n');
			}
			stat1=feof(fp1);
		}
		if(stat2==0)
		{
			while((ch=getc(fp2))!=EOF && ch!='\n')putchar(ch);
                        if(ch=='\n')putchar('\n');
                        stat2=feof(fp2);
                }
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}

char * s_gets(char * file,int n)
{
	char * ret_val;
	char * find;
	
	ret_val=fgets(file,n,stdin);
	find=strchr(file,'\n');
	if(find)
	{
		*find='\0';
	}
	else
	while(getchar()!='\n')continue;
	return ret_val;
}
