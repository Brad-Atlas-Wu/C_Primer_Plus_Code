/*任务：用户输入一个文件名，程序读取文件内容，并把所有小写转换为大写，写回到原文件中（替代掉原来的内容）
 * 	(试图不借助任何临时文件！！！)
 *
 * 算法 ： 我认为这个程序的难点在于要把转换后的内容写回到源文件中，那么就要求一下子读取文件中的所有内容，转换为大写之后，再存储到源文件中，这样就可以避免替换掉还没有读取的内容。但是这样的问题在于~~~缓冲区有那么大吗？
 *
 * 	我的解决方案(试图不借助任何临时文件！)：
 * 			用r+模式打开文件
 * 			位置移动到文件的结尾，记录下结尾的位置（方便之后删除前面的内容，以及知道该读到哪里）
 * 			回到文件开头
 * 			读文件内容，直到刚刚前面记录的结尾位置
 * 			把转换为大写后的内容附加在文件的结尾后面
 * 			利用之前记录的文件位置，删除转换前的内容
 *
 * 	待解决：如何不借助临时文件删除文件的某部分内容？
 * */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 81	//文件名的上限为81-1个字符
int main(void)
{
	FILE * fp;	//文件指针
	char filename[SIZE];	//记录文件名
	long last;		//记录源文件结尾的位置
	long current=0L;	//记录当前的位置
	int ch;

	printf("Enter a file name: ");
	scanf("%s",filename);
	while(getchar()!='\n')continue;	//因为scanf()不接受回车空格等,当然这个不是必要的，因为后面没有输入

	if((fp=fopen(filename,"r+"))==NULL)	//接下来需要同时对文件进行读写操作
	{
		fprintf(stderr,"Cant't open file:%s\n",filename);
		exit(EXIT_FAILURE);
	}
	
	fseek(fp,0L,SEEK_END);	//定位到文件结尾
	last=ftell(fp);		//记录源文件结尾的位置，返回值是相对文件开头的偏移量
	rewind(fp);		//回到文件开头

/*
	//测试
	ch=getc(fp);
	putchar(ch);

	fseek(fp,last-2,SEEK_SET);
	ch=getc(fp);
        putchar(ch);
	printf("\n");
*/

	//在遇到源文件原来的结尾之前，读取，转换，附加在结尾
	while( ((current=ftell(fp))<last) && (ch=getc(fp)) )
	{
		fseek(fp,current+last,SEEK_SET);	//定位到源文件最后一个字符的后面
		putc(toupper(ch),fp);			//把转换为大写的字符写入此位置
		
		fseek(fp,current+1,SEEK_SET);		//定位到源文件的下一个字符
	}

//最后一步还解决不了：如何不借助临时文件删除文件中的一部分内容
	long i=last;
	while(fseek(fp,--i,SEEK_SET)>=0)
	{
		putc(0,fp);
	}

	fclose(fp);	
	return 0;

	
}
