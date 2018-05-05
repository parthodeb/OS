 #include<stdio.h>
//using namespace std;
                       //ducslectures.blogspot.in
//class sched{
//public:
    int n,bt[10],at[10],tat[10],wt[10],rt[10],finish[10],twt,ttat,total;
    void readData();
    void computeSRT();
    void Init();
    void dispTime();
    int getNextProcess(int);
//};
 
void readData()
{
    printf("Enter no. of processes\n");
    scanf("%d",&n);
    printf("Enter the burst times in order :\n");
    for(int i=0;i<n;i++)
    scanf("%d",&bt[i]);
    printf("Enter the arrival times in order:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&at[i]);
}
 
void Init(){
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<n; i++)
     {
        rt[i]=bt[i];
        finish[i]=0;
        wt[i]=0;
        tat[i]=0;
        total+=bt[i];
        }
}
 
void computeSRT()
{
    readData();
    Init();
    int time,next=0,old,i;
    printf("Gantt Chart\n ");
    for(time=0;time<total;time++)
    {
        old=next;
        next=getNextProcess(time);
        if(old!=next || time==0) 
  {
        printf("(t%d)|==p%d==|",time,next+1);
        //cout<<"("<<time<<")|==P"<<next+1<<"==|";
        }
        rt[next]=rt[next]-1;
        if(rt[next]==0) 
  {
  finish[next]=1;
     }
        for(i=0;i<n;i++)
            if(i!=next && finish[i]==0 && at[i]<=time)
                wt[i]++;
    }
    printf("( %d ) \n",total);
    //cout<<"("<<total<<")"<<endl;
    for(i=0;i<n;i++)
      if(!finish[i]) {printf("Scheduling failed, cannot continue \n "); return;}
      //  if(!finish[i]) {cout<<"Scheduling failed, cannot continue\n"; return;}
    dispTime();
}
int getNextProcess(int time)
{ 
        int i,low;
        for(i=0;i<n;i++)
            if(finish[i]==0){low=i; break; }
        for(i=0;i<n;i++)
            if(finish[i]!=1)
                if(rt[i]<rt[low] && at[i]<=time)
                        low=i;
        return low;
 
}

void dispTime()
{
    for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        tat[i]=wt[i]+bt[i];
        ttat+=tat[i];
        printf("waiting time for P%d == %d, Turnaround time= %d \n",i+1,wt[i],tat[i]);
        //cout<<"Waiting time for P"<<(i+1)<<" = "<<wt[i]<<", Turnaround time = "<<tat[i]<<endl;
    }
    printf("Avg Waiting time = %f and Avg Turnaround time = %f\n",(double)twt/n,(double)ttat/n);
    //cout<<"Avg Waiting time = "<<(double)twt/n<<" and Avg Turnaround time = "<<(double)ttat/n<<endl;
    printf("\n\t\t\t--Scheduling complete--\n");
    //cout<<"Scheduling complete\n";
}
 int main()
{
    void readData();
    void computeSRT();
    void Init();
    void dispTime();
    int getNextProcess(int);
    computeSRT(); 
                        //ducslectures.blogspot.in
}