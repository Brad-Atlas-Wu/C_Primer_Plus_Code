#include<stdio.h>
void getdata(int n,int m,double (*)[n]);	//获取数组
double line_ave(int n,int m,double *);	//求取并返回每行的平均数
double ave(int n,int m,double (*)[n]);	//计算所有数据的平均值
void find_max(int n,int m,double (*)[n]);	//找出最大值

int main(void)
{
	int m=3;
	int n=5;
	double arr[m][n];
	
	getdata(n,m,arr);

	printf("输入的数组为:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%.2lf ",arr[i][j]);
		}
	printf("\n");
	}
	
	for(int i=0;i<m;i++)
	{
		printf("第%d行的平均值是：%lf\n",i+1,line_ave(n,m,arr[i]));	
	}

	printf("全部数据的平均值是:%lf\n",ave(n,m,arr));
	
	find_max(n,m,arr);
	return 0;
}

void getdata(int n,int m,double (* p)[n])
{
	printf("请输入一个3乘5的数组\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lf",*(p+i)+j);
		}
	}

}

double line_ave(int n,int m,double * p)
{
	double total=0.0;
	for(int i=0;i<n;i++)
	{
		total+=*(p+i);
	}
	return total/n;
}

double ave(int n,int m,double (* p)[n])
{
	double total=0.0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			total+=*(*(p+i)+j);
		}
	}
	return total/(m*n);
}

void find_max(int n, int m,double a[][n])
{
	double max=0.0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>max)max=a[i][j];
		}
	}

	printf("数组中的最大值是：%lf\n",max);
}
