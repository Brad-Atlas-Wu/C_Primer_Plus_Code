/*
 *	在读到EOF之前循环读取输入，报告大写字母数，小写字母数，标点符号数，数字数量还有单词数量
 *
 *	while（输入不为EOF）判断并累加大写字母数，小写字母数，标点符号数，数字数量
 *
 *	并且计算单词数量
 *		开始状态在单词外
 *		if(在单词外且遇到有效字符)单词数加1，标记为单词内
 *		else if(遇见分隔符)标记在单词外
 *		
 * */

#include<stdio.h>
#include<ctype.h>
#define IN 1
#define OUT 0
int main(void)
{
	int ch;		//因为要判断EOF,所以把字符定义为int类型
	int stat=OUT;	
	int n_upper,n_lower,n_digit,n_word,n_punct;	//n_punct累计标点数量
	n_upper=n_lower=n_digit=n_punct=n_word=0;	//初始化数量
	while((ch=getchar())!=EOF)
	{	
		putchar(ch);
		if(isupper(ch))n_upper++;
		else if(islower(ch))n_lower++;
		else if(isdigit(ch))n_digit++;
		else if(ispunct(ch))n_punct++;
		
		if(stat==OUT && !(ispunct(ch) || isspace(ch)))	//在单词外遇见有效字符，表示遇见单词
		{
			n_word++;
			stat=IN;
		}
		else if(ispunct(ch) || isspace(ch))stat=OUT; 	//在单词中遇见分隔符，代表一个单词结束
		
	}
	putchar('\n');
	printf("一共有%d个大写字母，%d个小写字母，%d个标点符号，%d个数字，%d个单词\n",n_upper,n_lower,n_punct,n_digit,n_word);
	return 0;
}
