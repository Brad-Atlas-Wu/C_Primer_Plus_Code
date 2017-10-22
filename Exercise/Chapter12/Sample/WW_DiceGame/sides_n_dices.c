/*文件包含函数unsigned int getsides()和unsigned int getdices()
 *	unsigned int getsides()用于获得并且判断用户输入的色子面数
 *	unsigned int getdices()用于获得并且判断用户输入的色子个数
 * */
#include<stdio.h>
unsigned int getsides(void)
{
/*这个地方，开始的时候定义了unsigned int sides，然后scanf("%u",&sides)!=1或者sides<0则进入循环。
 * 结果是我输入的数字为负数，却仍然没有进入循环，甚至可以正常生成和输出随机数！
 *	实验发现，当我输入比如-10的时候，scanf仍然返回1，并把-10转换成unsigned int ASCII说对应的数字，正常赋值
 *		因此程序自然可以运行，但是运行结果是错的！
 * */
	int sides;
	while(scanf("%d",&sides)!=1 || sides<2 && sides!=0)
	{
		printf("您的输入不正确！(必须是大于等于2的整数)请重新输入(输入0退出)\n");

		if(sides<0);
		else
		while(getchar()!='\n')continue;	//处理多余字符
	}
	return sides;
}

unsigned int getdices(void)
{
	int dices;
	 while(scanf("%d",&dices)!=1 || (dices<0 && dices!=-1 && dices!=0))
        {
                printf("您的输入不正确！请重新输入(0退出，-1返回上级)\n");

		if(dices<0);
                else
                while(getchar()!='\n')continue;
        }
	return dices;

}
