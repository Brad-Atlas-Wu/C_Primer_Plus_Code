/* 任务：用户输入一个月份,日期和年，程序输出这一年到这一天为止的天数。月份可以是月份名，月份号或者缩写
 *
 * 知识点：1.结构的定义、初始化、访问
 * 	   2. 字符串赋值，对比
 * 	   3.枚举类新
 *
 * 问题：判断用户输入的月份号那里，应该有更好的方法
 *
 * */

#include<stdio.h>
#include<string.h>
#define LEN 15
//声明结构模板
struct month{
	char name[LEN];
	char abbr[4];
	int day;
	short num;
};

int main(void)
{
	struct month arr_mon[12];//定义结构数组
	int date;
	int year;
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

	//初始化月份名
	char temp_name[12][LEN]={"January","Feburary","March","April","May","June","July","Augest","September","October","November","December"};
	char temp_abbr[12][4]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	char cmp_num[12][3]={"1","2","3","4","5","6","7","8","9","10","11","12"};
	for(int i=0;i<12;i++)
	{
		strcpy(arr_mon[i].name,temp_name[i]);
		strcpy(arr_mon[i].abbr,temp_abbr[i]);
	}
	//利用枚举变量提高可读性
	enum month{jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
	/*上面是各种混乱的初始化*/


	char month_choice[LEN];
	printf("Please enter a month name:\n");
	while((scanf("%s",month_choice)==1) && (month_choice[0]!='q'))
	{	
		printf("Please enter date of this month:\n ");
		if(scanf("%d",&date)!=1)
		{
			printf("ERROR!");
			break;
		}
		printf("Enter the year:\n");

		if(scanf("%d",&year)!=1)
		{
			printf("ERROR!");
		       	break;
		}

		long total_days=0;
		int i;
		for(i=jan;i<=dec;i++)
		{
			if((strcmp(month_choice,arr_mon[i].name)==0) || (strcmp(month_choice,arr_mon[i].abbr)==0) || (strcmp(month_choice,cmp_num[i])==0))
				break;
			total_days+=arr_mon[i].day;

		}
		if(i==12)
		{
			printf("Cannot find %s\n",month_choice);
			return 1;
		}
		else
		{
			printf("It's the %ld days in %d \n\n",total_days+date,year);
			printf("Please enter the next month num(q to quit)\n");
		}

	}
	printf("Bye!");
	return 0;
}
