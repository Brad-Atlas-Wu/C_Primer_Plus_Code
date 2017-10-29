/*
	任务：建立一个学生计分系统
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
void output_data(struct student *,int);//输出信息
char * s_gets(char *,int n);

int main(void)
{	
	//定义结构数组,初始化学生姓名
	struct student stu_arr[CSIZE]={
		{{"Brad","Wu"}},
		{{"Clare","Lin"}},
		{{"Una","Xie"}},
		{{"Rice","Wu"}}
	};
	
	get_data(stu_arr,CSIZE);
	output_data(stu_arr,CSIZE);
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
				for(int i=1;i<=3;i++)
				{
					printf("Subject%d: ",i);
					if(scanf("%f",&(p_stu[i].grade[i]))!=1)
						fprintf(stderr,"ERROR!");
		                }   

				p_stu[i].ave=(p_stu[i].grade[0]+p_stu[i].grade[1]+p_stu[i].grade[2])/3.0;
			}
		}
		if(i==n)
		{
			printf("Student %s is not in the list\n",temp_name);
			printf("Enter another student name: ");
			continue;
		}
		
		while(getchar()!='\n')continue;//处理多余字符
		printf("Enter the next student(empty line to quit): ");
	}
}

void output_data(struct student * p_stu,int n)
{
	float class_ave=0.0;
	printf("************************************************************\n");
	printf("NAME\tG1\tG2\tG3\tAVE\n");
	for(int i=0;i<n;i++)
	{
		printf("%s %s:\t%f\t%f\t%f\t%f\n",p_stu[i].student_name.fir_name,p_stu[i].student_name.last_name,p_stu[i].grade[0],p_stu[i].grade[1],p_stu[i].grade[2],p_stu[i].ave);
	}
/*	
	//计算班级平均分
	int i;
	for(i=0;i<CSIZE;i++)
	{
		class_ave+=p_stu[i].ave;
	}
	class_ave/=(float)i;

	printf("The average score of this class: %lf\n",);
*/
	printf("************************************************************\n");
	
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

