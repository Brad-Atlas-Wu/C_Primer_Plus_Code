#include<stdio.h>
#include<stdlib.h>

void order(int *); 

int main(void)
{
	int * p;
	p=(int *)malloc(100*sizeof(int));
	for(int i=0;i<100;i++)p[i]=rand()%10+1;
	
	printf("输出原始数据:\n");	
	for(int i=0;i<100;i++)	//输出原始数据
	{
		printf("%3d",p[i]);
		if((i+1)%10==0)printf("\n");
	}
	order(p);	//进行降序排序
	
	printf("输出排序之后的数据:\n");
	for(int i=0;i<100;i++)  //输出排序后的结果
        {
                printf("%3d",p[i]);
                if((i+1)%10==0)printf("\n");
        }
	
	return 0;
}

void order(int * p)
{
	int t;
	for(int i=1;i<100;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(p[j]<p[i])
			{
				t=p[j];
				p[j]=p[i];
				p[i]=t;
			}
		}		

	}
}
