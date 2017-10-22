//知识点：结构数组的数组名=结构第一个成员地址
#include<stdio.h>
#define FUNDLEN 50
#define N 2	//结构数组的上限+1

struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[],int n);	//第一个参数是一个结构指针

int main(void)
{
	struct funds jones[N]={
		{
			"Garlic-Melon Bank",
			4032.27,
			"Lucky's Savings and Loan",
			8543.94
		},
		{
			"Honest Jack's Bank",
			3620.88,
			"Party Times Savings",
			3802.91
		}
	};

	printf("The Joneses have a total of $%.2f.\n",sum(jones,N));
	return 0;
}

double sum(const struct funds money[],int n)
{
	double total;
	int i;

	for(i=0,total=0;i<n;i++)
		total+=money[i].bankfund+money[i].savefund;

	return(total);
}

