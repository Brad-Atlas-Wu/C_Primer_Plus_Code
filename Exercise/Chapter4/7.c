#include<stdio.h>
#include<float.h>

int main()
{
	float a=1.0/3.0;
	double b=1.0/3.0;
	
	printf("float小数位后6位：%.6f\n",a);
	printf("float小数位后12位：%.12f\n",a);
	printf("float小数位后16位：%.16f\n",a);
	printf("float类型最少有效数字位数：%d\n",FLT_DIG);	

	printf("double小数位后6位：%.6f\n",b);
        printf("double小数位后12位：%.12f\n",b);
        printf("double小数位后16位：%.16f\n",b);
	printf("double类型最少有效数字位数：%d\n",DBL_DIG);

	return 0;

}
