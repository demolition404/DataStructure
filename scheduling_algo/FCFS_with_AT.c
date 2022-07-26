#include<stdio.h>
/*
    Q2. WAP in C to implement the FCFS scheduling algorithm with considering the arrival time.
*/
/*
    Algorithm by Ayan Dutta : 
        -->the one which arrives first executes first.
        -->basically we can sort the array of arrival times 
            and simultainiously changing the burst times order 
            according to the arrival time
        -->once done that find waiting time[i] = burst_time[i-1]+..burst_time[0]-Arrivaltime[i];
*/
/*
    Process by Ayan Dutta :
        -->ask user number of process that is n;
        -->ask user to input individual burst times;
        -->ask user to input individual arrival times;
        -->solve the problem
            -->Bubble sort arrival time array and accordingly swap the burst times;
            -->solve :
                -->find waiting time:before burst times - arrival time of the process;
                -->turn around time:time when process completed - arrival time;

*/
void arrange(int Burst_time[],int Arrival_time[],int n)
{
    // in this function we will be arranging our process according to the arrival times;
    // for sorting we use bubble sort algorithm which takes O(N^2) time but easy to implement 
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(Arrival_time[j]<Arrival_time[i])
            {
                int temp1 = Arrival_time[j];
                Arrival_time[j] = Arrival_time[i];
                Arrival_time[i] = temp1;
                //simultaniously we need to arrange our Burst_times;
                int temp2 = Burst_time[j];
                Burst_time[j] = Burst_time[i];
                Burst_time[i] = temp2;

            }
        }
        
    }
    
}
float wait_time(int Burst_time[],int Arrival_time[],int n)
{
    int waiting_time[n];
    int burst_times = 0;
    for (int i = 0; i < n; i++)
    {
        if(Arrival_time[i]<=burst_times)
        waiting_time[i] = burst_times - Arrival_time[i];
        else waiting_time[i] = 0;
        burst_times+=Burst_time[i];
    }
    printf("Process_id\tBurst_time\tArrival_time\twait_time\n");
    float avg_waiting_time=0;
    for (int i = 0; i < n; i++)
    {
        
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,Burst_time[i],Arrival_time[i],waiting_time[i]);
        avg_waiting_time+=waiting_time[i];
    }
    avg_waiting_time=(float)avg_waiting_time/n;
    return avg_waiting_time;
}
float turn_around(int Burst_time[],int Arrival_time[],int n)
{
    int waiting_time[n];
    int turn_around_time[n];
    int burst_times = 0;
    for (int i = 0; i < n; i++)
    {
        if(Arrival_time[i]<=burst_times)
        {
            waiting_time[i] = burst_times - Arrival_time[i];
            burst_times+=Burst_time[i];
        }

        else {
            waiting_time[i] = 0;
            burst_times=Arrival_time[i]+Burst_time[i];
        }
    }
    printf("Process_id\tBurst_time\tArrival_time\twait_time\tturn_around_time\n");
    float avg_turn_around_time=0;
    for (int i = 0; i < n; i++)
    {
        
       
        if(Arrival_time[i]>waiting_time[i]+Burst_time[i])
        {
            avg_turn_around_time+=Burst_time[i]+waiting_time[i];
             printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,Burst_time[i],Arrival_time[i],waiting_time[i],waiting_time[i]+Burst_time[i]);
        }

        else
        {

        
            avg_turn_around_time+=waiting_time[i]+Burst_time[i];
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,Burst_time[i],Arrival_time[i],waiting_time[i],waiting_time[i]+Burst_time[i]);
        }
        
    }
    avg_turn_around_time=(float)avg_turn_around_time/n;
    return avg_turn_around_time;

}
int main()
{
    printf("Enter the number of processes : \n");
    int n;
    scanf("%d",&n);
    int Burst_time[n];
    int Arrival_time[n];
    printf("Enter the burst time of the processes and arrival time consecutively : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&Burst_time[i],&Arrival_time[i]);

    }
    arrange(Burst_time,Arrival_time,n);
    float avg_waiting_time = wait_time(Burst_time,Arrival_time,n);
    printf("average waiting time = %f\n",avg_waiting_time);
    float avg_turn_around_time = turn_around(Burst_time,Arrival_time,n);
    printf("average turn around time = %f\n",avg_turn_around_time);


}