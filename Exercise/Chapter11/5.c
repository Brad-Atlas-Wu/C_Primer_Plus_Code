#include<stdio.h>
#define SIZE 50
char * str_chr(char *,char);
int main(void)
{
	char str[SIZE]="Hello,I am brad!";
	char ch;
	char * pc;
	printf("Please enter a char:\n");
	while((ch=getchar())!='@')
	{
		pc=str_chr(str,ch);
		if(pc)printf("The adress:%p\n%c\n",pc,*pc);
		else printf("Can not find!\n");
		while(getchar()!='\n')continue;
		printf("Please enter next char:\n");
		
	}
	return 0;
}


char * str_chr(char * str,char ch)
{
	while(*str!='\0')
	{
		if(*str==ch)return str;
		str++;
	}	
	return NULL;
}
