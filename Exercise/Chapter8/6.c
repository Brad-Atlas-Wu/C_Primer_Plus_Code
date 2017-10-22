#include<stdio.h>
char get_first();
int main()
{	
	char ch;
	ch=get_first();
	putchar(ch);
	printf("\n");
	return 0;
}


char get_first()
{
	char ch;
	ch=getchar();
	while(isspace(ch))
	{
		ch=getchar();
	}
	return ch;
}
