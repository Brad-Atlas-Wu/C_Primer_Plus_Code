/*任务： 定义两个结构，
 * 	结构1： 成员1：社会保险号	成员2： 结构2
 * 	结构2： 成员1：first name 	成员2：middle name 	成员3：last name
 * 	初始化并打印结构信息
 *
 * 
 * 知识点：1.结构的嵌套使用
 * 	   2. 结构传值
 *
 * 算法：
 * 	定义结构2
 * 	定义结构1
 * 	初始化结构
 *
 * 	定义子函数，参数为结构整体
 * 		打印first name和last name
 * 		如果没有中间名，就不打印中间名
 * 		如果有中间名，打印中间名首字母，在后面加.
 * */

#include<stdio.h>
#include<string.h>
#define LEN 20
#define SIZE 5	//数组上限
struct name_def{
	char fir_name[LEN];
	char mid_name[LEN];
	char last_name[LEN];
};

struct data{
	int number;
	struct name_def name;
};

void output(struct data);//用于输出结构信息，参数位结构指针
int main(void)
{
	//定义并初始化结构数组
	struct data array[SIZE]={
		{1001,{"Brad","Atlas","Wu"}},
		{1002,{"Clara","","Lin"}},
		{1003,{"Stephen","","Job"}},
		{1004,{"Bruce","Dragon","Lee"}},
		{1005,{"Jack","Kongfu","Chen"}}
			
	};

	for(int i=0;i<SIZE;i++)
	{
		output(array[i]);
	}
	return 0;
}

void output(struct data pd)
{
		printf("%s %s",pd.name.fir_name,pd.name.last_name);
		if(strcmp(pd.name.mid_name,"")!=0)
			printf(" %c.",pd.name.mid_name[0]);
		printf(" -- %d\n",pd.number);
}
