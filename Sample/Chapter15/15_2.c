/*任务：切换一个值中的后n位，待处理的值和n都是函数的参数
 *	注：程序为自己的练习，和例题不同(例题一次生成掩码的方法值得借鉴)
 *算法：获得用户输入的数值和n
 	inverse()将数值最后n位切换，返回数值
 *      用itobs()的方法求出0/1序列
 *
 * 知识点:1. 生成掩码
 * */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void itobs(char *,int);
int inverse(int,int);
int main(void)
{
	size_t size;//位数量
	int x;
	int num;//记录用户输入的n位
	char * fstr;
	printf("Enter an integer,please:(q to quit)\n");
	while(scanf("%d",&x)==1)
	{
		if(scanf("%d",&num)!=1)
		{
			printf("Invalid!\n");
			return 1;
		}

		size=sizeof(x)*CHAR_BIT;//提高可移植性
		fstr=malloc(size+1);//动态分配空间（变长数组就可以，但是这样可移植性更好）
		itobs(fstr,x);
		printf("%d is equal to %s\n",x,fstr);
		x=inverse(x,num);
		itobs(fstr,x);
		printf("inverse: %s\n",fstr);
		printf("Enter the next integer(q to quit):\n");
	}

	printf("Bye!\n");
	return 0;	
}

void itobs(char str[],int n)
{
	const static size_t size=sizeof(n)*CHAR_BIT;//这里参考例题标志为const static，这样一方面安全，另一方面定义为局部静态变量，节省了多次调用函数时重复定义和初始化size的时间!
	int mask=01;//掩码定义为八进制的1,即只有最低位为1
	
	for(int i=size-1;i>=0;i--)
	{
		str[i]=(n & mask)+'0';
		n>>=1;//n右移一位
	}
	str[size]='\0';
}

int inverse(int x,int n)
{
	int mask=01;
	for(int i=0;i<n;i++)
	{
		x^=mask;
		mask<<=1;		
	}
	return x;
}
