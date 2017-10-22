/*本题是在题目2的基础上进行修改，要求只使用自动变量，那么就是在数值通过函数的参数进行传递*/
#include"pe12-2a.h"
int main()
{
	int mode;
	/*这个地方我开始犯了一个错误，直接定义了两个指针：p_d,p_c分别希望指向距离和耗油量的地址
 * 		然后把p_d,p_c作为函数get_info()的参数希望获得用户输入的distance和consumption
 * 		但是编译之后在输入distance的时候就已经提示段错误
 * 		  其实原因很简单，我定义了指针p_d，这个指针指向哪里呢？不知道！我作为参数传递过去，
 * 		那用户输入的距离最后存储在哪里呢？不知道！！！所以，就会出现内存越界的错误。
 *		   正确的做法是：想定义变量distance和consumption,这样程序就给距离和耗油量分配了一个固定
 *		的地址了，这个时候再通过&distance把地址传递给参数，就不会出现问题了！
 *		   当然，如果我是想通过函数改变指针指向的地址，而不是指针指向地址总的数据，那么，
 *		指针初始指向哪里就不重要了，也不会出现问题。但是在本例中，我是想要改变数据的~~
 * 	*/
	double distance;	//用户输入的里程		
	double consumption;	//用户输入的耗油量
	int premode=0;		//用来记录上次输入的模式,初始化为0（避免第一次就输入错误而premode为任意值）
	printf("Enter 0 for metric mode, 1 for US mode(-1 to quit)\n");
	while(scanf("%d",&mode)==1 && mode>=0)
	{
		mode=set_mode(mode,premode);
		premode=mode;
		get_info(mode,&distance,&consumption);
		show_info(mode,distance,consumption);
		printf("Enter 0 for metric mode,1 for US mode");
		printf("(-1 to quit)\n");
	}
	printf("Done.\n");

	return 0;
}
