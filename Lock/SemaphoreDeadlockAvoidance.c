#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
void *fun1();
sem_t mysem;
//pthread_mutex_t l;
void *fun2();
int shared=1; 
int main()
{
    sem_init(&mysem,0,1);   		
                            /*  1)reference of sem variable
   								2)no. of processes using this sem variable
								if 0 then it represents all threads of process are going to use this sem varible
								3) default value of sem i.e. 1*/
	//pthread_mutex_init(&l,NULL);
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);
printf("Final value of shared is %d\n",shared);
}

void *fun1()
{
	sem_wait(&mysem);//willingness to acquire the lock
    //pthread_mutex_lock(&l);
    int x;
    x=shared;
    x++;
sleep(1);
	printf("thread 1 \n");
    shared=x;
    printf("After incrementing shared = %d \n",shared);
    //pthread_mutex_unlock(&l);
	sem_post(&mysem);//want to unlock 
}

void *fun2()
{
    sem_wait(&mysem);
    //pthread_mutex_lock(&l);
    int y;
    y=shared;
    y--;    
  sleep(1);
	printf("thread 2 \n");
    shared=y;
    printf("After decrementing shared = %d \n",shared);
    //pthread_mutex_unlock(&l);
	sem_post(&mysem);//want to unlock 


}