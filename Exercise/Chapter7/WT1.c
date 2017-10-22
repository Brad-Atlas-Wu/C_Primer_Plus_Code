/*
 	例题见P207
	用户输入数字，输出数字的所有约数，或者输出数字是一个素数
	变量： int n保存数字，int i控制循环并且左右%的右运算数。
		int t来计数输出了个约数，如果是0那么就证明是素数
	
	


*/
#include<stdio.h>

int  main()
{	
	int n;
	int t=0;
	scanf("%d",&n);
	for(int i=2;i<=n/2;i++)		//这个地方到n/2(实际到根号n就够了，但是要输出除数和商)，另外切记i是从2开始，如果从0开始那就会陷入死循环！
	{
		if(n%i==0)
		{
			printf("%d ",i);
			t++;
		}
	}
	if(t==0)printf("这是一个素数！\n");
	
	return 0;
}

