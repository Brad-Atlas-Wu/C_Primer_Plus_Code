/*
P214	任务：用户循环输入句子，计算单词数，字符数和行数
	
	用户循环输入
	每次输入一个非结束字符，则字符数+1
	遇到换行符行数+1
	
	开始状态为0
	遇到第一个字母状态变为1
	遇到空格不变
	
	状态为1时遇到空格单词数加1，状态变成0

	补充： 后来发现之前的设计有一个问题：那就是如果当结束符号@没有在新行而是连在最后一个单词后面的时候
		那么单词数量和行数就会算少一个。
		为此，加了一个变量int last记录上一个字符，如果@的上一个字符是换行符，则计数正确；如果上一个字符不是换行符，那么行数就要加一；如果上一个字符不是任何类型的空符（单词分隔符），那么单词数目加一(当然需要另一个变量来记录是否为空符)
*/


#include<stdio.h>
#include<ctype.h>
#define IN 1
#define OUT 0
int main()
{
	char ch;
	int nline,nletter,nword;
	int last,last2;	//记录结束符的上一个输入是不是换行,空符
	_Bool state;
	nline=nletter=nword=0;
	state=OUT;
	
	while((ch=getchar())!='@')
	{
		if(!isspace(ch))
		{
			nletter++;
			last2=0;	//不是空符
		}
		else
			last2=1;	//是空符
		if(ch=='\n')
		{
			nline++;
			last=1;		//表明是换行
		}
		else
			last=0;		//表明不是换行
	
		if(state==IN && isspace(ch))
		{
				nword++;
				state=OUT;
		}
		else if(state==OUT && !isspace(ch) )
		{
			state=IN;
		}
	}
	if(last==0 && ch=='@')
	{	
		nline++;	//如果@上一个符号不是换行符，那么就行数加一
	}
	if(last2==0 && ch=='@' )
		nword++;
	printf("There are %d words, %d lines and %d letters\n",nword,nline,nletter);	
	
	return 0;
}
