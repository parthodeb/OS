
#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
void *shared_memory;

char buff[50];
int main()
{

int sh_id=shmget((key_t)2330,1000,0666| IPC_CREAT);
printf("Key for shared memory %d\n",sh_id);

shared_memory=shmat(sh_id,NULL,0);
printf("Process attached at %x \n",shared_memory);
printf("data:-\n");
scanf("%s",buff);
strcpy(shared_memory,buff);
printf("You wrote :%s\n",shared_memory);

}