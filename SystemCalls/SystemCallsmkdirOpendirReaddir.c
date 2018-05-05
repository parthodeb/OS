#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
int main()
{
	DIR *dp; //DIR=data type Directory
	struct dirent *dptr; //inbuilt structure
	mkdir("Programs",0777); //permission for read, write and execute
	dp=opendir("Programs");
	while((dptr=readdir(dp))!=NULL)
	{
		printf("%s\n",dptr->d_name); //%s=string
		printf("%d\n",dptr->d_type);
		printf("%ld\n",dptr->d_ino); //%ld=long double
	}
	closedir(dp);
	system("rmdir Programs");
}



/* 

	Struct dirent
	{
	ino_t d_ino;
	off_t d_off;
	unsigned char reclen;
	int d_type;
	char d_name;
	};
*/

