#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=0,FileSystem[10]={[0 ... 9]=1},start,len,j,ch=1;
	/*(for (i=0;i<10;i++)
	{
		FileSystem[i]=1;
	}*/
	while(1)
	{
		printf("Enter the starting Block : " );
		scanf("%d",&start);
		printf("Enter the Length of your file: ");
		scanf("%d",&len);
		i=start;
		for(j=0;j<10;j++)
		{		
			if(FileSystem[i]==1&&len!=0)
			{
				FileSystem[i]=0;
				i=i+1;
				len--;
			}
			else if(FileSystem[i]==0&&len!=0)
			{
				i=i+1;
			}
			else if(FileSystem[i]==0&&len==0)
			{
				break;
			}
		}
		for (i=0;i<10;i++)
		{
			printf("\nFileSystem[%d] = %d",i,FileSystem[i]);	
		}
		printf("\nDo you want to repeat: " );
		scanf("%d",&ch);
		if(ch!=1)
		{
			printf("Thank You \n");
			break;
		}
	}
}