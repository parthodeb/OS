#include<stdio.h>
int main()
{
	int tquantum=10,i,j,MaxPro,t,totalBurst=0,tq,N=0,m;
	printf("Enter the number of processes: ");
	scanf("%d",&MaxPro);
	int Pid[MaxPro],AT[MaxPro],BT[MaxPro],queue[MaxPro],ReadyQueue[MaxPro],BTRQ[MaxPro];
	for(i=0;i<MaxPro;i++)
	{
		printf("\n Pid of process %d= ",i);
		scanf("%d",&Pid[i]);
		printf(" Arrival time of process %d= ",i);
		scanf("%d",&AT[i]);
		printf(" Burst time of process %d =",i);
		scanf("%d",&BT[i]);
	}
	
	for(i=0;i<MaxPro;i++)
	{
		totalBurst=totalBurst+BT[i];
	}
	printf("\nTotal CPU time will be %d.",totalBurst);
	for(tq=0;tq<10;tq++)  //to measure time quantum
	{
		for(i=0;i<MaxPro;i++)//to run at every second 
		{	for(j=0;j<MaxPro;j++) /*this is most important line it will check the BT time of the Processes
									 to decide wheather to assign cpu with new process or process from readyqueue*/
			
			{
			if (AT[i]==tq && BT[i]<BTRQ[j])//to check weather new process is entered or not
			{
				ReadyQueue[N]=Pid[i];//adding new process in ready queue
				N++;
			}
			for(j=0;j<N;j++)//to add burst time of ready queue elements in BT of Ready Queue Elements
			{					
				if(Pid[m]==ReadyQueue[j])
				{
					BTRQ[j]=BT[m];
				}
					
			}
				/*for(j=0;j<i;j++)
				{
					if(BTRQ[N]>BT[j])
					{
						ReadyQueue[N]=ReadyQueue[N-1];
						ReadyQueue[N-1]=Pid[j];
					}
				}*/
		}
			t++;
			if(t==totalBurst)
			{
				break;
			}
	}
					// Now it is sorting them by there Arrival time at 04-04-18 9:00 pm
	
	
	
	
	
	printf("\nReady Queue: ");
	for (i=0;i<MaxPro;i++)
	{
		printf("%d  ",ReadyQueue[i]);
		
	}
}