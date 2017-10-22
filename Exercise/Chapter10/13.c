#include<stdio.h>
#define M 3
#define N 5
void getdata(double (*)[N]);	//获取数组
double line_ave(double *);	//求取并返回每行的平均数
double ave(double (*)[N]);	//计算所有数据的平均值
void find_max(double (*)[N]);	//找出最大值

int main(void)
{
	double arr[M][N];
	
	getdata(arr);

	printf("输入的数组为:\n");
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%.2lf ",arr[i][j]);
		}
	printf("\n");
	}
	
	for(int i=0;i<M;i++)
	{
		printf("第%d行的平均值是：%lf\n",i+1,line_ave(arr[i]));	
	}

	printf("全部数据的平均值是:%lf\n",ave(arr));
	
	find_max(arr);
	return 0;
}

void getdata(double (* p)[N])
{
	printf("请输入一个3乘5的数组\n");
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%lf",*(p+i)+j);
		}
	}

}

double line_ave(double * p)
{
	double total=0.0;
	for(int i=0;i<N;i++)
	{
		total+=*(p+i);
	}
	return total/N;
}

double ave(double (* p)[N])
{
	double total=0.0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			total+=*(*(p+i)+j);
		}
	}
	return total/(M*N);
}

void find_max(double a[][N])
{
	double max=0.0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(a[i][j]>max)max=a[i][j];
		}
	}

	printf("数组中的最大值是：%lf\n",max);
}
