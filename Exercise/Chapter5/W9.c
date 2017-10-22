#include<stdio.h>
#define F_TO_C 5.0/9.0
#define C_TO_K 273.16
void Temperatures(double fah);


void Temperatures(double fah)
{
        double cel,kai;
        cel=F_TO_C*(fah-32.0);
        kai=C_TO_K+cel;
        printf("%.2lf fah is %.2lf Cel, which is %.2lf Kai\n",fah,cel,kai);
}



int main()
{
	double fah;
	int n;		//用于统计输入了多少项
	printf("Please enter a Fah:\n");
	
	while(scanf("%lf",&fah))	//这里提供了一个很好的判断输入的方法，在这里，如果输入的不是数字，那么退出
	{				//另一个好处是不需要在循环前面另外加一个scanf语句，更简洁
		Temperatures(fah);
	}	
	return 0;
}

