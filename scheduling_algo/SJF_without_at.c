#include<stdio.h>
/*
    ALGO by ayan ->
    -->without considering arrival time 
    -->assuming all process arrived at the same time that is 0 seconds
    -->we have to see which process is the smallest and execute it 
    -->it will be non-premtive since once processes start since it is the smallest then no other process can replace it
    -->if 2 processes have the same burst times
        we will consider the process whose id is smaller

*/
/*
    we have to find average turn around time and 
    average waiting time

*/
void sort(int burst_time[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(burst_time[j]<burst_time[i])
            {
                int t = burst_time[j];
                burst_time[j]=burst_time[i];
                burst_time[i]=t;
            }
        }
        
    }
    
}
void solve(int burst_time[],int n)
{
    int waiting_time[n];
    int turn_around_time[n];
    sort(burst_time,n);
    int wt=0;
    double avg_tat=0;
    double avg_wt=0;
    for (int i = 0; i < n; i++)
    {
        waiting_time[i]=wt;
        wt+=burst_time[i];
        turn_around_time[i]=wt;
    }
    for (int i = 0; i < n; i++)
    {
        avg_wt+=waiting_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        avg_tat+=turn_around_time[i];
    }
    printf("Process_id\t\tBurst_time\t\tWaiting_time\t\tTurn_around_time:\n");
    for (int i = 0; i < n; i++)
    {
       printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_time[i],waiting_time[i],turn_around_time[i]);
    }
    
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("average turn around time: %f\n",avg_tat);
    printf("average waiting time: %f\n",avg_wt);




    
}
int main()
{
    /*Q1. WAP in C to implement the SJF scheduling algorithm without considering the arrival time.*/
    int n;
    printf("enter the no. of processes:");
    scanf("%d",&n);
    int burst_time[n];
    printf("enter individual burst_times:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&burst_time[i]);

    }
    solve(burst_time,n);
    
}