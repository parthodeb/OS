
#include<pthread.h>
#include<stdio.h>
void *fun1();
pthread_mutex_t l;
void *fun2();
int shared=1; 
int main()
{
    pthread_mutex_init(&l,NULL);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2,NULL);
    printf("\nFinal value of shared is %d\n",shared);
}

void *fun1()
{
    pthread_mutex_lock(&l);
    int x;
    x=shared;
    x++;   
   sleep(1); 
    shared=x;
    printf("\nThread 1 'Shared= %d'",shared);
    pthread_mutex_unlock(&l);
}

void *fun2()
{
    pthread_mutex_lock(&l);
    int y;
    y=shared;
    y--;    
  sleep(1);
    shared=y;
  pthread_mutex_unlock(&l);
}