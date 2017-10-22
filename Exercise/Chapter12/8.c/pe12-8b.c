/*本文件包含了主调函数的两个子函数：
 * 	1. make_array(int size ,int value). 根据主调函数传递的两个值：size(大小)，value（值）来定义并且初始化数组
 * 	2. show_array(const int arr[],int size)打印数组
 * 	*/
#include<stdlib.h>
#include<stdio.h>

int * make_array(int size,int value)
{
	int * pa;
	pa=calloc(size,sizeof(int));
	if(pa)
		for(int i=0;i<size;i++)pa[i]=value;	
	return pa;
}

void show_array(const int arr[],int size)
{	
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
		if((i+1)%8==0)printf("\n");	//每打印8个换行一次
	}
	if((i+1)%8!=0)printf("\n");	//在最末尾换行
}
