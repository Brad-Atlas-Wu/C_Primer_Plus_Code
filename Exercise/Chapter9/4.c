/*
 *	任务：计算两个数字的调和平均数
 *
 * */


#include<stdio.h>
double ave(double,double);
int main(void)
{	
	double n1,n2;
	printf("Please enter 2 double:\n");
	scanf("%lf %lf",&n1,&n2);
	printf("The ave of %lf and %lf is %lf\n",n1,n2,ave(n1,n2));
	return 0;

}


double ave(double a, double b)
{
	return 1.0/((1.0/a+1.0/b)/2.0);
}
