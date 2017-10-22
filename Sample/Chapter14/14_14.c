/*任务： 建立一个书单文件：1用户可以往文件中新添书单（作者，书名，价格）2.显示书单文件内容
 * 	注意：我对原题做了修改：
 * 		原题是把添加的书单内容放入结构数组，然后存入文件，并且输出结构数组的内容
 * 		而我是把结构数组存入文件后，输出文件内容（这样才知道有没有成功写入）
 *
知识点： 1. 从文件读取/存入结构（fread/fwrite）
	 2. 把二进制文件内容输出到屏幕上(关键在于清楚文件指示器当前指向的位置！)
算法：
	定义结构数组（用来暂时储存书单中的内容）
	
	打开并检测书单文件（a+b模式）
	判断书单是否已经满了
		是：结束程序
		否：继续
	fread()内容读入结构数组
	filecount记录读了多少个结构（便于在文件后面追加新内容）

	判断：书单是否已经满了？
			是：退出
			否：继续
	
	whiel(获得并判断用户输入的内容，直到书单满或者空行或者输入无效)

	fwrite把新添加的结构数组写入文件

	文件中是否有内容？
	有=》
显示文件内容：
	**文件指示器指向文件开头**
	定义临时结构体temp
	while(fread读取内容到temp,知道文件结尾)
		printf()输出到屏幕
	关闭文件

	无=》提示没有内容
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXAUTL 40 
#define MAXTITL 40
#define MAXBK	40//最大书籍数量
char * s_gets(char *,int);
struct book{//定义结构模板
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	FILE * pbooks;
	int count=0;
	int filecount;
	struct book library[MAXBK];
	size_t size=sizeof(struct book);
		
	if((pbooks=fopen("book.dat","a+b"))==NULL)
	{
		fprintf(stderr,"Can't open file %s\n","book.dat");
		exit(EXIT_FAILURE);
	}
	
	rewind(pbooks);
	while(count<MAXBK && fread(&library[count],size,1,pbooks)==1)
	{
		count++;
	}

	filecount=count;//=>记录文件中有多少个结构

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
		while(getchar()!='\n')continue;	//清除多余字符
		
		printf("Enter the next book title:\n");
	}

	if(count>filecount)
	{
		fwrite(&library[filecount],size,count-filecount,pbooks);
	}
	
	rewind(pbooks);
	if(count>0)
	{

		struct book temp;
		while(fread(&temp,size,1,pbooks)!=0)
			printf("%s by %s is $%.2f\n",temp.title,temp.author,temp.value);
		/*struct book temp[count];
		for(int i=0;i<count;i++)
		{
			(fread(&temp[i],size,1,pbooks)!=0);
			printf("%s by %s is $%.2f\n",temp[i].title,temp[i].author,temp[i].value);
		}*/

	}
	puts("Bye");
	fclose(pbooks);
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

