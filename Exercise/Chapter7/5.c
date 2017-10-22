#include<stdio.h>

int main()
{
	char ch;
	int n=0;
	while((ch=getchar())!='#')
	{
		switch(ch)
		{
			case'.':putchar('!');n++;break;
			case'!':putchar(ch);putchar(ch);n++;break;
			default:putchar(ch);break;
		}
	}
	printf("替换了 %d 次\n",n);
	return 0;
}
