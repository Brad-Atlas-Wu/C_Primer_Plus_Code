/*任务：在例题要求的基础上分为3个功能
 * 	1. 添加球员数据（如果球员号已经存在，那么直接显示球员名字，然后获取后面的信息）
 * 	2. 删除球员数据（按照球员号）
 * 	3. 显示球员数据以及全部统计信息
 *
 * 待实现：1.希望用户输入球员号之后，如果列表中有这个球员，就直接确认其姓名，无需用户重新输入
 * 		（这样的话就需要打开文件来检查）
 * 算法：
 * 	声明结构member
 * 	定义member类型的数组
 * 
 * 	showmenu()显示选项菜单
 * 	
 *	count_data():统计文件中现有多少条球员数据
 *
 * 添加球员：void add_member(struct member *,int)
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
 *删除球员：void delete_member(void)
 	要求用户输入要删除信息的球员号
	r模式打开原文件1
	w模式创建并打开另一个文件2
	循环读取文件1
		如果是索引号匹配的信息，跳过
		其他信息，写入文件2
	
	关闭文件1、文件2
	删除文件1
	重命名文件2为FILE_NAME
 * 	
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20
#define MAX 100//限制文件最多包含100条数据
#define FILE_NAME "data.out"
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
int count_data(void);//计算并返回文件中现在有多少用户的数据
void add_to_file(struct member *,int);
/*上面3个为辅助例程，下面三个是功能的具体实现*/

void add_member(struct member *,int);
void delete_member(void);
void show_data(int);


int main(void)
{
	struct member arr_data[MAX];
	char choice;
	int total_count=count_data();//获知文件中现有多少条数据

	show_menu();//显示用户选项菜单
	while((choice=getchar())!='q')
	{
		switch(choice)
		{
			case 'a':add_member(arr_data,total_count);break;
			case 'd':delete_member();break;
			case 's':show_data(total_count);break;
			default: printf("Invalid choice!\n");break;
		}
		while(getchar()!='\n')continue;//清除多余字符
		show_menu();//显示用户选项菜单
	}
}


//显示用户选项菜单
void show_menu(void)
{
	printf("\n**************************************\n");
	printf("a) add new members\td) delete members\ns)show all member data\tq)quit\n");
	printf("Please enter your choice: ");
	printf("\n**************************************\n");
}

void add_member(struct member * p_mem,int count)
{
	int i=0;
	printf("Enter the player number(enter [b] store&back to menu ): ");
	while((i<MAX-count) && (scanf("%d",&(p_mem[i].player_num))==1)) 
	{
		printf("Please enter the player's name(first&last): ");
		if(scanf("%s %s",p_mem[i].member_name.fir_name,p_mem[i].member_name.last_name) !=2)
		{
			printf("Invalid name format: Usage: [firstname lastname]\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Enter show_times,run_times,hit_times and rbi: ");
			if( scanf("%d %d %d %d",&(p_mem[i].show_times),&(p_mem[i].run_times),&(p_mem[i].hit_times),&(p_mem[i].rbi))!=4 )
			{
				printf("Invalid times input\n");
				exit(EXIT_FAILURE);
			}
		}
		printf("Please enter the player number(enter [b] store&back to menu): ");
		i++;
	}

	if(i>0)
	{
		add_to_file(p_mem,i);
		printf("%d new datas appended!\n",i);
	}
	else
	{
		printf("No input appended!\n");
	}
}

void delete_member(void)
{
        FILE * fp; 
        FILE * fp_copy;
	int n;
	printf("Please enter the player's number you want to delete: ");
	while(scanf("%d",&n)!=1)
	{
		printf("Invalid character!\n");
		printf("Try again!\n");
		while(getchar()!='\n')continue;
	}

	if((fp=fopen(FILE_NAME,"r"))==NULL)
	{   
		printf("Failed opening file: %s\n",FILE_NAME);
		exit(EXIT_FAILURE);
	}

	 if((fp_copy=fopen("copy","w"))==NULL)                     
         {                                       
	 	printf("Failed opening file: %s\n","copy");                                                  
		exit(EXIT_FAILURE);                                                     
	}

	rewind(fp);
	rewind(fp_copy);
	struct member temp;
	while(fread(&temp,sizeof(struct member),1,fp)!=0)
	{
		if(temp.player_num==n);
		else
			fwrite(&temp,sizeof(struct member),1,fp_copy);
	}

	fclose(fp);
	fclose(fp_copy);
	remove("./data.out");
	rename("copy",FILE_NAME);
}
void show_data(int count)
{
	struct member temp;
	FILE * fp;
	if((fp=fopen(FILE_NAME,"r"))==NULL)
	{
		fprintf(stderr,"Failed opening file %s\n",FILE_NAME);
		exit(EXIT_FAILURE);
	}
	
	int i=0;
	rewind(fp);
	while( (fread(&temp,sizeof(struct member),1,fp)!=0) ) 
	{
		printf("%d | %-10s %-10s%-5d%-5d%-5d%-5d\n",temp.player_num,temp.member_name.fir_name,temp.member_name.last_name,temp.show_times,temp.hit_times,temp.run_times,temp.rbi);
	}
}

//获知文件里面现有多少条数据
int count_data(void)
{
	FILE * fp;
	if((fp=fopen(FILE_NAME,"r"))==NULL)
	{
		return 0;	
	}
	fseek(fp,0,SEEK_END);

	fclose(fp);
	return (ftell(fp)+1);
}

void add_to_file(struct member * p_mem,int count)
{
	FILE * fp;
	if((fp=fopen(FILE_NAME,"a+b"))==NULL)
	{
		fprintf(stderr,"Failed opening file:%s",FILE_NAME);
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<count;i++)
	{
		fwrite(&p_mem[i],sizeof(struct member),1,fp);
	}

	fclose(fp);
}
