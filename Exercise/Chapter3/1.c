#include<stdio.h>

int main()
{
	int a;
	unsigned int b;
	a=2147483647;
	b=4294967295;
	printf("int的最大正数：%d\n",a);
	printf("int的最小负数：%d\n",-a-1);
	printf("int上溢1：%d\n",a+1);
	printf("int下溢1: %d\n",-a-2);
	

	printf("unsigned int 的最大值%u\n",b);
	printf("unsigned int 上溢%u\n",b+1);
	return 0;	
}
	
