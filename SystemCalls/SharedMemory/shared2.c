#include <unistd.h>
#include<sys/shm.h>
#include<stdio.h>
void *shared_memory;


int main()
{

int sh_id=shmget((key_t)2330,1000,0666);
printf("Key for shared memory %d\n",sh_id);

shared_memory=shmat(sh_id,NULL,0);
printf("Process attached at %x \n",shared_memory);
printf("data is %s\n",shared_memory);
//strcpy(shared_memory,buff);
//printf("You wrote :%s\n",shared_memory);
	
}