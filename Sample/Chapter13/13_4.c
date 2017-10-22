/*程序倒序显示文件内容
 *
 *重点：在***之间，演示结合fseek和ftell在文件中定位并且移动
 *
 * */


#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'	//Dos 文本文件中的文件结尾标记
#define SLEN 81

int main(void)
{
	char file[SLEN];	//储存文件名
	char ch;		
	FILE * fp;
	long count,last;	//last保存文件末尾的位置

	puts("Enter the name of the file to be processed:");
	scanf("%80s",file);		//获得文件名（小于等于80个字符）
	if((fp=fopen(file,"rb"))==NULL)		//二进制只读模式打开(因为下面的ftell()函数返回字节数)
	{
		printf("reverse can't open %s\n",file);
		exit(EXIT_FAILURE);
	}
/* ******************************************************************************************  */
	fseek(fp,0L,SEEK_END);		//定位到文件的末尾，注意偏移量是有L后缀的
	last=ftell(fp);			//last 记录文件的当前位置（也就是结尾的位置）
	for(count=1L;count<=last;count++)
	{
		fseek(fp,-count,SEEK_END);	//回退
		ch=getc(fp);
		if(ch!=CNTL_Z && ch!='\r')
			putchar(ch);
	}	
/* ************************************************************************************************ */
	putchar('\n');
	fclose(fp);
	return 0;
}


