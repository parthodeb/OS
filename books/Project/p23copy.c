
#include <stdio.h>
 
int main() 
{
      int arrival_time[10], burst_time[10], temp[10], pid[10],gantChart[10];
      int i, smallest, count = 0, time, limit,sm=0,total=0;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
	  printf("\nEnter Details of %d Processes\n", limit);
      limit=limit+3;
	  for(i = 3; i < limit; i++)
      {
		    printf("\nEnter PID: \t");
		    scanf("%d",&pid[i]);
            printf("Enter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
	for(i=3;i<limit;i++)
	{
		total=burst_time[i]+total;
	}
      burst_time[9] = 9999;  
	gantChart[sm]=0;
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 3; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
					  gantChart[time]=pid[smallest];
					  
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
	  for (i=0;i<total;i++)
	  {
		  printf(" %d ",gantChart[i]);
	  }
      return 0;
}