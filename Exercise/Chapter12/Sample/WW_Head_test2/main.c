/*
 *	算法：
 *		列出酒店名称和选项（包含退出选项）
 *		
 *		while(获取选项不等于q)	
 *			如果为合法输入，获得相应价目
 *				询问并获得天数
 *					如果天数不合法，重复输入
 *					如果输入b，列出清单，返回上级(跳出此次循环)
 *					如果输入为合法数字（整数）
 *						计算并输出最终价格！
 *			否则（输入非法）发出警告并且
 *				处理剩余的输入
 *				输出酒店列表，要求重新输入（跳出此次循环）
 *				
 *	
 *		子函数1输出酒店清单	void list(void)
 *		子函数2获得天数并进行判断  int days(void);
 *		子函数3根据选择的酒店和天数，计算最终价格，并且输出	long count(int days,int price)
 *		
 *	
 *	问题：程序后面有两处处理多余的字符流，可是尚未清楚多余字符的来源？
 * */

#include"head.h"
int main(void)
{
	int ch;		//记录选择的酒店
	int price;	//记录酒店的价格
	int time;	//记录用户输入的时间
	printf("1:");list();		//列出酒店清单	****在list前面标号，是为了定位list()位置，方便debug****	
	while((ch=getchar())!='q')
	{
		/*根据用户输入获得相应的价目*/
		if(ch=='a')price=P1;		
		else if(ch=='b')price=P2;
		else if(ch=='c')price=P3;
		else if(ch=='d')price=P4;
		else		//输入非法
		{
			while(getchar()!='\n')continue;	//处理后面输入的多余字符
			printf("2:");printf("请输入清单上的选择\n");
			list();
			continue;		
		}


		/*获得并且判断天数，返回天数*/
		time=days();
		if(time==-1)break;	//time返回为-1，结束程序
		else if(time==-2)	//time返回为-2，回到上一级，重新选择酒店
		{
			printf("3:");list();
			while(getchar()!='\n')continue;	//处理输入流中多余的字符(仍然不太清楚这个多余字符是哪里引入的~~~~~)
			continue;	//跳出本次循环（相当于菜单的返回上级）
		}

		/*计算并且输出最终价格*/
		count(time,price);
		printf("\n");
		printf("4:");list();
		while(getchar()!='\n')continue;	//处理输入流中多余的字符（不明字符流）
	}
	return 0;
}
