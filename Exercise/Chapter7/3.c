#include<stdio.h>

int main()
{
	int n;
	long n_even,n_odd;
	double ave_even,ave_odd;
	n_even=n_odd=0;
	ave_even=ave_odd=0;
	printf("Please enter int nums  0 to quit\n");
	while(scanf("%d",&n)==1 && n!=0)
	{
		if(n%2==0)
		{
			n_even++;
			ave_even+=n;
		}
		else
		{
			n_odd++;
			ave_odd+=n;
		}
	}
	printf("There are %d even and %d odd\n",n_even,n_odd);
	printf("The ave of even is %lf, and the ave of odd is %lf\n",ave_even/n_even,ave_odd/n_odd);
}
