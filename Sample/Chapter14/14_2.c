/*任务：创建多本书的目录，包含每本书的书名、作者、价格信息
 * 知识点：结构体数组定义和访问
 * */

#include<stdio.h>
#include<string.h>
char * s_gets(char * st,int n);
#define MAXTITL 40
#define MAXAUTL	40
#define MAXBKS 100	//书的最大数量，也就是结构体数组的上限

struct book{		//书的模板
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};		

int main(void)
{
	struct book library[MAXBKS];	//定义book类型结构的数组
	int count=0;	//计算输入了多少本书
	int index;
	
	printf("Please enter the book title.\n");
	printf("Press[Enter] at the start of a line to stop.\n");
	//书籍数量没有越界，获得书名成功且不为空行,执行循环
	while(count<MAXBKS && s_gets(library[count].title,MAXTITL)!=NULL && library[count].title[0]!=0)
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author,MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f",&library[count++].value);	//最后这里才count++
		while(getchar()!='\n')continue;		//清楚输入行
		if(count <MAXBKS)	//提示继续输入下一本书
			printf("Enter the next title.\n");
	}

	if(count>0)
	{
		printf("Here is the list of your books:\n");
		for(index=0;index<count;index++)
			printf("%s by %s : $%.2f\n",library[index].title,library[index].author,library[index].value);
		
	}
	else
		printf("No books? Too bad.\n");
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

