#include<stdio.h>
#include<ctype.h>

int main()
{
	int ch;
	int nupper,nlower;	//upper 和lower的个数
	nupper=nlower=0;
	
	while((ch=getchar())!=EOF)
	{
		putchar(ch);
		if(islower(ch))nlower++;
		else if(isupper(ch))nupper++;
	}
	printf("有%d个大写字母，和%d个小写字母\n",nupper,nlower);
	return 0;

}
