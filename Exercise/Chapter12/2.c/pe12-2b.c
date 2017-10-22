#include"pe12-2a.h"
int main()
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode(-1 to quit)\n");
	while(scanf("%d",&mode)==1 && mode>=0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode,1 for US mode");
		printf("(-1 to quit)\n");
	}
	printf("Done.\n");

	return 0;
}
