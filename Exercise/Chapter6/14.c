/*
 	程序设置两个数组【8】，第一个数组记录用户输入的值，第二个数组保存第一个数组的累计和
	变量：两个double类型数组[8]，int i控制数组下标
	用while来控制用户循环输入
	
	
 */
#include<stdio.h>

int main()
{
	double num[8];
	double accu[8];
	int i=0;
	while(i<8 && (scanf("%lf",&num[i])==1))
		i++;
	accu[0]=num[0];
	for(i=1;i<8;i++)
	{
		accu[i]=accu[i-1]+num[i];
	}	
	
	for(i=0;i<8;i++)
	{
		printf("%lf ",num[i]);
	}
	printf("\n");
	
	for(i=0;i<8;i++)
	{
		printf("%lf ",accu[i]);
	}
	printf("\n");
	return 0;
}
