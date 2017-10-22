#include<stdio.h>

int main()
{	
	char name[15],c;
	int i;
	i=0;
	printf("Please enter your name:\v");
	while(i<15 && ((c=getchar())!='\n'))
	{
		name[i]=c;
		i++;
	}
	name[i]='\0';
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	printf("\"   %s\"\n",name);
	
        return 0;
}
	
