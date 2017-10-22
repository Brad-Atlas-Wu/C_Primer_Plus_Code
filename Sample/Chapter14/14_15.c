//任务：用户输入一种颜色，程序判断程序中是否有这种颜色
//知识点：1.枚举类型enum(可以出现在所有int类型能出现的位置，提高代码可读性)

#include<stdio.h>
#include<string.h>//提供strcmp()、strchr()函数原型
#include<stdbool.h>//C99特性
char * s_gets(char * st,int n);

enum spectrum{red,orange,yellow,green,blue,violet};//枚举模板声明
const char * colors[]={"red","orange","yellow","green","blue","violet"};
#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found=false;

	puts("Enter a color(empty line to quit):");
	while(s_gets(choice,LEN)!=NULL && choice[0]!='\0')
	{
		for(color=red;color<=violet;color++)
		{
			if(strcmp(choice,colors[color])==0)
			{
				color_is_found=true;
				break;
			}
		}
		if(color_is_found)
		{
			switch(color)
			{
				case red:puts("Roses are red.");break;
				case orange:puts("Poppies are orange.");break;
				case yellow:puts("Sunflowers are yellow.");break;
				case green:puts("Grass is green.");break;
				case blue:puts("Bluebells are blue.");break;
				case violet:puts("Violets are violet.");break;
			}
		}
			else 
				printf("I don't know about the color %s.\n",choice);
			color_is_found=false;//=>初始化
			puts("Next color,please(empty line to quit):");
		
	}
	puts("Goodbye!\n");
	return 0;
}

char * s_gets(char * st,int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');   //查找换行符
		if(find)                //如果地址不是NULL
		*find='\0';     //在此处放置一个控制符
		else
			while(getchar()!='\n')				
				continue;       //处理输入行中剩余的字符			
	}	
	return ret_val;
}

