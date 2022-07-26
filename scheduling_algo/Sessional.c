#include <stdio.h>
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
int main()
{
    int n;
    printf("Enter number of the process: ");
    scanf("%d", &n);
    
    int burst = 0, cmpl_T;
    int AT[n], BT[n], WT[n], TT[n];
    float Avg_WT, Avg_TT, Total = 0;
    
    printf("Enter Arrival time and Burst time of the process\n");
    printf("Arrival_Time\tBurst_Time\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &AT[i], &BT[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            WT[i] = AT[i];
        else
            WT[i] = burst - AT[i];
        burst += BT[i];
        Total += WT[i];
    }
    Avg_WT = Total / n;
    cmpl_T = 0;
    Total = 0;
    for (int i = 0; i < n; i++)
    {
        cmpl_T += BT[i];
        TT[i] = cmpl_T - AT[i];
        Total += TT[i];
    }
    Avg_TT = Total / n;
    printf("Process Waiting_time TurnAround_time\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d\t\t%d\t\t%d\n", i + 1, WT[i], TT[i]);
    }
    printf("Average waiting time is : %f\n", Avg_WT);
    printf("Average turn around time is : %f\n", Avg_TT);
    return 0;
}