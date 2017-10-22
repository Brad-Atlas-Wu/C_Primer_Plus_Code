#include<stdio.h>

int main()
{
	char note;
	int i,j;
	
	for(i=0;i<6;i++)
	{
		for(note='F',j=0;j<i+1;j++,note--)
			printf("%c",note);
		printf("\n");

	}
	return 0;
}
