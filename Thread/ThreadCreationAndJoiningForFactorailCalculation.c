#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>

void *thfunction(int arg);
char var[100]="\n Welcome \n";
int main()
{
	int r;
	void *th_result;
	int No;
	printf("Enter the number for which u want to find factorial");
	scanf("%d",&No);
	pthread_t mythread;
	r=pthread_create(&mythread,NULL,thfunction,No);
	if(r!=0)
	{
		printf("\n Thread creation failed");
		exit(EXIT_FAILURE);
	}
	//printf("\n Waiting for thread to join");
	int s=pthread_join(mythread,&th_result);
	if (s!=0)
	{printf("\nThread join failure");
		exit(EXIT_FAILURE);
	}
	printf("\nThread has joined & it is returning Factorial is:- %d \n",(int*)th_result);
	
	exit(EXIT_FAILURE);
	}

void *thfunction(int arg)
{
	printf("\nThread's function is running and argument is %d \n",(int*)arg);
	int fact=1,i;
	for(i=1;i<=arg;i++)
	{
		fact=fact*i;
	}
	printf("Factorial is %d ",fact);
	pthread_exit(fact);
}
