#include<stdio.h>
int main()
{
	int BT[50],AT[50],Pid[50],totalBurstTime,NoofProcess,i,p[50],time;
	printf("Enter no. of processes: ");
	scanf("%d",&NoofProcess);
	for (i=0;i<NoofProcess;i++)
	{
		printf("\n \tEnter process id: ");
		scanf("%d",&Pid[i]);
		printf("\tEnter Arrival Time: ");
		scanf("%d",&AT[i]);
		printf("\tEnter Burst time: "); 
		scanf("%d",&BT[i]);
		}
	printf(" -: Entered Information :-  "); 
	for(i=0;i<NoofProcess;i++)
	{
		
		printf("\n pid: %d \t Arrival Time: %d \t Burst Time: %d \t \n",Pid[i],AT[i],BT[i]);
		}
	
}
