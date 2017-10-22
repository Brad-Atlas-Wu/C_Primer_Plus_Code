#include"head.h"
void list(void)
{
	printf("*******************\n");
	printf("请问您选择的酒店是(q退出)：\n");
	printf("a)假日酒店￥400  b)花园酒店￥650\nc)白天鹅宾馆￥1000  d)香格里拉大酒店￥1500\n");
	printf("*******************\n");
}

int days(void)
{
	int time=-1;
	int stat;	//用来记录是要结束程序还是返回上一级
	printf("请输入您在居住的天数：(输入b返回上一级（重新选择酒店）,输入q退出)\n");
	while(scanf("%d",&time)!=1 || time<0 )
	{	
		if((stat=getchar())=='q')return -1;	//代表结束程序
		else if(stat=='b')return -2;		//代表返回上一级
		printf("输入错误，请重新输入您居住的天数（b返回上一级，q退出）\n");
	}
	return time;
}

long count(int days,int price)
{
	long sum=0;
	for(int i=0;i<days;i++)
	{
		sum+=price;
		price*=RATE;
	}
	printf("您一共需要支付：%ld元\n",sum);
}
