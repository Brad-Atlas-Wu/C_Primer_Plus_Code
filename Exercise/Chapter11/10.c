#include<stdio.h>
#define SIZE 50
void mob_blank(char * str);
int main(void)
{
	char str[SIZE];
	printf("请输入一个字符串：\n");
	fgets(str,SIZE,stdin);
	while(*str!='\n')
	{
		mob_blank(str);
		fputs(str,stdout);
		fgets(str,SIZE,stdin);
	}
	return 0;
}

void mob_blank(char * str)
{
	char * pc=str;
	while(*str!='\0')
	{
		if(*str!=' ')*pc++=*str;
		str++;
	}
	*pc='\0';
}
