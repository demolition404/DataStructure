#include<stdio.h>
void round_robin(int burst_time[],int arrival_time[],int quanta,int n,int temp[])
{
    int i, NOP=n, sum=0,count=0, y=n, quant=quanta, wt=0, tat=0; 
    float avg_wt,avg_tat;
     printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
        for( i = 0; y!=0; )  
        {  
            if(temp[i] <= quant && temp[i] > 0)  
            {  
                sum = sum + temp[i];  
                temp[i] = 0;  
                count=1;  
            }     
            else if(temp[i] > 0)  
            {  
                temp[i] = temp[i] - quant;  
                sum = sum + quant;    
            }  
            if(temp[i]==0 && count==1)  
            {  
                y--;   
                printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i], sum-arrival_time[i], sum-arrival_time[i]-burst_time[i]);  
                wt = wt+sum-arrival_time[i]-burst_time[i];  
                tat = tat+sum-arrival_time[i];  
                count =0;     
            }  
            if(i==NOP-1)  
            {  
                i=0;  
            }  
            else if(arrival_time[i+1]<=sum)  
            {  
                i++;  
            }  
            else  
            {  
                i=0;  
            }  
        }  
        // represents the average waiting time and Turn Around time  
        avg_wt = wt * 1.0/NOP;  
        avg_tat = tat * 1.0/NOP;  
        printf("\n Average Turn Around Time: \t%f", avg_wt);  
        printf("\n Average Waiting Time: \t%f", avg_tat);  
}
int main()
{
    int n;
    printf("enter the no. of processes:");
    scanf("%d",&n);
    int burst_time[n];
    int arrival_time[n];
    int temp[n];
    printf("enter burst_time and arrival time for each of the processes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("for process[%d]:",i+1);
        scanf("%d%d",&burst_time[i],&arrival_time[i]);
        temp[i]=burst_time[i];
    }
    printf("enter the time quantum of the processes:");
    int quanta;
    scanf("%d",&quanta);
    round_robin(burst_time,arrival_time,quanta,n,temp);


    
}