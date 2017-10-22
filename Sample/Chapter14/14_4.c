//知识点：1.结构体指针	2. 结构体数组的初始化（包含嵌套）

#include<stdio.h>
#define LEN 20

//声明标记为names模板
struct names{
	char first[LEN];
	char last[LEN];
};

//声明标记为guy的模板，这两个模板都是全局作用域
struct guy{
	struct	names handle;	//定义并嵌套了类型为struct names的结构体变量handle
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	//定义并初始化了一个struct guy类型的数组，数组有两个元素
	struct guy fellow[2]={
		{{"Ewen","Villard"},	//初始化数组第一个元素
		"grilled salmon",
		"personality coach",
		68112.00	
		},
		{{"Rodney","Swillblly"},	//初始化数组的第二个元素
		"tripe",
		"tabloid editor",
		432400.00	
		}
	};

	struct guy * him;	//定义了一个struct guy类型的结构体指针
	
	printf("address #1:%p #2:%p\n",&fellow[0],&fellow[1]);
	him=&fellow[0];	//告诉编译器该指针指向何处
	printf("pointer #1:%p #2:%p\n",him,him+1);
	printf("him->income is $%.2f; (*him).income is $%.2f\n",him->income,(*him).income);
	him++;	//指向下一个结构(数组的第二个元素)
	printf("him->favfood is %s; him->handle.last is %s\n",him->favfood,him->handle.last);
	return 0;
}
