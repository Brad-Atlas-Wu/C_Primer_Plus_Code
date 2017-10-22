/*任务：将一个20行30列的包含0~9的数字矩阵转换成灰度，方法是每个数字对应不同的符号输出~~~比如0为空格，9为#
 * 	可以通过命令行获得文件名，输出文件为文件名.img
 
*知识点：1.一次读取一个Int类型数据fscanf(fp1,"%1d",&n)
	 2. 添加后缀名
	 3.略微窥见图像输出原理

答案:  答案的优越出在于:在选择是哪个数字对应哪个符号输出的时候,首先定义并初始化了数组: const char tran[LEVEL+1]=”!@##$%”，然后将之前读入的数字作为下标以此输出，相比我自己所用的switch语句要简洁高效得多

 * 算法：
 * 	命令行获得并且检验参数
 * 	打开并且检验文件
 * 	创建文件.img, w模式打开
 * 	逐个读取数字，并且存入20*30的int类型数组中
 * 	转换int类型数组元素，存入20*31的字符串数组中
 *	输出字符串数组内容到.img文件和屏幕上
 * 	关闭两个文件
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 81	//文件名长度+1
#define LINE 20	//数组行
#define ROW 30	//数组列

int main(int argc, char * argv[])
{
	FILE * fp1,* fp2;	//fp1为源文件，fp2为转换后的输出
	int n;		//记录读取的数字
	char filecp[SIZE];	//输出文件的文件名
	int data[LINE][ROW];	//数组用于储存20*30的数字数据
	char img[LINE][ROW+1];	//储存转换之后的字符数组

	//初始化数字数组为0
	for(int i=0;i<LINE;i++)
	{
		for(int j=0;j<ROW;j++)
			data[i][j]=0;
	}
	if(argc!=2)
	{
		fprintf(stderr,"Usage: ./aout filename\n");
		return 1;
	}
	//添加后缀名
	strncpy(filecp,argv[1],SIZE-4);
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
	while(i<LINE && j<ROW && (fscanf(fp1,"%1d",&n)==1))
	{
		data[i][j++]=n;
		if(j==ROW)
		{
			j=0;
			i++;
		}
	}

	//转换数字内容，并存入数组
	for(int i=0;i<LINE;i++)
	{
		int j=0;
		for(;j<ROW;j++)
		{
			switch(data[i][j])
                        {
                        	case 0:img[i][j]=' ';break;
                                case 1:img[i][j]='.';break;
                                case 2:img[i][j]='^';break;
                                case 3:img[i][j]='-';break;
                                case 4:img[i][j]='+';break;
                                case 5:img[i][j]='*';break;
                                case 6:img[i][j]='%';break;
                                case 7:img[i][j]='&';break;
                                case 8:img[i][j]='$';break;
                                case 9:img[i][j]='#';break;
                                default:break;
                         }
		}
		img[i][j]='\0';		//给每行字符串结尾
	}


	//把转换后的字符数字写入.img文件中,并显示在屏幕上
	for(int i=0;i<LINE;i++)
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

