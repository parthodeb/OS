#include<stdio.h>
int main()
{
	char buffer[1200];
	FILE *r;
	r=popen("ls","r");
	fread(buffer,1,1200,r);
	printf("%s",buffer);
	pclose(r);
}