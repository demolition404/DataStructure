#include<stdio.h>
/*
    ALFO by ayan->
        -->srtf means shortest remaining time first
        -->which means stf with preemtive approach 
        -->so basically at a certain moment we have to check which is the smallest burst
            time of any particular program and then implement it 
        -->if the shortest burst time is not the burst time of the given process running
            -->then compare the shortest with the present burst 
                -->if present burst smaller then continue;
                -->else stop the present and start the new process whose burst time is lower
        -->considering arrival time we need to be a bit more carefull

*/
/*
    basically we need to calculate the average turn around time and average waiting time
*/
/*
    Process by ayan->
        -->firstly in any iteration we have to check which process has the least time
        -->then do that process till any other process has not arrived then 
        -->compare the reduced burst time with the burst times of arrived process
        -->if less then continue the process till any other process arrives
        -->and complete likewise
        -->if more then select the process with least burst time and then continue that process 
        -->till you encounter any process which has less number of  
*/
void solve(int burst_time[],int arrival_time[],int n)
{
    int time,count=0,smallest=9,i,limit=n;
    int temp[10]={0,0,0,0,0,0,0,0,0,0};
    double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
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
      printf("nnAverage Waiting Time:t%lfn", average_waiting_time);
      printf("Average Turnaround Time:t%lfn", average_turnaround_time);
}
int main()
{
    /*
        Q2. WAP in C to implement the SRTF scheduling algorithm with considering the arrival time.

    */
   int n;
   printf("enter the no. of processes:");
   scanf("%d",&n);
   int burst_time[n];
   int arrival_time[n];
   printf("enter arrival time and burst time of each process simultaniosly:\n");
   for (int i = 0; i < n; i++)
   {
       scanf("%d%d",&burst_time[i],&arrival_time[i]);

   }
   solve(burst_time,arrival_time,n);

   

}