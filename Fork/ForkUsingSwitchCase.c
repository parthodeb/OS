/*Frok()->used for process creation*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h> //posix API for linux and this header file is used for fork system call
int main()
{
	pid_t p; // pid_t is data type of process_id
	p=fork(); //creates new program
	int i;
	switch(p)
	{
		case -1: printf("Error:Process cannot be created");
			break;
		case 0:  //child is executing
			
			//sleep(100);
			printf("\nI am child having id %d \n",getpid());
			printf("My parent's id is %d \n",getppid()); //getppid- get id of parent
			break;
		default: //parent is execution
			sleep(20);
			//wait();
			printf("I am parent having id %d \n",getpid());
			printf("My child's id is %d \n",p); // p has id of child given by fork system
			break;
		}
	}
