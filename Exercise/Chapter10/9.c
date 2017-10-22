#include<stdio.h>
void copy(int,int,double a[*][*],double b[*][*]);
void output(int,int,double a[*][*]);
int main(void)
{
	int m=3;
	int n=5;
	double source[m][n];
	double target[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			source[i][j]=2*i+j;		//注意：变长数组不能在定义的同时赋值！！！
		}
	}
	
	copy(m,n,target,source);
	printf("原数组：\n");
	output(m,n,source);
	printf("\n");
	printf("复制后数组：\n");
	output(m,n,target);
	return 0;
}

void copy(int m,int n, double target[m][n],double source[m][n])		//拷贝
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			target[i][j]=source[i][j];
		}
	}
}


void output(int m,int n,double source[m][n])		//输出
{
	for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%lf ",source[i][j]);
                }
		printf("\n");
        }

}
