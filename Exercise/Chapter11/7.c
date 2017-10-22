#include<stdio.h>
#define SIZE 15
#define SIZE2 30
char * mystrncpy(char *,char *, int);
int main(void)
{
	char stra[SIZE]="I am brad!";
	char strb[SIZE2];
	char * p =strb;
	char * pc;
	char ch;
	while((ch=getchar())!='\n')
	{
		*p++=ch;
	}
	*p='\0';
	puts(strb);
	puts(stra);
	pc=mystrncpy(stra,strb,SIZE);	
	puts(pc);
	return 0;
}

char * mystrncpy(char * target, char * source,int limit)
{
	int n=0;
	char * pc=target;
	while(n++<limit-1 && *source!='\0')*target++=*source++;
	return pc;
}
