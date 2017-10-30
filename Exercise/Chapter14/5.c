/*
	任务：建立一个学生计分系统

	知识点：1.结构操作

	算法：
		两个结构，初始化学生姓名

	子函数1）获得学生成绩：	获得用户输入的学生姓名，匹配学生
				匹配无效：输出无法匹配，重新输入
				匹配成功：提示用户输入该学生的三科成绩（处理多余字符）；计算三科平均分，存入结构
	子函数2）输出学生成绩：

	子函数3）计算并输出班级信息：（各科和全部平均分）
*/
#include<stdio.h>
#include<string.h>
#define LEN 20
#define CSIZE  4

//定义两个结构模板
struct name{
	char fir_name[LEN];
	char last_name[LEN];
};

struct student{
	struct name student_name;
	float grade[3];
	float ave;
};

void get_data(struct student *,int);//获取用户输入的学生成绩
void output_stu_data(struct student *,int);//输出学生个人信息
void output_class_data(struct student *,int);//输出班级信息
char * s_gets(char *,int n);

int main(void)
{	
	//定义结构数组,初始化学生姓名
	struct student stu_arr[CSIZE]={
		{{"Brad","Wu"}},
		{{"Clara","Lin"}},
		{{"Una","Xie"}},
		{{"Rice","Wu"}}
	};
	
	get_data(stu_arr,CSIZE);//匹配姓名，获得学生个人信息
	output_stu_data(stu_arr,CSIZE);//输出学生个人信息
	output_class_data(stu_arr,CSIZE);//输出班级平均分
}

void get_data(struct student * p_stu,int n)
{
	char temp_name[2][LEN];
	printf("Please enter student's first name(empty line to quit): ");
	while(s_gets(temp_name[0],LEN) && temp_name[0][0]!='\0')
	{	
		printf("The first name: %s\n",temp_name[0]);
		printf("Now enter the last name(empty to quit): ");
		if(s_gets(temp_name[1],LEN) && temp_name[1][0]=='\0')
		{
			printf("The Second name: %s\n",temp_name[1]);
			printf("END_1\n");
			break;
		}
		
		int i;
		for(i=0;i<n;i++)
		{
			if((strcmp(temp_name[0],p_stu[i].student_name.fir_name)==0) && (strcmp(temp_name[1],p_stu[i].student_name.last_name)==0))//找到匹配的学生
			{
				printf("Please enter his/her scores: ");
				for(int j=0;j<3;j++)//获得用户输入的成绩
				{
					printf("Subject%d: ",j+1);
					if(scanf("%f",&(p_stu[i].grade[j]))!=1)
						fprintf(stderr,"ERROR!");
		                }   

				p_stu[i].ave=(p_stu[i].grade[0]+p_stu[i].grade[1]+p_stu[i].grade[2])/3.0;//计算该学生的平均分
				while(getchar()!='\n')continue;//处理多余字符
				break;//既然找到匹配学生姓名，就提前退出循环
			}
		}

		if(i==n)//如果没有找到匹配的学生
		{
			printf("Student %s is not in the list\n",temp_name);
			printf("Enter another student name: ");
			continue;
		}
		
		printf("Enter the next student(empty line to quit): ");
	}
}

void output_stu_data(struct student * p_stu,int n)
{
	float class_ave=0.0;
	printf("************************************************************\n");
	printf("NAME\t\tG1\tG2\tG3\tAVE\n");
	for(int i=0;i<n;i++)
	{
		printf("%s %s:\t%.2f\t%.2f\t%.2f\t%.2f\n",p_stu[i].student_name.fir_name,p_stu[i].student_name.last_name,p_stu[i].grade[0],p_stu[i].grade[1],p_stu[i].grade[2],p_stu[i].ave);
	}
	printf("************************************************************\n");
	
}

void output_class_data(struct student * p_stu,int n)
{
	struct student class;//定义储存班级信息的结构

	//求各科/全科班级平均分
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<n;j++)
		{
			class.grade[i]+=p_stu[j].grade[i];
			if(i==0)//只计算一次
				class.ave+=p_stu[j].ave;
		}
		class.grade[i]/=(float)n;
	}
	class.ave/=(float)n;



	//打印班级成绩信息
	printf("Class average:\n");
	for(int i=0;i<3;i++)
	{
		printf("\tG%d: %.2f\n",i+1,class.grade[i]);
	}
	printf("Total_ave: %.2f\n",class.ave);
}


char * s_gets(char name[],int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(name,n,stdin);
	find=strchr(name,'\n');
	if(find)*find='\0';
	else 
		while(getchar()!='\n')continue;
	return ret_val;
}

