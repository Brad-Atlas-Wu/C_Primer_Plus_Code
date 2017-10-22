/*本程序是对例题13.3的修改。按照单词写入的顺序为单词编号。确保下次运行程序时单词序号是之前的继续
 *	程序的关键点在于：**每次运行程序的时候，程序都需要知道之前已经有多少个单词，或者说知道当前的最大序号是多少
 *	以便能够在序号的基础上继续。**
 *
 * 知识点：统计文件中的单词数量
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41	//数组上限，也即字符串最大字符数量+1

int main(void)
{
	FILE * fp;
	char words[MAX];		//用于记录每行输入的字符串
	int num=0;	//用于标记单词序号
	if((fp=fopen("wordy","a+"))==NULL)
	{
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	puts("ENTER words to add to the file;press the # key at the beginning of a line to terminate.");
/*********************************************************/
	//计算之前输入了多少个单词
	while(fscanf(fp,"%40s",words)==1)num++;
/*********************************************************/

	while((fscanf(stdin,"%40s",words)==1) && (words[0]!='#'))
	{	
		fprintf(fp,"%d.%s\n",++num,words);
	}

	puts("File contents:");
	rewind(fp);	//指针返回到文件开始处
	while(fscanf(fp,"%s",words)==1)
		puts(words);
	puts("Done!");
	if(fclose(fp)!=0)
		fprintf(stderr,"Error closing file\n");

	return 0;

}
