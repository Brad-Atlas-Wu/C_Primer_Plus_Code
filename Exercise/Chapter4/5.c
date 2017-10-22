#include<stdio.h>

int main()
{
	float speed;
	float size;
	printf("Please enter your net speed:\v");
	scanf("%f",&speed);
	printf("Please enter the file size\v");
	scanf("%f",&size);
	printf("At %.2f megabits per sec, a file of %.2f Megabytes\n",speed,size);
	printf("Download in %.2f sec\n",size/(speed/8.0));
	return 0;
}
