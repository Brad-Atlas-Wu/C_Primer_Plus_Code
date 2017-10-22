/*复习题4：
 * 	任务：计算输入的浮点数的算数平均数
 * 		如果没有命令行参数，就从终端标准输入
 * 		如果有命令行参数，那么这个参数解释为文件名，从这个文件中获得输入
 *	参考答案是用分支语句来选择fp指针，显然更加高效！！！
 * 	*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	double num;
	double sum;
	double i=0.0;	//累计输入了多少个数字
	if(argc<2)	//没有参数
	{
		printf("Please input the first num:(q to quit)\n");
		while(fscanf(stdin,"%lf",&num)==1)
		{
			i++;
			printf("Enter the next num:(q to quit) ");
			sum+=num;
		}
		
	}
	else	//有参数
	{
		 FILE * fp;
		if((fp=fopen(argv[1],"r"))==NULL)
		{
			fprintf(stderr,"Can't open file %s\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	
		while(fscanf(fp,"%lf",&num)!=EOF)
		{
			i++;
			sum+=num;
		}
		fclose(fp);
	}

	printf("算数平均数是：%.2lf\n",sum/i);
	
}
