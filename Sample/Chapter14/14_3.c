/*任务：管理自己的朋友信息,输出一封给好友的信
 * 知识点：1. 结构嵌套
 * 	  2. 数组指针的使用
 * */

#include<stdio.h>
#define LEN 20

//这里演示了数组指针的一个使用
const char * msgs[5]=		//定义了一个数组，每个数组元素是一个char类型指针
{
	"	Thank you for the wonderful evening, ",
	"You certainly prove that a ",
	"is a special kind of guy. We must get together",
	"over a delicious ",
	" and have a few laughs"
};

struct names{
	char first[LEN];
	char last[LEN];
};

struct guy{
	struct names handle;	//第二个结构
	char favfood[LEN];	//嵌套结构
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow={
		{"Ewen","Villard"},
		"grilled salmon",
		"personality coach",
		68112.00
	};

	printf("Dear %s,\n\n",fellow.handle.first);
	printf("%s%s.\n",msgs[0],fellow.handle.first);
	printf("%s%s\n",msgs[1],fellow.job);
	printf("%s\n",msgs[2]);
	printf("%s%s%s",msgs[3],fellow.favfood,msgs[4]);
	if(fellow.income>150000.0)
		puts("!!");
	else if(fellow.income>75000.0)
		puts("!");
	else 
		puts(".");
	printf("\n%40s%s\n"," ","See you soon,");
	printf("%40s%s\n" ," ","Shalala");

	return 0;
}

