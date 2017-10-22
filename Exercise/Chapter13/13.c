/*任务:在练习13.c的基础上改用变长数组VLA.
 * 	我这里都在main函数中完成操作，如果要调用子函数，就需要在用参数传递变长数组之前传递行列信息
 * 	
*知识点：1.变长数组

 * 算法：
 * 	命令行获得并且检验参数
 * 	打开并且检验文件
 * 	创建文件.img, w模式打开
 * 	逐个读取数字，并且存入20*30的int类型数组中
 * 	转换int类型数组元素，存入20*31的字符串数组中
 *	输出字符串数组内容到.img文件和屏幕上
 * 	关闭两个文件
 * */
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define SIZE 81	//文件名长度+1
//#define LINE 20	//数组行
//#define ROW 30	//数组列

int main(int argc, char * argv[])
{
	int size=81;
	int line=20;
	int row=30;
	FILE * fp1,* fp2;	//fp1为源文件，fp2为转换后的输出
	int n;		//记录读取的数字
	char filecp[size];	//输出文件的文件名
	int data[line][row];	//数组用于储存20*30的数字数据
	char img[line][row+1];	//储存转换之后的字符数组
	char trans[]=" !@#$%^&*(";

	//初始化数字数组为0
	for(int i=0;i<line;i++)
	{
		for(int j=0;j<row;j++)
			data[i][j]=0;
	}
	if(argc!=2)
	{
		fprintf(stderr,"Usage: ./aout filename\n");
		return 1;
	}
	//添加后缀名
	strncpy(filecp,argv[1],size-4);
	strcat(filecp,".img");

	//打开两个文件
	if((fp1=fopen(argv[1],"r"))==NULL)
	{	
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	  if((fp2=fopen(filecp,"w"))==NULL)
        {
                fprintf(stderr,"Can't open file %s\n",filecp);
                exit(EXIT_FAILURE);
        }

	//文件内容读入到int类型数组
	int i,j;
	i=j=0;
	while(i<line && j<row && (fscanf(fp1,"%1d",&n)==1))
	{
		data[i][j++]=n;
		if(j==row)
		{
			j=0;
			i++;
		}
	}

	//转换数字内容，并存入数组
	for(int i=0;i<line;i++)
	{
		int j=0;
		for(;j<line;j++)
		{
      			img[i][j]=trans[data[i][j]]; 
		}
		img[i][j]='\0';		//给每行字符串结尾
	}

	//把转换后的字符数字写入.img文件中,并显示在屏幕上
	for(int i=0;i<line;i++)
	{
		puts(img[i]);
		fputs(img[i],fp2);
		putc('\n',fp2);
	}
	

	if(ferror(fp1))
	{       
		fprintf(stderr,"Failed reading file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	if(ferror(fp2))
        {
                fprintf(stderr,"Failed reading file %s\n",filecp);
                exit(EXIT_FAILURE);
        }

	fclose(fp1);
	fclose(fp2);
	return 0;
}

