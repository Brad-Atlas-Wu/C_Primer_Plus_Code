//函数用三个函数将源数组内容复制给目标数组内容
//	第一个函数用数组表示法
//	第二个函数用指针表示法
//	第三个函数用指向开头的指针和指向结束后面的指针
#include<stdio.h>
#define SIZE 5
void copy_arr(double *,double *,int);
void copy_ptr(double *,double *,int);
void copy_ptrs(double *,double *,double *);
void output(double *,int);

int main(void)
{
	double source[SIZE]={1.1,2.2,3.3,4.4,5.5};
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];
	copy_arr(target1,source,SIZE);
	copy_ptr(target2,source,SIZE);
	copy_ptrs(target3,source,source+SIZE);
	return 0;
}

void copy_arr(double a[SIZE],double b[SIZE],int n)
{
	for(int i=0;i<n;i++)a[i]=b[i];
	output(a,n);
}


void copy_ptr(double * t, double * s, int n)
{
	while(n--)
	{
		printf("%lf ",*t++=*s++);			//这里之前我写的是*t++=*s++,然后再output(t,n)
	}							// 可是这样的结果是什么？
	printf("\n");						//  结果是在开始打印的时候，t指针指向的位置已经是数组
								//  的结尾了！！所以打印错误！
}   								//	因此要注意在操作过程中指针位置的移动！！！
								
void copy_ptrs(double * t,double * pstart,double * pend)
{
	while(pstart<pend)
	{
		*t=*pstart++;
		printf("%lf ",*t);
		t++;
	}
	printf("\n");
}

void output(double * p,int n)
{
	while(n--)printf("%lf ",*p++);
	printf("\n");
}
