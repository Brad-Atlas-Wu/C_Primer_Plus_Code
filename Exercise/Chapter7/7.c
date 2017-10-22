#include<stdio.h>
#define INCOME_P_H 1000		//每小时收入
#define BASE_RATE 0.15
#define EXTRA_RATE 0.2
#define REST_RATE 0.25
#define TAX_BASE BASE_RATE*300.0
#define TAX_EXTRA EXTRA_RATE*150.0+TAX_BASE
int main()
{


	double time;	//每周工作时间
	double salary;
	double tax;
	printf("How many hours do you work per week?\n");
	scanf("%lf",&time);
	if(time<=40.0)
	{
		salary=1000.0*time;
	}
	else
	{
		salary=1000.0*40.0+(double)(time-40)*1.5*1000.0;
	}
	
	if(salary<=300.0)
	{
		tax=BASE_RATE*salary;
	}
	else if (salary<=450.0)
	{
		tax=TAX_BASE+(salary-300.0)*EXTRA_RATE;
	}
	else
	{
		tax=TAX_EXTRA+(salary-400.0)*REST_RATE;
	}
	printf("您的总工资是：$%.2lf 税金是：$%.2lf  净收入是：$%.2lf\n",salary,tax,salary-tax);
	return 0;

}

