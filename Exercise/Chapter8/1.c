#include<stdio.h>

int main()
{
	int nc=0;
	while(getchar()!=EOF)
		nc++;
	printf("文件中一共有%d个字符\n",nc);
	return 0;
}
