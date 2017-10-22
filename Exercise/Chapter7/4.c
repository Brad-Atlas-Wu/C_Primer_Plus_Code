/*
	程序要求首先循环读取，然后用！替换句号，用！！代替！ ，并输出替换的次数
	while读取
	如果遇到句号，替换，次数加一
	如果遇到 感叹号，替换，次数加一
	其他时候正常输出
*/

#include<stdio.h>

int main()
{
	char ch;
	int n=0;
	while((ch=getchar())!='#')
	{
		if(ch=='.'){putchar('!');n++;}
		else if(ch=='!'){putchar(ch);putchar(ch);n++;}
		else putchar(ch);
	}
	printf("替换了%d次\n",n);
	return 0;
}
