/*
 *	任务：统计文件单词的平均字母数。
 *	
 *	伪代码：
 *	输入字符，直到文件结尾
 *	状态标记在单词外
 *	如果在单词外
 *		如果遇到字符
 *			标记在单词内，单词数量加1
 *	如果在单词内
 *		计算字母数
 *		如果遇到分隔符
 *			标记为在单词外
 *
 *	计算单词的字母平均数
 *
 * */


#include<stdio.h>
#include<ctype.h>
#define IN 1
#define OUT 0

int main()
{
	int ch;
	int nword=0;		//储存文件中的单词总数
	int nletter=0;		//储存字母数
	_Bool state=OUT;
	while((ch=getchar())!=EOF)
	{
		if(state==OUT)
		{
			if(isalpha(ch))
			{
				state=IN;
				nword++;		
			}
			
		}
		else
		{
			nletter++;
			if(isblank(ch) || ispunct(ch))
			{
				state=OUT;
			}	
		}	
	}
	printf("there are %d words,and %d letters in total\n",nword,nletter);
	printf("文件中单词的平均字母数是：%.2lf\n",(double)nletter/(double)nword);
	return 0;
}
