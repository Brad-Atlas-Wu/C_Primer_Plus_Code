/* 任务：接受用户输入的单词（也就是没有分隔符的连续字符串数组），并将单词依次写入文件*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41	//数组上限，也即字符串最大字符数量+1

int main(void)
{
	FILE * fp;
	char words[MAX];		//用于记录每行输入的字符串
	if((fp=fopen("wordy","a+"))==NULL)
	{
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	puts("ENTER words to add to the file;press the # key at the beginning of a line to terminate.");
	while((fscanf(stdin,"%40s",words)==1) && (words[0]!='#'))
		fprintf(fp,"%s\n",words);

	puts("File contents:");
	rewind(fp);	//指针返回到文件开始处
	while(fscanf(fp,"%s",words)==1)
		puts(words);
	puts("Done!");
	if(fclose(fp)!=0)
		fprintf(stderr,"Error closing file\n");

	return 0;

}
