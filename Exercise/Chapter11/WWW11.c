/*
 *	定义一个二维数组，储存最多是个字符串
 *	while(字符串数量小于10且没有遇到文件结尾)读取字符串
 *		输出选项菜单，接受用户输入
 *			如果输入为q,结束程序
 *			否则按用户选择分别调用不同的函数打印
 *	
 *	子函数中定义新的指针，按用户要求的顺序指向原字符串（这样就是只排列指针，而不改变字符串！）
 *
 *	程序问题：1. 对于按照字符串长度输出的子函数，最好能够把一个tab字符看成是八个字符长度而不是一个字符
 *		  2. 在使用输入重定向进行输入的时候程序会发生错误(无限循环，应该是输入流的问题)
 *		  3. 根据第一个单词长度输出字符串的函数还有问题，似乎无法跳过开头的空白符号!(解决:原来是忘记回归stat值)
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ROW 10
#define COLUM 100		//因为是二维字符数组，所以定义的是一个指向数组的指针
void origin_output(char (*)[COLUM],int);		//输出源字符串
void asc_output(char (*)[COLUM],int);		//按ASCII顺序输出字符串
void lenth_output(char (*)[COLUM],int);		//按照字符串长度输出字符串
void firword_output(char (*)[COLUM],int);		//按照第一个单词长度输出字符串
char get_choice(void);				//获取并检查用户选项

int main(void)
{
	char str[ROW][COLUM];	//定义一个数组接受用户输入的字符串
	char choice;		//记录用户的输出顺序选项
	int nstr=0;		//累计用户输入了多少个字符串
//接受用户输入的字符串
	while(nstr<ROW && fgets(str[nstr],COLUM,stdin))		//可以看出，当fgets遇到文件结尾的时候返回NULL
	{
		nstr++;						//计算输入了多少个字符串
	}

//根据输入的选项执行相应的输出结果
	while((choice=get_choice())!='q')	
	{
		switch(choice)
		{
			case 'a':origin_output(str,nstr);break;
			case 'b':asc_output(str,nstr);break;
			case 'c':lenth_output(str,nstr);break;
			case 'd':firword_output(str,nstr);break;
		}
	}
	printf("BYE!\n");
	return 0;
}

//获取用户的选项，如果无效，要求重新输入。如果有效，则返回选项。
char get_choice(void)
{
	int ch;
	//输出列表
	printf("**************************************************************\n");
	printf("请选择输出顺序\n");
	printf("a.输出源字符串\tb.按ASCII顺序输出字符串\nc.按照字符串长度输出字符串\td.按照第一个单词长度输出字符串\n");
        printf("q.退出\n");
        printf("**************************************************************\n");
	//接受并且判断用户的选项
	while((ch=getchar())!='a' && ch!='b' && ch!='c' && ch!='d' && ch!='q')
	{
		printf("输入选择无效!请重新选择\n");
		printf("**************************************************************\n");
	        printf("请选择输出顺序\n");
        	printf("a.输出源字符串\tb.按ASCII顺序输出字符串\nc.按照字符串长度输出字符串\td.按照第一个单词长度输出字符串\n");
        	printf("q.退出\n");
        	printf("**************************************************************\n");
	}
	while(getchar()!='\n')continue;       //处理多余的无效字符
	return ch;
}
//按照原来顺序输出
void origin_output(char (* p)[COLUM],int nstr)
{
	for(int i=0;i<nstr;i++)
		fputs(p[i],stdout);	
}

//按照ascii顺序排列输出
//需要用到strcmp函数进行比较
void asc_output(char  str[][COLUM],int nstr)	//第一个形参写成数字格式是为了强调这是一个字符串数组
{
	char * p[ROW];	//重点：处理字符串的时候，用到了指针数组而不是指向数组的指针！
			//因为下面要处理的排序问题需要一个数组记录每个行开头的地址，需要的不仅是一个指针，而是一个指				针数组
			//当然这个指针数组并不知道他指向的行是一个多长的数组，只负责记录一个首地址而已。
			//数组的每个元素存储对应字符串行的首地址
	char * temp;	
	for(int i=0;i<nstr;i++)		//将指针数组初始化，指向每行字符串的首元素
	{
		p[i]=str[i];
	}

	for(int i=nstr;i>0;i--)		//对比字符串的ascii码，利用冒泡法对指针进行重新排序
	{
		for(int j=1;j<i;j++)
		{
			if((strcmp(p[j-1],p[j]))>0) //如果前面的字符串大于后面的字符串
	                {
                			temp=p[j-1];
					p[j-1]=p[j];
					p[j]=temp;		        
        	        }

		}
	}
	
	for(int i=0;i<nstr;i++)		//按照指针指向的顺序输出字符串
	{
		fputs(p[i],stdout);
	}
}

//按照字符串长度排列输出
//需要用到strlen()函数
/*
 *	定义数组储存各个字符串的长度
 *	对比字符串长度，将最长字符串的下表按顺序赋给指针数组
 *		然后将最大值归-1，将最长的字符串数目归-1，再循环对比
 * */
