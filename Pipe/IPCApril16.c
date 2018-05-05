
#include<unistd.h>
#include<stdio.h>
int main()
{

	char buff[50];
	int r[2];
	pipe(r);
	pid_t f;
	f=fork();
	
	if(f==-1)
	{
		printf("Error\n");
	}
	else if(f==0)
	{
		
		write(r[1],"Weelcome to LPU",6);
	}
	else
	{

		read(r[0],buff,6);
		printf("%s\n",buff);
	}
}
