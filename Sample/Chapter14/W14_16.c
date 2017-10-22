/*任务：用户输入一段字符串
	根据用户选择实现下面功能：
		u: 转换为大写
		l:转换为小写
		t: 大小写转换
		o:输出原字符
		n:下一个字符串
知识点：1. 函数指针作为函数参数（用于选择哪一个函数,关键在于根据用户选择，定义函数指针指向哪个函数）
	2. 菜单小技巧：判断strchr("abc",ch)==NULL =》相当于：ch!=a && ch!=b && ch!=c
	3. 将用户选项转换为小写，这样就算用户输入大写对应的也是相应的小写选项
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 81
char * s_gets(char * st,int n);
char showmenu(void);//=>显示选择菜单，获取，判断并返回用户选择
void eatline(void);//清楚多余输入
void show(void (* pfun)(char *),char * str);//参数1为函数指针，根据函数指针指定的函数实现功能
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);//不更改字符串

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (* pfun)(char *);//声明一个函数指针，被指向的函数接收char *类型的参数，无返回值

	puts("Enter a string (empty line to quit):");
	while(s_gets(line,LEN)!=NULL && line[0]!='\0')
	{
		while((choice=showmenu())!='n')
		{
			switch(choice)//switch语句设置函数指针
			{
				case 'u':pfun=ToUpper;break;
				case 'l':pfun=ToLower;break;
				case 't':pfun=Transpose;break;
				case 'o':pfun=Dummy;break;
			}
			strcpy(copy,line);//为show()函数拷贝一份（因为下面的函数直接修改字符串内容）
			show(pfun,copy);//根据用户的选择，使用选定的函数
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");
	return 0;
}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase	l)lowercase");
	puts("t) transposed case 	o)original case");
	puts("n)next string");
	ans=getchar();//获得用户的输入
	ans=tolower(ans);//转换为小写
	eatline();//清理输入行
	while(strchr("ulton",ans)==NULL)
	{
		puts("Please enter a u,l,t,o,or n:");
		ans=tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void)
{
	while(getchar()!='\n')continue;
}

void ToUpper(char * str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while(*str)
	{
		*str=tolower(*str);
		str++;
	}
}

void Transpose(char * str)
{
	while(*str)
	{
		if(islower(*str))
			*str=toupper(*str);
		else if(isupper(*str))
			*str=tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
	//不改变字符串
}

void show(void (*fp)(char *),char * str)
{
	(*fp)(str);//把用户选定的函数作用于str
	puts(str);//显示结果
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