void lenth_output(char str[][COLUM],int nstr)	
{
	char * p[ROW];		//定义指针数组
	int lenth[ROW];
	
	for(int i=0;i<nstr;i++)		//记录每个字符串的长度
	{
		lenth[i]=strlen(str[i]);
	}

	int submark;
	int j=0;
	for(int i=0;i<nstr;i++)
	{
		int max=-1;	//因为最大长度不可能是-1，比较安全
		for(int i=0;i<nstr;i++)	//获得当前剩余字符串的最大字符数量的字符串下标
		{
			if(lenth[i]>max)
			{
				max=lenth[i];
				submark=i;	
			}	
		}
		p[j++]=str[submark];	
		lenth[submark]=-1;	//将刚刚最大的数目设为-1，再从剩余的字符数目中找最大。
	}
	
	for(int i=0;i<nstr;i++)fputs(p[i],stdout);
}


//按照第一个单词长度输出字符串
//需要判断一个单词的开始和结束，应该要跳过开头的空白符号，并且判断以空白符号结束
/*
 *定义int类型字符串记录每个字符串第一个单词的长度
 * 对于每一个字符串计数:
 * 	跳过开头的字符串不算
 * 	遇到第一个有效字符的时候，开始计算
 * 	遇到结尾空白，结束计算，把数字赋给对应的字符串元素
 *
 * 对比所有字符串第一个单词的长度，指针数组按顺序指向，最后输出
 * */
void firword_output(char str[][COLUM],int nstr)
{	
	_Bool stat=0;		//未遇到单词
	int nword[ROW];	//定义了一个变长数组
	char * p[ROW];

	//计算并储存每一个字符串第一个单词的长度
	for(int i=0;i<nstr;i++)	//循环对每个字符串执行
	{
		int j=0;
		int n=0;		//用于计算各个字符串第一个单词的字符数目
		_Bool stat=0;
		while(str[i][j]!='\0')		//在遇到字符串结尾之前执行
		{	
			if(stat==0 && isspace(str[i][j]))j++;	//跳过开头的空白
			else if(isspace(str[i][j]))		//遇到单词的结束
			{
				nword[i]=n;
				break;
			}
			else 					//在第一个单词中
			{
				n++;
				j++;
				stat=1;				
			}				
		}
	}
		for(int i=0;i<nstr;i++)
		{
			printf("%d\n",nword[i]);
		}

	//根据第一个单词的长度对指向字符串的指针进行排序
	int submark;
	int j=0;
	for(int i=0;i<nstr;i++)
	{
		int max=-1;     //因为最大长度不可能是-1，比较安全
		for(int i=0;i<nstr;i++) //获得当前剩余字符串的最大字符数量的字符串下标
        	{
			if(nword[i]>max)
			{
				max=nword[i];
				submark=i;
			}
		}
		p[j++]=str[submark];
		nword[submark]=-1;      //将刚刚最大的数目设为-1，再从剩余的字符数目中找最大。
	}
	for(int i=0;i<nstr;i++)fputs(p[i],stdout);
}		
