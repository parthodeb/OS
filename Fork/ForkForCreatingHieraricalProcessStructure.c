#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main()

{	
	printf("Main Parent having pid %d \n",getpid());
	pid_t p1;
	pid_t c1,c2,Cc;
	int i;
	c1=fork();
	
	
	if (c1<0 )
	{
		printf("Error");
	}
	else if(c1==0 )
	{
		
		printf("\nchild C1 having pid %d \n",getpid());
		//printf("child C2 having pid %d \n",getpid());
		//printf("My parent's P1's pid %d \n",getppid());
	
		Cc=fork();
		if (Cc<0)
		{
			printf("Error");
		}
		else if(Cc==0)
		{
			printf("\nGrand child Cc having pid %d \n",getpid());
			//printf("My parent's C1's pid %d \n",getppid());
		
		}
		wait(0);

	}	
	else
	{	wait(0);
		c2=fork();
		if ( c2<0)
		{
			printf("Error");
		}
		else if(c2==0)
		{
		
			printf("\nchild C2 having pid %d \n",getpid());
			//printf("My parent's P1's pid %d \n",getppid());
		}
		else{
		wait(0);
		//printf("\n\nParent having pid %d \n",getpid());
		//printf("My child's C1's pid is %d \n",c1);
		//printf("My child's C2's pid is %d \n",c2);
		//printf("My Gradchild's Cc's pid is %d \n",Cc);
		printf("\n\n!**Executed Successfully**!\n");
		}
	}
	//printf("\nCommon\n");
}
		