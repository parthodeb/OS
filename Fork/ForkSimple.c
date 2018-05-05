/*Frok()->used for process creation*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h> //posix API for linux and this header file is used for fork system call
int main()
{
	int p; // pid_t is data type of process_id
	printf("Hi\n");
	int i;
	p=fork(); //creates new program
	if (p<0)
	{
		printf("Error");
		}
	else if(p==0)
	{	
		exit(0);
		printf("child having pid %d \n",getpid());
		printf("My parent's pid %d \n",getppid()); //getppid- get id of parent
		}
	else
	{
		wait(0);
		//sleep(1);
		printf("Parent having pid %d \n",getpid());
		printf("My child's pid is %d \n",p); // p has id of child given by fork system call
		sleep(1);
	}
	printf("\n Common\n");
}
