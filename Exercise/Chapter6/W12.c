//按原题的意思，序列应该收敛于一个值，所以程序可能有问题

#include<stdio.h>
#include<math.h>

int main()
{
	double sum_A=0.0;
	double sum_B=0.0;
	double limit;
	printf("Please enter the limit:\n");
	scanf("%lf",&limit);

	
//	printf("Sum of ");			//第一个数列
	for(double n=1.0;n<limit+1.0;n+=1.0)
	{	
		sum_A+=1.0/n;
//		printf("1.0/%.1lf+",n);
	}
//	printf("\b"); 	//用这个转义符来去掉最后多出来的+
//	printf(" is  %lf\n",sum_A);
	

//	printf("Sum of ");	//第二个数列
	for(double n=1.0;n<limit+1.0;n+=1.0)
        {
		if(((int)n)%2==0)
		{
			sum_B-=1.0/n;
//			printf("1.0/%.1lf+",n);
		}
		else
		{
			sum_B+=1.0/n;
//                      printf("1.0/%.1lf-",n);
		}
        }
//      printf("\b");   //用这个转义符来去掉最后多出来的+
//      printf(" is  %lf\n",sum_B);

	printf("\nSum_A: %lf\tSum_B: %lf\n",sum_A,sum_B);
	return 0;
}
