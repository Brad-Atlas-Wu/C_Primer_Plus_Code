#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch;
	int n=0;
	while((ch=getchar())!='#')
	{	
		if(isspace(ch)){n=0;continue;}
		n++;
		printf("%c:%d",ch,ch);
		printf("%c",n%8==0?'\n':'\t');
	}
	return 0;
}
