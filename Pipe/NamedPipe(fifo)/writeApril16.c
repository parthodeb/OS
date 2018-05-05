#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int r;
	r=open("myfifo1",O_WRONLY);
	write(r,"HelloWorld",7);
	
}