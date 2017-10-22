/*这个文件既是对题目给出程序的复制，调用子函数make_array()和show_array*/
#include<stdio.h>
#include<stdlib.h>
int * make_array(int elem,int val);
void show_array(const int ar[],int n);	//ar[]数组加上了限定符const，表明只读

int main(void)
{
	int * pa,size,value;

	printf("Enter the numver of elements: ");
	while(scanf("%d",&size)==1 && size >0)
	{
		printf("Enter the initialization value: ");
		scanf("%d",&value);
		pa=make_array(size,value);
		if(pa)
		{
			show_array(pa,size);
			free(pa);
		}
		printf("Enter the number of elements(<1 to quit):");
	}
	printf("Done.\n");
	return 0;
}

