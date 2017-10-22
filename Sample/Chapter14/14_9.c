//知识点：子函数中，传递和返回结构体来修改结构体内容
#include<stdio.h>
#include<string.h>	//strlen原型

#define NLEN 30
struct namect{
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect );
void showinfo(struct namect );
char * s_gets(char * st,int n);

int main(void)
{
	struct namect person;

	person=getinfo();
	person=makeinfo(person);
	showinfo(person);
	return 0;
}

struct namect getinfo(void)
{
	struct namect temp;	//临时结构体temp
	printf("Please enter your first name.\n");
	s_gets(temp.fname,NLEN);
	printf("Please enter your last name.\n");
	s_gets(temp.lname,NLEN);
	return temp;
}

struct namect makeinfo(struct namect info)
{
	info.letters=strlen(info.fname)+strlen(info.lname);
	return info;
}

void showinfo(struct namect info )
{
	printf("%s %s, your name contains %d letters.\n",info.fname,info.lname,info.letters);
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

