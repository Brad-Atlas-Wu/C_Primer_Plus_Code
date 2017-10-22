#include<stdio.h>
#define YEAR 5
#define MONTH 12
int main(void)
{
	float rain[YEAR][MONTH]=
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

//求每年的降水量和年平均降水量
	float subtot;
	float total=0.0;
	for(int year=0;year<YEAR;year++)
	{
		subtot=0.0;
		for(int month=0;month<MONTH;month++)
		{
			subtot+=*(*(rain+year)+month);
		}
		printf("%d\t%f\n",2010+year,subtot);
		total+=subtot;
	}
	printf("年平均降水量是:%f\n",total/YEAR);

//求五年中每月平均降水量
	int yue=1;
	for(int month=0;month<MONTH;month++)
	{
		total=0.0;
		for(int year=0;year<YEAR;year++)
		{
			total+=*(*(rain+year)+month);
		}
		printf("%d月的平均降水量是：%f\n",yue++,total/YEAR);
	}
}	
