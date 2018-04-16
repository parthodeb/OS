

 #include<stdio.h>
int No,bt[10],at[10],tat[10],wt[10],rt[10],finish[10],twt,ttat,total,tq=0; 

void readData()
{
    printf("Enter no. of processes\n");
    scanf("%d",&No);
    printf("Enter the arrival times in order:\n");at[0]=0;
    printf("\n%d ----(Note:-for 1st process AT is by default '0' so start from of 2nd process)\n",at[0]);
    for(int i=1;i<No;i++)
    scanf("%d",&at[i]);
    printf("Enter the burst times in order :\n");
    for(int i=0;i<No;i++)
    scanf("%d",&bt[i]);
}
 
void Init(){
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<No; i++)
     {
        rt[i]=bt[i];
        finish[i]=0;
        wt[i]=0;
        tat[i]=0;
        total+=bt[i];
        }
}
 int getNextProcess(int time)
{ 
        int i,low;
        for(i=0;i<No;i++)
        {
            if(finish[i]==0)
            {
                low=i; break; 
            }}
        for(i=0;i<No;i++)
        {
            if(finish[i]!=1)
            {
                if(rt[i]<rt[low] && at[i]<=time)
                {    
                    low=i;
                }}}
        return low;
 
}
void dispTime()
{
    for(int i=0;i<No;i++)
    {
        twt+=wt[i];
        tat[i]=wt[i]+bt[i];
        ttat+=tat[i];
        printf("waiting time for P%d == %d, Turnaround time= %d \n",i+1,wt[i],tat[i]);
    }
    printf("Avg Waiting time = %f and Avg Turnaround time = %f\n",(double)twt/No,(double)ttat/No);
    printf("\n\t\t\t--Scheduling complete--\n");
    
}
void computeSRT()
{
    readData();
    Init();
    int time,next=0,old,i,new_time;
    printf("Gantt Chart\n ");
    for(time=0;time<total;time++)
    { 
          
        old=next;
        next=getNextProcess(time);
        if((old!=next &&tq==0 ) ||time==0)
        {
            
            printf("(t=%d)|----p%d----|",time,next+1);
        }
        rt[next]=rt[next]-1;
        
        if(rt[next]==0) 
        {   
            finish[next]=1;
        }
        for(i=0;i<No;i++)
        {
            if(i!=next && finish[i]==0 && at[i]<=time)
            {
                wt[i]++;
            }
        }
        if(time!=0&&old==next&&time%10==0){next=getNextProcess(time);printf("(t=%d)|----p%d----|",time,next+1);}
           
    }
    printf("( %d ) \n",total);
    for(i=0;i<No;i++)
        if(!finish[i]) 
        {
            printf("Scheduling failed, cannot continue \n "); 
            return;
        }
    dispTime();
}

int main()
{

    printf("\t<-------------------------Welcome------------------------->\t\n");
    printf("....(--please Extend your command prompt to appropriate size--).....\n");
    printf("\t<-------------------------------Rights reserved to Shubham>\t\n");
    void readData();
    void computeSRT();
    void Init();
    void dispTime();
    int getNextProcess(int);
    computeSRT(); 
    printf("\n\t\t--------Sorry but here concept of time quantum is not applied\n");
                      
}