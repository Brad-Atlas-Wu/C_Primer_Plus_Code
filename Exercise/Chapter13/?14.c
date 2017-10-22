/*任务：在程序12.c的基础上，处理失真数据
 * 	如果数值和其上下左右的相邻值得差都大于1，那么用相邻值得平均数（四舍五入为整数）替代该值
 * 	注意位于边界的值要特殊处理
 
*知识点:

问题：自己的算法太复杂，几何没学好~~~有空再研究吧哈哈哈

处理失真的算法：
	复制副本数组（完成失真处理前不改变原数组内容）
	用循环遍历所有副本数组元素
	是不是边界值？
		不是：
			对比在原数组中的4个相邻值，如果相差都大于1，取平均值并代替（除以4）
		是：是边线值还是边角值？
			边线：对比原数组的3个相邻值，如果相差都大于1，取平均值并代替（除以3）
			边角：对比原数组的2个相邻值，如果相差都大于1，取平均数并代替（除以2）
	
 
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

