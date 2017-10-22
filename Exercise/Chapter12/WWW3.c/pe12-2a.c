/*	**本题目是在题目2的基础上进行修改，要求只使用自动变量，那么就是在数值通过函数的参数进行d传递。**
 *参考答案的做法是，简单粗暴地把原本定义的外部链接的文件作用域变量直接都放在main中，然后~很多操作都在main中完成
	而我的做法仍然是用函数来完成，把变量通过参数传递，这样程序模块化更加清晰

 *
 * 文件包含了3个子函数：
 * 	set_mode(int mode)	把文件pe12-2b.c中的mode传递给本文件
 *	get_info()	根据mode值提示用户输入相应的数据，并将其存储到文件作用域变量
 *	show_info()	根据设置的模式计算并且显示油耗
 *
 * 	*/

#include<stdio.h>	//函数需要有输入和输出


/*把文件pe12-2b.c中的mode传递给本文件 */
/*	因为要求只能使用自动变量，所以在set_mode函数每次被调用的时候，不能保存mode变量
 *		这样子为了知道之前的模式是什么，就要和例题一样，也引入一个变量premode来储存之前的模式
 **/
int set_mode(int choice,int premode)
{
	int mode=0;
	if(choice==0 || choice==1)mode=choice;	//如果mode输入正确，将main函数中获得的mode,传递给本文件的mode
	else if(premode==0)
	{
		printf("Invalid mode specified. Mode 0(Metric mode)used\n");//如果输入错误，使用上次的模式
		mode=premode;
	}
	else if(premode==1)
	{
		printf("Invalid mode specified. Mode 1(US)used\n ");
		mode=premode;
	}
	return mode;
}

/*根据mode值提示用户输入相应的数据，并将其存储到文件作用域变量*/
void get_info(int mode,double * p_d, double * p_c)	//p_d指向里程，p_c指向耗油量
{
	if(mode==0)
	{
		printf("Enter distance traveled in kilometers: ");
		while(scanf("%lf",p_d)!=1 || (*p_d)<0)
		{
			printf("Invalid input! \nAgain,Enter distance traveled in kilometers\n");
			if((*p_d)<0);
			else while(getchar()!='\n')continue;
			
		}
		
		printf("Enter fuel consumed in liters: ");
		while(scanf("%lf",p_c)!=1 || *p_c<0)
		{
			printf("Invalid input! \nAgain,Enter fuel consumed in liters:\n");
			if((*p_c)<0);
                        else while(getchar()!='\n')continue;

		}
	}
	else if(mode==1)
	{
		printf("Enter distance traveled in miles: ");
                while(scanf("%lf",p_d)!=1 || *p_d<0)
                {
                        printf("Invalid input! \nAgain,Enter distance traveled in miles\n");
			if((*p_d)<0);
                        else while(getchar()!='\n')continue;

                }

                printf("Enter fuel consumed in gallons: ");
                while(scanf("%lf",p_c)!=1 || *p_c<0)
                {
                        printf("Invalid input! \nAgain,Enter fuel consumed in gallons:\n");
			if((*p_c)<0);
                        else while(getchar()!='\n')continue;

                }

	}
}

/*根据设置的模式计算并且显示油耗*/
void show_info(int mode,double distance,double consumption)
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


