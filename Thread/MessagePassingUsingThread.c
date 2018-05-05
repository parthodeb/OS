#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>

void *thfunction(void *arg);
char var[100]="\n WElcome \n";
int main()
{
	int r;
	void *th_result;
	pthread_t mythread;
	r=pthread_create(&mythread,NULL,thfunction,(void*)var);
	if(r!=0)
	{
		printf("\n Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("\n Waiting for thread to join");
	int s=pthread_join(mythread,&th_result);
	if (s!=0)
	{
	    printf("\nThread join failure");
		exit(EXIT_FAILURE);
	}
	printf("\nThread has joined & it is returning %s \n",(char*)th_result);
	printf("\nMessage is %s \n",var);
	exit(EXIT_FAILURE);
	}
	
void *thfunction(void *arg)
{
	printf("\nThread's function is running and argument is %s \n",(char*)arg);
	strcpy(var,"Done");
	pthread_exit("\nThank you");
	//pthread_exit("Thanks");
}







	
