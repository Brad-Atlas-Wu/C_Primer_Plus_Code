#include<stdio.h>
void chline(char ch,int i,int j);
int main()
{	
	char ch;
	int i,j;
	printf("Enter the char:\n");
	ch=getchar();
	printf("Enter the row:\n");
	scanf("%d",&i);
	printf("Enter the colum:\n");
	scanf("%d",&j);
	chline(ch,i,j);
	return 0;
}

void chline(char ch, int row,int colum)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<colum;j++)
			putchar(ch);
		printf("\n");
	}
	return;
}


