/*
 *	任务： 打印输入字符及其十进制的ASCII码，
 *		用^A之类的符号替代空格以前的字符
 *		用'\n'和'\t'替代换行符和tab
 *		除遇见换行符外，每打印十对进行一次换行
 *
 *	伪代码：
 *		遇到EOF之前循环输入
 *
 *		如果字符码大于或等于空格，打印字符以及ASCII码
 *
 *		如果字符码小于空格
 *			如果是换行符或者制表符，打印'\n'或'\t'，并且打印ASCII
 *			否则以^@..^O形式打印出来，并打印ASCII
 *
 *
 * */


#include<stdio.h>

int main()
{
	int ch;
	int n=0;	//用于计数，控制换行
	
	while((ch=getchar())!=EOF)
	{

	
		if(ch>=' ')
		{
			printf("%2c %3d | ",ch,ch);
			n++;
		}	
		else
		{
			n++;
			if(ch=='\n')
			{
				printf("\\n %3d | ",ch);
				printf("\n");
			}
			else if(ch=='\t')printf("\\t %3d | ",ch);
			else 
			{
				printf("^%c %3d | ",ch+64,ch);
			}
		}

		if(ch!='\n' && n%10==0)printf("\n");

	}








	
	return 0;
}
