/*
 *	这道题目主要的难点在于：1.要根据单词的数量分配空间
 *				2.要给每个单词都分配刚刚好的内存空间
 *	考察了动态分配内存，也显示了动态分配的优势：节约空间
 *	
 *	程序的算法结构详见 C primer Plus/习题详解		
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ** getword(int nword);

int main(void)
{
	int nword;	//记录用户希望输入的单词数量
	char ** p_word;		//指向指针的指针，用于储存每个单词（或者说字符串数组）的首元素地址
	printf("How many words do you wish to enter: ");
	scanf("%d",&nword);
	
	p_word=getword(nword);	//最后返回的也是一个指向一个指向char类型指针的指针
	
	for(int i=0;i<nword;i++)printf("%s\n",p_word[i]);	//按单词（字符串数组）进行输出
	return 0;
}

char ** getword(int nword)
{
	int ch;		//用于临时记录输入的字符
	char temp[50];	//用于临时储存一个单词（因为这之前还不知道单词有多长，无法准确地动态分配，所以需要临时储存这个单词）
	int i=0;	//临时数组temp[]的下标
	int j=0;	//双重指针p_word的下标
	char ** p_word;	//指向每个单词（字符串数组）的首元素地址，指向指针的指针
	char * pc;	//储存单词首元素的地址
	p_word=malloc(nword*sizeof(char *));	//按照用户希望输入的单词个数，动态分配内存
	while((ch=getchar())!='@')
	{
		if(ch==' ' || ch=='\t')
		{
			temp[i]='\0';
			pc=malloc((i+1)*sizeof(char));	//到了单词的结尾，知道单词的长度，这时候为这个单词动态分配空间
			i=0;
			strcpy(pc,temp);	//把临时数组的内容复制到刚刚给单词分配的空间中
			if(j<nword)
			{
				p_word[j]=pc;	//把刚刚分配给单词的内存的地址赋给p_word相应的元素
				j++;
			}
		}
		else
		{
			temp[i]=ch;
			i++;	
		}
	}
	return p_word;
}
