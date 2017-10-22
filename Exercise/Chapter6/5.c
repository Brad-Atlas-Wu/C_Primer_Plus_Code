/*
 基于用户输入的字母打印一个字母金字塔。
	我观察到这个金字塔是以中间一列为对称的。
	所以我的做法是先正着打印一遍字母，再倒着打印一遍字母，这样就输出了一行。
*/

#include<stdio.h>

int main()
{
	char note;
	int i,j,k;
	printf("Please enter a letter to create your pyramid:\n");
	scanf("%c",&note);

	for(i=0;i<=note-'A';i++)
	{	
		for(k=note-'A';k>i;k--)		//输出每行之前的空格
			printf(" ");
	
		char c1;		
		for(j=0;j<i+1;j++)	//正着打印一遍字母
		{
			c1='A'+j;
			printf("%c",c1);
		}
	        for(j=0;j<i;j++)	//倒着打印字幕
                {
                        printf("%c",--c1);
                }

		printf("\n");
	}
	return 0;
}
