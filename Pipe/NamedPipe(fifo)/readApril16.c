#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int r;char buff[50] ;
	r=open("myfifo1",O_RDONLY);
	read(r,buff,7);
	printf("%s",buff);
	
}