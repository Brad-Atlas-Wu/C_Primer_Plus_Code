#include<stdio.h>

int main()	
{
	char ch;
	int last=0;	//1代表上一个字符是e，0代表上一个字符不是e
	int n=0;	//计算ei出现的次数
	while((ch=getchar())!='#')
	{
		if(ch=='e')last=1;
		else if(ch=='i' && last==1){n++;last=0;}
		else last=0;
	}
	printf("一共有%d个ei\n",n);
	return 0;
}
