#include <stdio.h>

int main()
{
     int n;
     int bt[100], pid[100],at[100],wt[100];
     wt[0]=0;
     int temp,ptemp,btemp;
     int i, j;
     float twt=0.0;
     float tat= 0.0;
     float att,awt;

     printf("Enter the number of processes : ");
    scanf("%d",&n);

    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
        
    }
    
    printf("Enter process arrival time ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
 
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

   
    for (i=0;i<(n-1);i++)
    {
         for (j=0;j<(n-i-1);j++)
        {
            if (at[j]>at[j + 1])
                {
                 temp = at[j];
                 at[j] = at[j+1];
                 at[j+1]=temp;

                 ptemp=pid[j];
                 pid[j]=pid[j+1];
                 pid[j+1]=ptemp;

                 btemp=bt[j];
                 bt[j]=bt[j+1];
                 bt[j+1]=btemp;

                 }
        }
    }
 
  
 
    
    for(i=1;i<n;i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
 
    printf("Process ID      Arrival Time     Burst Time      Waiting Time      TurnAround Time\n");
    
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t \t",at[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
 
       
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
 
        
        twt += wt[i];
 
       
        tat += (wt[i]+bt[i]);
    }
    
 
    
    awt = twt/n;
 
    
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}