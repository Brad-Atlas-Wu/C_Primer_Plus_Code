/*任务：利用为操作把整数转换为二进制输出
 * 	要求定义一个函数，参数为一个整数和一个字符串地址，
 * 	程序把整数转化为二进制0/1序列放入字符串，然后输出字符串
 *
 * 注：自己练习的版本，和例题写法略有不同
 *
 * 算法：获得用户输入的整数
 * 	sizeof求整数有多少字节，乘8求出位的数量size
 * 	定义大小为size+1的char数组
 * 	把数组名和整数传递给itobs()
 *
 * 	itobs():
 * 	while(没有到最后一位)
 * 		定义掩码，只有最低位为1(说白了就是1，为了装逼，用八进制01)
 * 		整数和掩码&操作获得i
 * 		i+'0'的值存入数组（由最大下标开始）=>因为数组中需要是字符而不是数字
 * 		左移一位
 * 知识点：1.提取位
 * */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void itobs(char *,int);

int main(void)
{
	size_t size;//位数量
	int n;
	char * fstr;
	printf("Enter an integer,please:(q to quit)\n");
	while(scanf("%d",&n)==1)
	{
		size=sizeof(n)*CHAR_BIT;//提高可移植性
		fstr=malloc(size+1);//动态分配空间（变长数组就可以，但是这样可移植性更好）
		itobs(fstr,n);
		printf("%d is equal to %s\n",n,fstr);
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

