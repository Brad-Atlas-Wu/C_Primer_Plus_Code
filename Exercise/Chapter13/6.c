/*本程序将例题13.2由命令行模式修改为用户输入模式
 *
 * 任务：程序通过命令行接受参数，参数为待压缩的文件名
 *      程序把文件压缩成原来的三分之一（写入每三个字符的第一个字符）,压缩后的内容保存在文件名.red中
 *       
 *    知识点：***这个程序演示了如何在程序中创建一个文件，给它命名，添加后缀名，并且向文件中写入内容***
 *            
 */


#include<stdio.h>
#include<stdlib.h>	//提供exit()的原型,只要有涉及到打开文件的时候，就用exit而不是return
#include<string.h>	//提供strcpy(),strcat()的原型
#define LEN 40

char * s_gets(char *,int n);

int main(void)
{
	FILE * in,* out;	//声明两个指向FILE的指针(in指向源文件，out指向压缩后的文件)
	int ch;		
	char oldname[LEN-5];	
	char name[LEN];		//储存输出文件的文件名（包含后缀）
	int count=0;		//计算读取的字符数量

	printf("Please enter the filename you want to condense: ");
	if((s_gets(oldname,LEN-5))==NULL)
	{
		fprintf(stderr,"Fail getting filename!\n");
		return 1;
	}	

	
	//设置输入(当然顺便检查有没有正确打开文件)
	if((in=fopen(oldname,"r"))==NULL)
	{
		fprintf(stderr,"I couldn't open the file\"%s\"\n",oldname);	
		exit(EXIT_FAILURE);
	}

	//设置输出(下面步骤实际上创建了一个“文件名.red”的新文件，并以写入模式打开，用于储存压缩后的结果！)
	//****这里学习到了如何在程序中新建一个文件***
	strncpy(name,oldname,LEN-5);	//拷贝文件名(至少要留出五个元素储存后缀名和/0)
	name[LEN-5]='\0';	
	strcat(name,".red");
	if((out=fopen(name,"w"))==NULL)		//以写模式打开文件(也是在同时判断)
	{
		fprintf(stderr,"Can't create output file.\n");//使用标准错误文件指针
		exit(3);
	}

	//拷贝数据
	while((ch=getc(in))!=EOF)
		if(count++ % 3 ==0)	
			putc(ch,out);	//打印3个字符中的第一个字符（到文件“文件名.red”中）

	//收尾工作
	if(fclose(in)!=0 || fclose(out) != 0)		//如果文件正常关闭，返回值应该是0
		fprintf(stderr,"Error in closing files\n");

	return 0;
}

char * s_gets(char * name,int n)
{
	char * ret_val;
	char * pos;
	ret_val=fgets(name,n,stdin);
	if((pos=strchr(name,'\n')))
	{
		*pos='\0';
	}
	return ret_val;
}
