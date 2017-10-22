#include<stdio.h>

int main()
{
	int a;
	printf("please enter an ASCII num: ");
	scanf("%d",&a);
	if(a>=0 && a<=255){printf("the corresponding char of %d is %c\n",a,a);}
	else printf("数值无效，请输入范围为0-255的ASCII码！\n");

	return 0;
}
