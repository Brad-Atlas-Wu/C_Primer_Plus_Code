/*任务：用户输入一个月份号，程序输出这一年到这一个月为止的总天数
 *
 * 知识点：结构的定义、初始化、访问
 * */

#include<stdio.h>
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

	short choice;
	printf("Please enter a month num:\n");
	while(scanf("%d",&choice)==1)
	{	
		long total_days=0;
		for(int i=0;i<choice;i++)
		{
			total_days+=arr_mon[i].day;
		}
		printf("%ld days in total\n\n",total_days);
		printf("Please enter the next month num(q to quit)\n");
	}

	return 0;
}
