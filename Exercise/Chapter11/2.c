#include<stdio.h>
#define SIZE 40
char * get_str(char * );
int main(void)
{
	char *pc;
	char str[SIZE];
	pc=get_str(str);
	printf("The adress:%p\n%s\n",pc,pc);
	return 0;
}

char * get_str(char * str)
{
	char ch;
	int n=0;
	while((ch=getchar())!='\n' && ch!=' ' && ch!='\t' && n<10)
	{
		*(str+n)=ch;
		n++;
	}
	*(str+n)='\0';
	while(getchar()!='\n')continue;
	return str;
}

