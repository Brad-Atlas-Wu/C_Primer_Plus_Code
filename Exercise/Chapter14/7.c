/*任务： 程序在例题14_14.c的基础上添加了两个功能：
 * 	1. 删除指定记录
 * 	2. 修改指定记录
 *
知识点： 1. 从文件读取/存入结构（fread/fwrite）
	 2. 把二进制文件内容输出到屏幕上(关键在于清楚文件指示器当前指向的位置！)
算法：
	showmenu()显示用户选项菜单
	while(选项有效)
		要求用户输入书名
		执行用户选择的操作
	
	删除记录：
		拷贝文件，跳过用户输入书名相匹配的记录
		删除源文件
		副本文件改名

	修改记录：
		重写覆盖要修改的记录
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXAUTL 40 
#define MAXTITL 40
#define MAXBK	40//最大书籍数量
#define FILE_NAME "book.dat"

struct book{//定义结构模板
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char *,int);
void show_menu(void);
int get_filecount(void);
int add_books(struct book *,int);
void add_to_file(struct book *);


size_t size=sizeof(struct book);
int main(void)
{
	int filecount;
	struct book library[MAXBK];

	filecount=get_filecount();

	show_menu();
	char choice;
	while((choice=getchar())!='q')
	{
		switch(choice)
		{
			case 'a':filecount=add_books(library,filecount);break;
			//case 'd':
			//case 'm':
			//default:
		}
	}
		
	puts("Bye");
	return 0;
}

int add_books(struct book * library,int count)
{
	int init_count=count;
	if(count==MAXBK)
	{
		fprintf(stderr,"File book.dat is full!\n");
		exit(EXIT_FAILURE);
	}
	puts("Please enter the title: ");
	puts("Press [enter] at a new line to quie.");
	while(count<MAXBK && s_gets(library[count].title,MAXTITL)!=NULL && library[count].title[0]!='\0')
	{
		puts("Now enter the author: ");
		s_gets(library[count].author,MAXAUTL);
		puts("Now enter the value:");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')continue; //清除多余字符
		printf("Enter the next book title:\n");
	}
	
	add_to_file(library);
	printf("%d books appended!\n",count=init_count);
	
	return count;
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
	
	return ret_val;											
}

int get_filecount(void)
{
	FILE * fp;
	int n;
	if((fp=fopen(FILE_NAME,"w+"))==NULL)
	{
		fprintf(stderr,"Can't open file %s\n","book.dat");
		exit(EXIT_FAILURE);
	}
	fseek(fp,0,SEEK_END);
	n=ftell(fp)+1;
	fclose(fp);
	return n;
	
}

void show_menu(void)
{
	printf("\n*********************************************\n");
	printf("Please enter your choice:\n");
	printf("a) add new books\td)delete books\nm)modify datas\tq)quit\n");
	printf("\n*********************************************\n");

}

void add_to_file(struct book * books)
{
	FILE * pf;
	if((pf=fopen(FILE_NAME,"wb"))==NULL)
	{
		fprintf(stderr,"Can't open file %s\n","book.dat");
		exit(EXIT_FAILURE);						          
	}
	rewind(pf);
	while(fwrite(books,size,1,pf)!=0)
		;
	fclose(pf);
}
