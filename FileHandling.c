#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int buff[500],n=10;
	char f;
	f=open("new1.txt",O_RDWR);
	read(0,buff,n);
	
	//ite(1,buff,n);
write(f,buff,n);
	close(f);
	f=open("new1.txt",O_RDWR);
	//intf("\n");
	read(f,buff,n);
	write(1,buff,n);
		
	close(f);
}
	
