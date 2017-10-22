/*
	只接受正整数输入，输出所有小于或等于该数字的素数
	
	让用户输入一个正整数n
	把n作为循环上限，传递循环值给子函数
	子函数判断素数，如果是素数，就打印
	

 */

#include<stdio.h>
void prim(int);
int main()
{
	int n;
	printf("Please enter an int:\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		prim(i);
	printf("\n");	
	return 0;
}

void prim(int n)
{
	int t=0;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			t++;
			break;
		}
	}
	if(t==0)printf("%d ",n);
}
