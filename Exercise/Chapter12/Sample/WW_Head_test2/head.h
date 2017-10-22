#include<stdio.h>
/*预定义不同酒店的单日价格*/
#define P1 400
#define P2 650
#define P3 1000
#define P4 1500
#define RATE 0.95
/*声明子函数原型*/
void list(void);		//打印酒店清单
int days(void);		//获得并且判断用户输入的天数，返回正确值
long count(int days,int price);	//根据用户输入的天数和酒店计算最终总价


