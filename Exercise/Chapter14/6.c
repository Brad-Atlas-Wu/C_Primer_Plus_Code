/*任务：在例题要求的基础上分为3个功能
 * 	1. 添加球员数据（如果球员号已经存在，那么直接显示球员名字，然后获取后面的信息）
 * 	2.删除球员数据（按照球员号）
 * 	3. 显示球员数据以及全部统计信息
 * 算法：
 * 	声明结构member
 * 	定义member类型的数组
 * 
 * 	showmenu()显示选项菜单
 * 	
 * count_data():统计文件中现有多少条球员数据
 *
 * 添加球员：void add_member(struct member *)
 * 	while(获取球员号)
 *		判断球员号是否已经存在
 * 			是：显示球员名
 * 			否：获取球员名
 * 		继续获得球员其它数据
 * 	if（获取数据成功）
 * 		调用add_to_file()，把新添数据写入文件
 *
 *	
 *	add_to_file:
 *		定义文件指针
 *		a+b模式打开文件
 *		fwrite()写入文件
 *		关闭文件
 * 	
 * */

#include<stdio.h>
#include<string.h>
#define LEN 20
#define MAX 100//限制文件最多包含100条数据
struct name{
	char fir_name[LEN]; 	
	char last_name[LEN];
};

struct member{
	short player_num;
	struct name member_name;
	int show_times;//上场次数
	int hit_times;//击中数
	int run_times;//走垒数
	int rbi;//打点

};

void show_menu(void);//显示用户选项菜单
char getchoice(void)；//获得/检测用户选项
void add_member(struct member *);
int main(void)
{
	struct member arr_data[MAX];
	char choice;

	show_menu();//显示用户选项菜单
	while((choice=getchar())!='q')
	{
		switch(choice)
		{
			case 'a':add_member(arr_data);break;
			case 'd':del_memver(arr_data);break;
			case 's':show_data(arr_data);break;
			default: printf("Invalid choice!\n");break;
		}
	}

void show_menu(void)
{
	printf("\n**************************************\n");
	printf("a) add new members\td) delete members\ns)show all member data\tq)quit\n");
	printf("Please enter your choice: ");
	printf("\n**************************************\n");
}



