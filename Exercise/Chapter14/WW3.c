/*对例题14_2.c进行修改
 * 任务：创建多本书的目录，包含每本书的书名、作者、价格信息。
 * 	并且按照输入顺序，字母顺序，价格顺序（升序）进行输出
 * 知识点：1. 利用指针类型的数组对结构体排序
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

void norm_order(struct book *,int count);
void alpha_order(struct book *,int count);
void price_order(struct book *,int count);

int main(void)
{
	struct book library[MAXBKS];	//定义book类型结构的数组
	int count=0;	//计算输入了多少本书
	
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
		printf("Here is the list of your books by input order:\n");
		norm_order(library,count);
		printf("Here is the list of your books by Alpha order:\n");
		alpha_order(library,count);
		printf("Here is the list of your books by Price order(low to high):\n");
		price_order(library,count);

		


	//	for(index=0;index<count;index++)
	//		printf("%s by %s : $%.2f\n",library[index].title,library[index].author,library[index].value);
		
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

void norm_order(struct book pb[],int count)
{
	for(int index=0;index<count;index++)
		printf("%s by %s : $%.2f\n",pb[index].title,pb[index].author,pb[index].value);
		printf("\n");
}

void alpha_order(struct book pb[],int count)
{
	struct book * p_order[count];//定义指针数组用于排序(有变长数组好方便呀！)
	for(int index=0;index<count;index++)
		p_order[index]=&pb[index];
	
	//对指针进行排序
	struct book * ptemp;
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count-i-1;j++)
		{
			if(strcmp((*p_order[j]).title,(*p_order[j+1]).title)>0)
			{
				ptemp=p_order[j];
				p_order[j]=p_order[j+1];
				p_order[j+1]=ptemp;
			}
		}
	}

	for(int index=0;index<count;index++)
		printf("%s by %s : $%.2f\n",(*p_order[index]).title,(*p_order[index]).author,(*p_order[index]).value);
		printf("\n");
	

}

void price_order(struct book pb[],int count)
{
	 struct book * p_order[count];//定义指针数组用于排序(有变长数组好方便呀！)
	 for(int index=0;index<count;index++)
	 	p_order[index]=&pb[index];

	 struct book * ptemp;
	 for(int i=0;i<count;i++)
	 {
		 for(int j=0;j<count-1-i;j++)							
		 {							                       
	 		if(((*p_order[j]).value) > ((*p_order[j+1]).value))							
			{												
				ptemp=p_order[j];
				p_order[j]=p_order[j+1];
				p_order[j+1]=ptemp;
			}
		}			
	}
	for(int index=0;index<count;index++)
		printf("%s by %s : $%.2f\n",(*p_order[index]).title,(*p_order[index]).author,(*p_order[index]).value);
		printf("\n");
}
