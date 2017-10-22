/*
 *	任务：程序演示二进制件的随机访问（fseek定位，fread/fwrite读写）
 *	
 *	知识点：1.（fseek定位，fread/fwrite读写）
 *		
 *
 * 	算法：
 * 		二进制写模式打开文件并检测
 * 			fwrite把数组中的内容写入文件
 * 			关闭文件
 *		
 *		二进制读模式打开文件并检测
 * 		用户输入要访问的位置i
 * 			根据i计算fseek的偏移量pos
 * 			根据pos用fseek定位
 * 			fread()读取该位置的值，输出
 * 		关闭文件
 * 			
 * 			
 * 			
 * 		
 * */

#include<stdio.h>
#include<stdlib.h>
#define ARSIZE	1000	//数组的大小

int main()
{
	double numbers[ARSIZE];	//定义数字
	double value;	//用于记录访问位置的值
	const char * file="numbers.dat";	//文件名首地址
	int i;
	long pos;	//偏移量（注意是L类型的）
	FILE * iofile;	//文件指针

	//创建一组double 类型的值,初始化
	for(i=0;i<ARSIZE;i++)
		numbers[i]=100.0*i+1.0/(i+1);

	//打开文件
	if((iofile=fopen(file,"wb"))==NULL)
	{
		fprintf(stderr,"Could not open %s for output.\n",file);
		exit(EXIT_FAILURE);
	}

	//以二进制格式把数组写入文件
	fwrite(numbers,sizeof(double),ARSIZE,iofile);
	fclose(iofile);		//这里先关闭文件，使缓冲区中剩余的数据都写入到文件中
	
	if((iofile=fopen(file,"rb"))==NULL)
	{
		fprintf(stderr,"Counld not open %s for random access.\n",file);
		exit(EXIT_FAILURE);
	}

	//从文件中读取选定的内容
	printf("Enter an index in the range 0_%d.\n",ARSIZE-1);
	while(scanf("%d",&i)==1 && i>=0 && i<ARSIZE)
	{
		pos=(long) i * sizeof(double);	//计算偏移量
		fseek(iofile,pos,SEEK_SET);	//定位到此处
		fread(&value,sizeof(double),1,iofile);
		printf("The value there is %f.\n",value);
		printf("Next index (out of range to quit):\n");
	}
	//完成
	fclose(iofile);
	puts("Bye!");

	return 0;
}
