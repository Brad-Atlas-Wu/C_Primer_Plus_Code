#include<stdio.h>

int main()
{
	char note;	//表示每行开头的字母
	int i,j,n,step;	//n用于表示每行开头字母的差值，而step是这些差值的差值（这个地方应该要完善算法）
	for(n=0,step=0,i=0;i<6;i++,step++)
	{
		n+=step;
		for(note='A'+n,j=0;j<i+1;j++)
		{
			
			printf("%c",note++);
		}
		printf("\n");
	}
return 0;
}
