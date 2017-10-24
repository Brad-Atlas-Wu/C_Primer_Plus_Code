//任务：输出窗口设置选项（包括：透明/不透明，填充颜色，边框风格，边框颜色）
//知识点：1.位字段的使用（节省空间）
//	  2.这个程序提供了很好的“选择输出”的模板
//
//算法：宏定义各种选项（根据）
//	声明位字段结构模板
//	创建/初始化位字段结构
//	输出结构内容
//	改变结构内容
//	再次输出

#include<stdio.h>
#include<stdbool.h>//C99定义了bool,true,false

/*线的样式*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/*三原色,对应二进制数*/
#define BLUE 4	
#define GREEN 2
#define RED 1

/*混合色*/
#define BLACK 0
#define YELLOW (RED | GREEN)//这里用到了位操作符“ |”
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8]={"black","red","green","yellow","blue","magenta","cyan","white"};

//=>声明位字段结构与模板
struct box_props{
	bool opaque: 1;//或者unsigned int(C99以前)
	unsigned int fill_color: 3;
	unsigned int: 4;//边界对齐
	bool show_border: 1;//或者unsigned int (C99以前)
	unsigned int border_color: 3;
	unsigned int border_style: 2;
	unsigned int: 2;//边界对齐
};

void show_settings(const struct box_props * pb);//参数为结构指针

int main(void)
{
	//创建并初始化box_props结构box
	struct box_props box={true,YELLOW,true,GREEN,DASHED};

	printf("Original box settings:\n");
	show_settings(&box);

	box.opaque=false;
	box.fill_color=WHITE;
	box.border_color=MAGENTA;
	box.border_style=SOLID;
	printf("\nModified box settings:\n");
	show_settings(&box);

	return 0;
}

void show_settings(const struct box_props * pb)
{
	printf("Box is %s.\n",pb->opaque==true?"opaque":"transparent");//条件表达式选择输出
	printf("The fille color is %s.\n",colors[pb->fill_color]);//用下标选择输出（对应标为颜色的值）
	printf("Border %s.\n",pb->show_border==true?"shown":"not shown");
	printf("The border color is %s.\n",colors[pb->border_color]);//用下标选择输出
	printf("The border style is ");
	switch(pb->border_style)//条件分支语句选择输出
	{
		case SOLID :printf("solid.\n");break;
		case DOTTED: printf("dotted.\n");break;
		case DASHED:printf("dashed.\n");break;
		default: printf("unknown type.\n");
	}
	
}


