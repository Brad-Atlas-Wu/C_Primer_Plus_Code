#include<stdio.h>
int test(void);
int main(void)
{
	int i;
	while(getchar()!='@')
	{
		i=test();
	}
	printf("函数被调用了%d次\n",i);
}

int test(void)
{
	static int i=0;
	printf("Hello\n");
	i++;
	return i;
	
}
