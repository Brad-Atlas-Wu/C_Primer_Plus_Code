/*
 *	任务：
 *	设置lower=1,upper=100
 *	提示用户在1到100之间想一个数字，程序进行猜测输出
 *		如果用户输入y表明猜测正确，输出提示
 *		如果用户输入n表明猜测错误
 *			询问猜测的数字是高了还是低了
 *				如果高了，upper=guess
 *				如果低了, lower=guess
 *			取中值
 *
 *
 *
 * */

#include<stdio.h>

int main()
{
	int guess=50;
	int lower=1;
	int upper=100;
	char ch;
	printf("please choose a number between 1 to 100\n");
	printf("I would try to guess!\n");
	printf("If my guess is correct,enter y,else enter n\n\n");
	printf("Is your number %d?\n",guess);
	while(getchar()!='y')
	{	
		printf("My guess is too high or too low?\n");

		while(getchar()!='\n')continue;

		if((ch=getchar())=='h')upper=guess;
		else if(ch=='l')lower=guess;	
		guess=(lower+upper)/2;

		while(getchar()!='\n')continue;

		printf("Is your number %d?\n",guess);
	}

	printf("I am right!!!\n");
	


	return 0;
}
