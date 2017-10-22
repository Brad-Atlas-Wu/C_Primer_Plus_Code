#include<stdio.h>

int main()
{
	long double k;
	double kt;	//夸脱
	k=(1.e23)/3.0;	//表示每克水含有的水分子数量
	printf("请输入夸脱数：");
	scanf("%lf",&kt);
	printf("%lf 夸脱相当于%lf克，相当于有%.0llf个水分子\n",kt,kt*950,kt*950*k);	
        return 0;
}

