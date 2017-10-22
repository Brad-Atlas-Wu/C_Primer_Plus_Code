/*文件包含了3个子函数：
 * 	set_mode(int mode)	把文件pe12-2b.c中的mode传递给本文件
 *	get_info()	根据mode值提示用户输入相应的数据，并将其存储到文件作用域变量
 *	show_info()	根据设置的模式计算并且显示油耗
 *
 *	文件中定义了三个内部链接的文件作用域变量，mode(模式),distance(距离),consumption(油耗)
 *		用以在文件中传递这三个参数的值。（这样做就省去了在函数中通过参数传递的过程）
 * 	*/

#include<stdio.h>	//函数需要有输入和输出

static int mode=0;	//开始给个默认值，代表是使用英制的
static double distance,consumption;

/*把文件pe12-2b.c中的mode传递给本文件*/
void set_mode(int choice)
{
	if(choice==0 || choice==1)mode=choice;	//如果mode输入正确，将main函数中获得的mode,传递给本文件的mode
	else if(mode==0)printf("Invalid mode specified. Mode 0(Metric mode)used\n");
	else if(mode==1)printf("Invalid mode specified. Mode 1(US)used\n ");
}

/*根据mode值提示用户输入相应的数据，并将其存储到文件作用域变量*/
void get_info(void)
{
	if(mode==0)
	{
		printf("Enter distance traveled in kilometers: ");
		while(scanf("%lf",&distance)!=1 || distance<0)
		{
			printf("Invalid input! \nAgain,Enter distance traveled in kilometers\n");
			if(distance<0);
                        else while(getchar()!='\n')continue;

		}
		
		printf("Enter fuel consumed in liters: ");
		while(scanf("%lf",&consumption)!=1 || consumption<0)
		{
			printf("Invalid input! \nAgain,Enter fuel consumed in liters:\n");
			if(consumption<0);
                        else while(getchar()!='\n')continue;

		}
	}
	else if(mode==1)
	{
		printf("Enter distance traveled in miles: ");
                while(scanf("%lf",&distance)!=1 || distance<0)
                {
                        printf("Invalid input! \nAgain,Enter distance traveled in miles\n");
			if(distance<0);
                        else while(getchar()!='\n')continue;

                }

                printf("Enter fuel consumed in gallons: ");
                while(scanf("%lf",&consumption)!=1 || consumption<0)
                {
                        printf("Invalid input! \nAgain,Enter fuel consumed in gallons:\n");
			if(consumption<0);
                        else while(getchar()!='\n')continue;

                }

	}
}

/*根据设置的模式计算并且显示油耗*/
void show_info(void)
{
	if(mode==0)
	{
		printf("Fuel consumption is %lf liters per 100 km\n\n",consumption/distance*100.0);
	}
	else if(mode==1)
	{
		printf("Fuel consumption is %lf miles per gallon\n\n",distance/consumption);
	}
}


