#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
struct student 
{
	bool all_three;
	bool pen ;
	bool paper;
	bool question_paper;
	
};
void *teacher();
void *student1();
void *student2();
void *student3();
pthread_mutex_t lck;
int ch1,ch2;
int r1,r2;

int main()
{	
	printf("\t\t\t---Welcome---\n");
	pthread_mutex_init(&lck,NULL);
	struct student s[3]={0};
	s[1].pen=1;
	s[2].paper=2;s[3].question_paper=1;
	pthread_t t_thread;
	pthread_t s_thread;
	printf("Resources Menu: \n\t\tPress '1' for pen\n\t\tPress '2' for paper \n\t\tPress '3' for question_paper \n"); 
	
	while(1)
	{
		if(s[1].all_three==1 && s[2].all_three==1 && s[3].all_three==1){break;}
		pthread_create(&t_thread, NULL, teacher, NULL);
	    pthread_join(t_thread,NULL);
	    
		if((ch1==1 && ch2==2 || ch2==1 && ch1==2 ) && s[3].all_three==0)
		{
			printf("\nChoices Made = 'pen', 'paper'\n");
			s[3].all_three=1;
			pthread_create(&s_thread, NULL, student3, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ch1==1 && ch2==3 || ch2==1 && ch1==3 ) && s[2].all_three==0)
		{
			printf("\nChoices Made = 'pen', 'question_paper'\n");
			s[2].all_three=1;
			pthread_create(&s_thread, NULL, student2, NULL);
			pthread_join(s_thread,NULL);
		}
		else if((ch1==2 && ch2==3 || ch2==2 && ch1==3 ) && s[1].all_three==0)
		{
			printf("\nChoices Made = 'paper', 'question_paper'\n");
			s[1].all_three=1;
			pthread_create(&s_thread, NULL, student1, NULL);
			pthread_join(s_thread,NULL);
		}
		else
		{
			printf("\n\tError (007): try again.. with different choices.\n");
		}
	}
	printf("\n\t----Done---\n");
	
	
}

void *teacher()
{
	pthread_mutex_lock(&lck);
	printf("\nFirst Resource on shared tabel:-\t");
	scanf("%d",&ch1);
	printf("Second Resource on shared tabel:-\t");
	scanf("%d",&ch2);
	pthread_mutex_unlock(&lck);
}

void *student2()
{	
	pthread_mutex_lock(&lck);
	printf("\n\tStudent 2 has Completed the assignment. \n");
	pthread_mutex_unlock(&lck);
}
void *student3()
{	
	pthread_mutex_lock(&lck);
	printf("\n\tStudent 3 has Completed the assignment.\n");
	pthread_mutex_unlock(&lck);
}
void *student1()
{	
	pthread_mutex_lock(&lck);
	printf("\n\tStudent 1 has Completed the assignment.\n");	
	pthread_mutex_unlock(&lck);
}



----------------this could solve your problem......
struct arg_struct {
    int arg1;
    int arg2;
};

void *print_the_arguments(void *arguments)
{
    struct arg_struct *args = (struct arg_struct *)args;
    printf("%d\n", args -> arg1);
    printf("%d\n", args -> arg2);
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t some_thread;
    struct arg_struct args;
    args.arg1 = 5;
    args.arg2 = 7;

    if (pthread_create(&some_thread, NULL, &print_the_arguments, (void *)&args) != 0) {
        printf("Uh-oh!\n");
        return -1;
    }

    return pthread_join(some_thread, NULL); /* Wait until thread is finished */
}