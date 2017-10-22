/* **********本程序为自己模仿例题13.5的练习**************
算法：  
 *              获得并检验目标文件名
                	打开并检验目标文件（写入模式）
 *              	为目标文件建立并检验缓冲区
 *
 *              循环获得并检验源文件名
 *          	    	检验源文件名是否等于目标文件名
 *             	    	打开并检验源文件（读模式）
 *             	   	为源文件建立并检验缓冲区
 *                                 
 *              从源文件中读出内容到源文件缓冲区
 *              把缓冲区中内容追加到目标文件中  
 *		处理错误
 *                           
 *              定位到目标文件开头
 *              读取并输出内容
 *
 *	子函数：s_gets(char * ,int n)	获得并且检验文件名
 *		append(FILE *,FILE *)	执行内容的附件工作	
 *
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81	//定义文件名长度最多为81-1个字符
#define BUFSIZE 4096	//定义缓冲区为4096字节
int s_gets(char *,int n);	//获取文件名，返回值代表是否成功获取文件名(例题中的返回值为char * 类型)
void append(FILE * aim,FILE * source);	//把源文件内容附件给目标文件
int main(void)
{
	FILE * fa,* fs;	//定义目标文件和源文件的文件指针
	char file_aim[LEN];	//目标文件文件名
	char file_source[LEN];	//源文件文件名
	int ch;

	/*目标文件操作*/
	printf("Please enter the name of aim file: ");
	s_gets(file_aim,LEN);	//获取目标文件名

	if((fa=fopen(file_aim,"a+"))==NULL)     //以追加模式打开目标文件
	{
		printf("Can't open file: %s\n",file_aim);
		exit(EXIT_FAILURE);
	}

	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE))	//如果目标文件缓冲区建立失败，结束程序
	{
		printf("Fail to build buffer for %s\n",file_aim);
		exit(EXIT_FAILURE);
	}

	/*源文件操作*/
	printf("Please enter the first source files(empty to quit): \n");
	while(s_gets(file_source,LEN) && file_source[0]!='\0')//成功获得源文件名且不为空行,循环
	{
		if(strncmp(file_source,file_aim,LEN)==0)	//目标文件名和源文件相同，重新输入
		{
			printf("Can't append the file itself\n");
			printf("Enter the source file again(empty to quit)\n");
			continue;
		}
		if((fs=fopen(file_source,"r"))==NULL)	//源文件打开失败，结束程序
		{
			printf("Can't open file:%s\n",file_source);
			exit(EXIT_FAILURE);
		}

		if(setvbuf(fs,NULL,_IOFBF,BUFSIZE))
		{
			printf("Fail to build buffer for %s\n",file_source);
			exit(EXIT_FAILURE);
		}
		append(fa,fs);
		fclose(fs);	//******这里非常关键，需要释放指针，以便指针重新利用！*****
		
		printf("the file %s appended!\n",file_source);
		printf("Now, enter the next source file: \n");
		
	}

	rewind(fa);
	while((ch=getc(fa))!=EOF)
	{
		putchar(ch);
	}

	printf("\n");
	printf("Done!\n");
	return 0;
	
}

int s_gets(char * name,int n)
{
	int ch;
	int i=0;
	while((ch=getchar())!='\n' && i<n )
	{
		name[i]=ch;
		i++;
	}
	name[i]='\0';	//字符串结尾

	return i;	//i为0代表获取失败，非0代表获取文件名成功
}


void append(FILE * aim, FILE * source)
{
	static void * temp[BUFSIZE];	//中间数组
	size_t num;
	num=fread(temp,sizeof(char),BUFSIZE,source);	//从文件source中读取BUFSIZE*sizeof(char)个字节到temp中,返回字节个数
	while(num>0)
	{
		fwrite(temp,sizeof(char),num,aim);	//把temp中的字节流写入aim文件中（一次写BUFSIZE*sizeof(char)个）
		num=fread(temp,sizeof(char),BUFSIZE,source);
	}
}



