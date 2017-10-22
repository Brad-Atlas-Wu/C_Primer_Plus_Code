/*任务：提示用户输入一个文件和一个文件位置，程序打印从文件位置到换行符之前的内容
 * 	用户输入非数字支付或者负数来退出程序
 *
 * 知识点：文件的随机访问（二进制）（同见例题13.6）
 *
 * 算法：
 * 	提示用户输入文件名
 * 		以rb模式打开并检验文件
 *
 * 	提示用户输入文件位置
 * 	while(位置为非负整数)
 * 		fseek定位
 * 		while(fread读入字符且不是'\n')
 * 			fwrite输出到屏幕
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81	//文件名长度+1

char * s_gets(char * name,int n);
int main(void)
{
	FILE * fp;
	char filename[LEN];	//文件名
	long pos;	//文件位置偏移量
	char ch;
	
	printf("Enter a file name: \n");
	s_gets(filename,LEN);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		fprintf(stderr,"Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter a postion num: ");
	while(scanf("%ld",&pos)==1 && pos>=0)
	{
		fseek(fp,pos,SEEK_SET);
		//这里看到，其实是可以一个个字符访问的，很灵活	
		while(fread(&ch,sizeof(char),1,fp)==1 && ch!='\n')
			fwrite(&ch,sizeof(char),1,stdout);
		putchar('\n');
		printf("Enter the next position(负数或字符退出): ");
	}
	return 0;
}

char * s_gets(char name[],int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(name,n,stdin);
	find=strchr(name,'\n');
	if(find)*find='\0';
	else while(getchar()!='\n')continue;
	
	return ret_val;
}
