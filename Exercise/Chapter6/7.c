#include<stdio.h>
#include<string.h>

int main()
{	
	char s1[15];
	printf("Please enter a string :\n");
	scanf("%s",s1);
	for(int i=strlen(s1)-1;i>=0;i--)
	{
		printf("%c",s1[i]);
	}
	printf("\n");
	
	return 0;
}
