
#include<unistd.h>
#include<stdio.h>
int main()
{

	char buff[50];
	int r[2];
	pipe(r);
	pid_t f;
	f=fork();
	
	if(f==0)
	{
		read(r[0],buff,15);
		printf("%s\n",buff);
	}
	else if(f==-1)
	{
		printf("Error..");
	}
	else
	{
		write(r[1],"Welcome to LPU",15);
	}

}