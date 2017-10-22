/*
 *任务：重写程序清单12.4，要求不使用全局变量。
		下面程序直接将unit作为返回值
		还可以用指针作为函数参数传递值
		还可以直接在main中完成整个操作，不调用子函数
 * */
#include<stdio.h>
int critic();
int main(void)
{
	int units;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d",&units);
	while(units!=56)units=critic();
	printf("You must have look it up!\n");
	return 0;
}

int critic()
{
	int units;
	printf("No luck,my friend. Try again.\n");
	scanf("%d",&units);
	return units;
}
