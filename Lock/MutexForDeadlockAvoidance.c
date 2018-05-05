#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *fun1();
void *fun2();
pthread_mutex_t M;
int x;

int main()
{
	printf("\nEnter the value of X : ");
	scanf("%d",&x);
	pthread_mutex_init(&M,NULL);
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, fun1,x);
    pthread_create(&thread2, NULL, fun2,x);
    pthread_join(thread1, NULL);
    printf("after Execution of thread 1 x is %d \n",x);
   	
    pthread_join(thread2, NULL);
    printf("after Execution of thread 2 x is %d \n",x);
    printF("Successful Execution");
}
void *fun1()
{
	pthread_mutex_lock(&M);
    int f1;
    f1=x;
    f1=x*10;   
   sleep(1); 
    x=f1;
    pthread_mutex_unlock(&M);

}

void *fun2()
{
	pthread_mutex_lock(&M);
    int f2;
    f2=x;
    f2=x/10;   
   sleep(1); 
    x=f2;
    pthread_mutex_unlock(&M);
    
}