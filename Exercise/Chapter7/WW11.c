/*
伪代码：
	打印铲平价格表，供用户选择

	当输入不为q的时候，循环输入字母选项，选择产品
		如果输入为f，跳出循环
		如果输入不是a,b,c中的任意一个，那么要求重新输入

		如果输入为a,b,c中的任意一个，提示要输入重量，输入产品要添加的重量
		分支选择，对应产品的重量加上要添加的重量	
	如果输入为q，结束程序

	根据购买的重量和总价计算运费和折扣
	输出所有信息



	
		
*/

#include<stdio.h>
#define FARE_1 6.5	//小于等于5磅的运费
#define FARE_2 14	//大于5磅小于等于20磅的运费
#define EXTRA_FARE 0.1	//大于20磅多余每磅的运费
#define P_1 2.06	//洋蓟价格
#define P_2 1.15	//甜菜价格
#define P_3 1.09	//胡萝卜价格
int main()
{
	char ch;
	double w_yj,w_tc,w_hlb;		//三种蔬菜的重量
	double w_total;			//三种蔬菜的总重量
	double w_add;			//每次添加的重量		
	double price;			//蔬菜总价
	double sale;			//折扣
	double price_S;			//折扣后的价格
	double fare;			//运费包装费
	w_yj=w_tc=w_hlb=0.0;
	
	printf("***********************************************\n");
	printf("价格表：\n");
	printf("洋蓟：$2.05/pound\t甜菜：$1.15/pound\t胡萝卜：$1.09/pound\n");
	printf("选购：洋蓟(a)\t甜菜(b)\t胡萝卜(c)\t完成订单(f)\t退出订购(q)\n");
	printf("***********************************************\n");

	while((ch=getchar())!='q')
	{	
		if(ch=='f')break;				//重点1：这个地方需要现行判断ch的值，因为如果ch是f,q
		else if(ch=='\n')continue;			//	或者其他非a,b,c的字母时，就不需要继续输入
		else if(ch!='a' && ch!='b' && ch!='c')		//	下面的w_add。
		{						//	因此判断条件出现的位置和先后非常关键！
			printf("输入无效！请重新输入！\n");
			continue;
		}

		printf("请输入订购的重量：\n");			//重点2：这里需要在判断ch是a,b,c之前先输入一个w_add
		scanf("%lf",&w_add);				//	这个地方能造成很多问题！！！
		switch (ch)					//	假设上面getchar()输入一个a,我们确认的时候其
		{						//	实还输入了一个换行，而这个换行就会被scanf()
			case 'a':w_yj+=w_add;break;		//	接收。但是由于和转换说明%lf不符合，所以输入
			case 'b':w_tc+=w_add;break;		//	的换行符就会继续往后传，知道被下一次的getchar
			case 'c':w_hlb+=w_add;break;		//	接受！！！这显然不是我想要的！因此在前面会有
			default:;				//	语句：if(ch=='\n')continue;这样就能跳过这个
		}						//	换行。
								//补充：根据后面的学习，我知道应该改为
								//	while(getchar()!='\n')continue,这样就可以跳过								     //      所有后来的输入
		
		printf("*************************************************************************\n");
                printf("价格表：\n");
                printf("洋蓟：$2.05/pound\t甜菜：$1.15/pound\t胡萝卜：$1.09/pound\n");
                printf("选购：洋蓟(a)\t甜菜(b)\t胡萝卜(c)\t完成订单(f)\t退出订购(q)\n");
                printf("*************************************************************************\n");


	}
	if(ch=='q')
	{
		printf("放弃订单！\n");
		return 0;
	}
	
	
	//计算蔬菜的价格，并且计算折扣和折扣后的价格
	price=P_1*w_yj+P_2*w_tc+P_3*w_hlb;
	sale=((int)price/100)*5.0;
	price_S=price-sale;
	
	
	//计算蔬菜的总重量和运费
	w_total=w_yj+w_tc+w_hlb;
	if(w_total<=5)fare=FARE_1;
	else if(w_total<=20)fare=FARE_2;
	else fare=FARE_2+EXTRA_FARE*(w_total-20);
	
	
	printf("*******************************************************************************************\n");
	printf("订单确认：\n");
	printf("\t物品售价：  洋蓟：$2.05/pound\t甜菜：$1.15/pound\t胡萝卜：$1.09/pound\n");
	printf("\t订购重量：  洋蓟：%.2lfpounds\t甜菜：%.2lfpounds\t胡萝卜：%.2lfpounds\n",w_yj,w_tc,w_hlb);
	printf("\t重量合计：%.2lf pounds\n",w_total);
	printf("\t订购蔬菜费用：%.2lf\t",price);
	printf("包装盒运输费用：%.2lf\t",fare);
	printf("合计:%.2lf\n",price+fare);
	printf("\t您获得的折扣：%.2lf\n",sale);
	printf("\t应付价格：%.2lf\n",price+fare-sale);	
	printf("********************************************************************************************\n");

	return 0;
}
