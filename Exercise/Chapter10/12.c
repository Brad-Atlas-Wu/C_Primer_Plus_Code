#include<stdio.h>
#define YEAR 5
#define MONTH 12
void year_fall(float (*)[MONTH]);
void month_fall(float (*)[MONTH]);
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
	year_fall(rain);
	month_fall(rain);
	
	return 0;
}

void year_fall(float rain[][MONTH])
{	
	float total=0.0;
	for(int year=0;year<YEAR;year++)
	{
		float subtot=0.0;
		for(int month=0;month<MONTH;month++)
		{
			subtot+=rain[year][month];
		}
		printf("%d年的降水量是：%f\n",2010+year,subtot);
	total+=subtot;
	}	
	printf("年平均降水量是：%f\n",total/YEAR);
}

void month_fall(float rain[][MONTH])
{

	for(int month=0;month<MONTH;month++)
	{	
		float subtot=0.0;
		for(int year=0;year<YEAR;year++)
		{
			subtot+=rain[year][month];	
		}
		printf("%d月平均降水量: %f\n",month+1,subtot/YEAR);
	}
	
}
