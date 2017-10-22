//在程序14_8.c的基础上，将fname和lname改为指针（原本是数组），以演示不同
//知识点：1. 结构体中指针的**安全**使用		2.动态分配内存
#include<stdio.h>
#include<string.h>	//strlen原型
#include<stdlib.h>
#define NLEN 30
struct namect{
	char * fname;	//改为指针
	char * lname;
	int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);
char * s_gets(char * st,int n);

int main(void)
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
	return 0;
}

void getinfo(struct namect * pst)
{
	char temp[NLEN];	//定义临时数组储存字符串
	printf("Please enter your first name.\n");
	s_gets(temp,NLEN);
	//分配内存以储存名
	pst->fname=(char *)malloc(strlen(temp)+1);
	//把名拷贝到动态分配的内存中
	strcpy(pst->fname,temp);

	printf("Please enter your last name.\n");
	s_gets(temp,NLEN);
	pst->lname=(char *)malloc(strlen(temp)+1);
	strcpy(pst->lname,temp);
}

void makeinfo(struct namect * pst)
{
	pst->letters=strlen(pst->fname)+strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
	printf("%s %s, your name contains %d letters.\n",pst->fname,pst->lname,pst->letters);
}
void cleanup(struct namect * pst)
{
	free(pst->fname);
	free(pst->lname);
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
		while(getchar()!='\n')continue;       //处理输入行中剩余的字符
	}
	return 0;
}

