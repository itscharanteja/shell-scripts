#include <stdio.h>

#define MAX_PROCESSES 50

int n; 
int quantum; 
int burst_time[MAX_PROCESSES]; 
int arrival_time[MAX_PROCESSES]; 
int waiting_time[MAX_PROCESSES]; 
int turn_around_time[MAX_PROCESSES]; 

void roundRobin()
{
int remaining_time[MAX_PROCESSES];
for (int i = 0; i < n; i++)
remaining_time[i] = burst_time[i];
int t = 0;
while (1)
{
    int done = 1;
    for (int i = 0; i < n; i++)
    {
        if (remaining_time[i] > 0)
        {
            done = 0;
            if (remaining_time[i] > quantum)
            {
                t += quantum;
                remaining_time[i] -= quantum;
            }
            else
            {
                t = t + remaining_time[i];
                waiting_time[i] = t - burst_time[i] - arrival_time[i];
                remaining_time[i] = 0;
            }
        }
    }
    if (done == 1)
        break;
}
}

int main()
{
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the time quantum: ");
scanf("%d", &quantum);
printf("Enter the arrival time and burst time for each process:\n");
for (int i = 0; i < n; i++)
{
printf("Process %d: ", i + 1);
scanf("%d%d", &arrival_time[i], &burst_time[i]);
}
roundRobin();

int total_waiting_time = 0, total_turn_around_time = 0;
printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
for (int i = 0; i < n; i++)
{
    turn_around_time[i] = burst_time[i] + waiting_time[i];
    total_waiting_time += waiting_time[i];
    total_turn_around_time += turn_around_time[i];
    printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turn_around_time[i]);
}
printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
printf("Average Turnaround Time: %.2f\n", (float)total_turn_around_time / n);

return 0;
}