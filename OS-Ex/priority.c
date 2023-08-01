#include<stdio.h>
#include<string.h>
int main()
{
    int et[100],at[100],n,i,j,temp,p[100],st[100],ft[100],wt[100],ta[100];
    int totwt=0,totta=0;
    float awt,ata;
    int pn[100],t;
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process details for %d \n",(i+1));
        pn[i]=i+1;
        printf("enter arrivaltime for process\t");
        scanf("%d",&at[i]);
        printf("execution time  for process \t");
        scanf("%d",&et[i]);
        printf("enter the priority of process \t");
        scanf("%d",&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
               t=p[i];
               p[i]=p[j];
               p[j]=t;

            }
        }
    for(i=0; i<n; i++)

    {
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%d\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    return 0;
}
