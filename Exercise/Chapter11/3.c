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
	scanf("%s",str);
	return str;
}

