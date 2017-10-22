#include<stdio.h>

int main()
{
	unsigned long long income_d;
	unsigned long long income_T=0;
	unsigned day;
	printf("Please enter the days:\n");
	scanf("%d",&day);
	for(int i=1;i<=day;i++)
	{
		income_d=i*i;
		income_T+=income_d;
	}
	printf("After %d days ,you can earn $%lld per day, $%lld in total\n",day,income_d,income_T);
	return 0;
}
