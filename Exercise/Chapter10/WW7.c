#include<stdio.h>
#define ROW 3
#define COLUM 6
void opy_arr(double *,double *,int);
void copy_ptr(double * , double * , int n);
void copy_ptrs(double * t,double * pstart,double * pend);
int main(void)
{
	double array[ROW][COLUM]=
	{
		{1.2,3.4,9.8,5.3,9.0,6.4},
		{3.4,6.8,6.3,0.9,8.9,7.3},
		{1.2,3.6,8.0,7.5,1.4,8.9}

	};
	double target[ROW][COLUM];

//*************************************************************************
	for(int i=0;i<ROW;i++)
	{
		opy_arr(target[i],array[i],COLUM);
	}

	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COLUM;j++)
		{
			printf("%lf ",target[i][j]);
		}
		printf("\n");
	}
	printf("\n");
//************************************************************************************
	for(int i=0;i<ROW;i++)
        {
                copy_ptr(*(target+i),*(array+i),COLUM);		//这前面的*非常重要，target+i是target[i]的地址，
        }							//是一个指向内含六个元素数组的指针
								//而*(target+i)是target[i][0]的地址，
        for(int i=0;i<ROW;i++)					//是一个指向数组target[i]的指针
        {
                for(int j=0;j<COLUM;j++)
                {
                        printf("%lf ",target[i][j]);
                }
                printf("\n");
        }
	printf("\n");
//***************************************************************************************************

	for(int i=0;i<ROW;i++)
        {
                copy_ptrs(*(target+i),*(array+i),*(array+i)+COLUM);
        }

        for(int i=0;i<ROW;i++)
        {
                for(int j=0;j<COLUM;j++)
                {
                        printf("%lf ",target[i][j]);
                }
                printf("\n");
        }

//**************************************************************************
	return 0;
}

void opy_arr(double a[],double b[],int n)	//使用数组表示法
{
	for(int i=0;i<n;i++)a[i]=b[i];
}


void copy_ptr(double * t, double * s, int n)	//指针和数组大小表示法
{
        while(n--)
        {
                *t++=*s++;                   
        }                                                                                                                                                            
}


void copy_ptrs(double * t,double * pstart,double * pend) 	//指针和数组开头指针，结尾指针表示法
{
	while(pstart<pend)
	{
		*t++=*pstart++;
	}
}

