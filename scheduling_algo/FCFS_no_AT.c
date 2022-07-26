#include<stdio.h>
    /*
    Q1. WAP in C to implement the FCFS scheduling algorithm without considering the arrival time.
    */
    /*
    ALGO by Ayan Dutta :
        --> firstly if I don't consider arrival time its similar to saying that all
            processes are available at time 0.
        --> there are two things that I can do
            --> just finish one process after the another not caring about the burst time as well
            --> finish short processes first to reduce waiting time of process which are
                short i.e., reducing the average waiting time and average turn around time
        
        --> we are first going to solve via method one that is not caring about BT as well 
            just running the process in the cpu in the order the user inputs the BT of the 
            processes

                

    */
    /*
    Process by Ayan Dutta :
        -->ask the user for number of processes i.e., n;
        -->ask the user burst time of each process and store in burst_time[n];
        -->create array waiting_time[n];
        -->waiting_time[i] for some process i is the amount of time it waited 
        before execution.
        -->waiting_time[i] = burst_time[i-1]+burst_time[i-2]..+burst_time[0];
        -->after cal. of waiting times of all n process
        -->create array turn_around_time[n];
        -->turn_around_time[i] for any process i is waiting_time[i]+burst_time[i];
        -->average waiting time = sum of waiting time for all individual process/n;
        -->average turn around time = sum of turn around time for all individual process/n;

    */
float wait_time(int Burst_time[],int n)
{
    int waiting_time[n];
    int burst_sum=0;
    for (int i = 0; i < n; i++)
    {
        waiting_time[i]=burst_sum;
        burst_sum+=Burst_time[i];
    }
    printf("Process_id\tBurst_time\twait_time\n");
    float avg_waiting_time=0;
    for (int i = 0; i < n; i++)
    {
        
        printf("%d\t\t%d\t\t%d\n",i+1,Burst_time[i],waiting_time[i]);
        avg_waiting_time+=waiting_time[i];
    }
    avg_waiting_time=(float)avg_waiting_time/n;
    return avg_waiting_time;
    
}
float turn_around(int Burst_time[],int n)
{
    int waiting_time[n];
    int turn_around_time[n];

    int burst_sum=0;
    for (int i = 0; i < n; i++)
    {
        waiting_time[i]=burst_sum;
        burst_sum+=Burst_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        turn_around_time[i]=waiting_time[i] + Burst_time[i];   
    }
    printf("Process_id\tBurst_time\twait_time\tturn_around_time\n");
    float avg_turn_around_time=0;
    for (int i = 0; i < n; i++)
    {
        
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,Burst_time[i],waiting_time[i],turn_around_time[i]);
        avg_turn_around_time+=turn_around_time[i];
    }
    avg_turn_around_time = (float)avg_turn_around_time/n;
    return avg_turn_around_time;
}
int main()
{
    printf("Enter the number of processes : ");
    int n;
    scanf("%d",&n);
    int Burst_time[n];
    printf("Enter the burst time for each individual processes : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&Burst_time[i]);    
    }
    float avg_waiting_time = wait_time(Burst_time,n);
    printf("average waiting time = %f\n",avg_waiting_time);
    float avg_turn_around_time = turn_around(Burst_time,n);
    printf("average turn around time = %f",avg_turn_around_time);


}