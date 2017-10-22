/*
	本程序和程序7.c的主要区别在于要通过用户输入来选择用户的工资等级
	
	输出工资等级表
	用户输入一个数字
		如果数字为1-4，根据数字确定用户的工资等级，继续下面的程序
		如果数字为5，结束程序
		如果输入为其它范围数字或者非法输入，那么重新打印工资登记表，直到输入合法再继续程序
	
*/

#include<stdio.h>
#define INCOME_P_H_1 8.75		//每小时收入,最后的数字为等级
#define INCOME_P_H_2 9.33		
#define INCOME_P_H_3 10.00
#define INCOME_P_H_4 11.20
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
	int n; 		//记录用户选择的数字
	double choice;		//记录用户选择数字所对应的工资等级
	
		
	/**输出选择列表**/
	printf("************************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf(" 1)$8.75/hr\t\t\t 2)$9.33/hr\n 3)$10.00/hr\t\t\t 4)$11.20/hr\n 5)quit\n ");
	printf("************************************************************************\n");	

	while(scanf("%d",&n)==1)
	{	
		if(n<=5 && n>=1)break;
		else 
		{
			printf("************************************************************************\n");
        		printf("Enter the number corresponding to the desired pay rate or action:\n");
        		printf(" 1)$8.75/hr\t\t\t 2)$9.33/hr\n 3)$10.00/hr\t\t\t 4)$11.20/hr\n 5)quit\n ");
       			printf("************************************************************************\n");
		}

	}

		

	switch(n)
	{
		case 1:choice=INCOME_P_H_1;break;
		case 2:choice=INCOME_P_H_2;break;
		case 3:choice=INCOME_P_H_3;break;
		case 4:choice=INCOME_P_H_4;break;
		case 5:return 0;
		default: return 0;
	}




	printf("How many hours do you work per week?\n");
	scanf("%lf",&time);
	if(time<=40.0)
	{
		salary=choice*time;
	}
	else
	{
		salary=choice*40.0+(double)(time-40)*1.5*choice;
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

