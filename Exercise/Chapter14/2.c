/* 任务：用户输入一个月份,日期和年，程序输出这一年到这一天为止的天数。月份可以是月份名，月份号或者缩写
 *
 * 知识点：1.结构的定义、初始化、访问
 * 	   2. 字符串赋值，对比
 * 	   3.枚举类新
 *
 * */

#include<stdio.h>
#include<string.h>
#define LEN 15
//声明结构模板
struct month{
	char name[LEN];
	char abbr[3];
	int day;
	short num;
};

int main(void)
{
	struct month arr_mon[12];//定义结构数组
	//初始化数组的月天数和月号
	for(int i=0;i<12;i++)
	{
		if(0==i || 2==i || 4==i || 6==i || 7==i || 9==i || 11==i)
		{
			arr_mon[i].day=31;
		}
		else if(i==1)
			arr_mon[i].day=28;
		else
			arr_mon[i].day=30;

		arr_mon[i].num=i+1;
	}

	//初始化月份名/缩写名
	char temp_name[12][LEN]={"January","Feburary","March","April","May","June","July","Augest","September","October","November","December"};
	char temp_abbr[12][3]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	for(int i=0;i<12;i++)
	{
		strcpy(arr_mon[i].name,temp_name[i]);
		strcpy(arr_mon[i].abbr,temp_abbr[i]);
	}
	//利用枚举变量提高可读性
	enum month{jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

	char month_choice[LEN];
	printf("Please enter a month name:\n");
	while((scanf("%s",month_choice)==1) && (month_choice[0]!='q'))
	{	
		long total_days=0;
		int i;
		for(i=jan;i<=dec;i++)
		{
			if((strcmp(month_choice,arr_mon[i].name)==0) || (strcmp(month_choice,arr_mon[i].abbr)==0))
				break;
			total_days+=arr_mon[i].day;
		}
		if(i==12)
		{
			printf("Cannot find month %s\n",month_choice);
			printf("Please enter the month again(q to quit):\n");
			continue;
		}
		else
		{
			printf("%ld days in total\n\n",total_days);
			printf("Please enter the next month num(q to quit)\n");
		}

	}
	return 0;
}
