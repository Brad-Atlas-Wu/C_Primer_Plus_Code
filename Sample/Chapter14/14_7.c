//知识点：整个结构体内容作为参数传递
#include<stdio.h>
#define FUNDLEN 50

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds moolah);	//参数是整个结构体内容（副本）

int main(void)
{
	struct funds stan={
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
		
	printf("Stan has a total of $%.2f.\n",sum(stan));
	return 0;
}

//两个double类型的数相加
double sum(const struct funds moolah)
{
	return (moolah.bankfund+moolah.savefund);
}
