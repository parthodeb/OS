#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("Before Execution: \n" );
	execl("/bin/ls","ls",NULL);
	printf("\n After Execution" );
	}