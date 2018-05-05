
#include<sys/stat.h>
int main()
{
	int r;
	r=mkfifo("myfifo1",0777);
	if (r==0)
	{
		printf("Created\n");
	}
	else
	{
		printf("--Error\n");
	}
	
	
}