#include<stdio.h>
double count_pow(double,int);
int main()
{	
	double x;
	int xpower;
	printf("请输入一个数字以及他的正/负整数次幂:\n");
	scanf("%lf %d",&x,&xpower);
	printf("%.2lf的%d次幂是%lf\n",x,xpower,count_pow(x,xpower));
	return 0;
}

double count_pow(double x, int a)
{
	int i;
	double pow=1.0;
	if(a==0)
	{
		if(x==0)printf("0的0次方未定义，暂定为1\n");

		pow=1.0;	
	}
	else if(x==0)
	{
		pow=0.0;
	}
	else if(a>0)
	{	
		for(i=a;i>0;i--)pow*=x;
	}
	else
	{
		pow=1.0/count_pow(x,-a);
	}
	return pow;
}
