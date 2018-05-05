#include<stdio.h>
#include<pthread.h>

struct mystruct
{
	int a;
	int b;
};
int *c;
void *sum(void *ptr)
{
	struct mystruct *struct_ptr=ptr;
	printf("Value Of first number is %d \n",struct_ptr->a);
	printf("Value of second number is %d \n",struct_ptr->b);
	
	int s=struct_ptr->a+struct_ptr->b;
	pthread_exit(s);
	}
	
int main()
{
	struct mystruct obj;
	obj.a=2;
	obj.b=3;
	pthread_t mythread;
	pthread_create(&mythread, NULL, sum, &obj);
	pthread_join(mythread, &c);
	printf("Sum of 2 numbers is %d \n",c);
	}