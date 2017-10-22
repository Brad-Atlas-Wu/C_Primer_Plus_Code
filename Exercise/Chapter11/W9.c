/*
 *	任务：反序存储字符串
 * */

#include<stdio.h>
#define SIZE 50
void inverse(char *);
int main(void)
{
	char order_str[SIZE];
	char ch;
	printf("请输入一个字符串:\n");
	fgets(order_str,SIZE,stdin);		//fgets()会输入换行符，所以字符串的最后一位是'\0'，倒数第二位是\n'
	fputs(order_str,stdout);
	inverse(order_str);
	fputs(order_str,stdout);
	return 0;
}

void inverse(char * str)
{
	int i;
	char * p_end;
	char * p_start=str;
	char temp;
	while(*++str != '\0')continue;
	p_end=str-2;		//不交换'\0'和'\n'
	while(p_start<=p_end)
	{
		temp=*p_start;
		*p_start=*p_end;
		*p_end=temp;
		p_start++;
		p_end--;
	}
	

}
