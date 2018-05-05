#include<stdio.h>
#include<pthread.h>

int s=1;

void *f1()
{
	int a;
	a=s;
	a++;
	sleep(1);
	s=a;
};
void *f2()
{
	int b;
	b=s;
	b--;
	sleep(1);
	s=b;
};

	
int main()
{
	
	pthread_t mythread1;
	pthread_t mythread2;
	pthread_create(&mythread1, NULL,f1,NULL);
	pthread_create(&mythread2, NULL,f2,NULL);
	pthread_join(mythread1, NULL);
	
	pthread_join(mythread2, NULL);
	printf("%d ",s);
	}
