#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *f1();
void *f2();
int x;
int y;
int main()
{
	printf("Enter the value of x :- ");
	scanf("%d",&x);
	printf("Enter the value of y :- ");
	scanf("%d",&y);
	pthread_t thread1;
	
	pthread_create(&thread1,NULL ,f1,x);
	
	pthread_join(thread1,NULL);
	printf("After Execution of 1st thread value of x becomes:- %d \n",x);

	pthread_t thread2;
	pthread_create(&thread2, NULL, f2,y);
	pthread_join(thread2,NULL);
	printf("After Execution of 2nd thread value of y becomes:- %d \n",y);
	printf("Successful Execution \n");
}


void *f1()
{	int f1;
	f1=x+5;
	x=f1;
	
}

void *f2()
{
	int f2;
	f2=y-5;
	y=f2;
	
}

