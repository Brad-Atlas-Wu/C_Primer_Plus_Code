/*
 *	任务：反序输出命令行参数
 *
 *	考察的是利用main的参数agrc和char **agrv
 *
 *	if(agrc<2，证明没有参数)
 *	else 逆序输出
 *
 *	疑问：这个地方，但用户没有输入参数的时候仅仅是提示完就结束了。
 *		那么能不能再循环调用main函数自身，让用户重复输入呢？
 * */
#include<stdio.h>
int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("请输入参数！\n");
	}
	else
	{
		for(int i=argc-1;i>0;i--)
		{
			fputs(argv[i],stdout);
			printf(" ");
		}
	printf("\n");
	}
	return 0;
}

