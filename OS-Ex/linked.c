#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,i,j,k,c[100];
    printf("Enter the number of blocks:");
    scanf("%d",&n);
    printf("Enter the number of files:");
    scanf("%d",&m);
    int a[m],b[m];
    for(i=0;i<m;i++)
    {
        printf("Enter the size of file %d:",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[j]=1;
            for(k=0;k<m;k++)
            {
                if(b[k]==j)
                    c[j]=0;
            }
            if(c[j]==1)
                break;
        }
        if(j==n)
        {
            printf("File cannot be allocated\n");
            return 0;
        }
        b[i]=j;
        for(k=j+1;k<j+a[i];k++)
            b[i]=k%n;
    }
    printf("File Allocation is as follows:\n");
    for(i=0;i<m;i++)
        printf("File %d-->Block %d\n",i+1,b[i]+1);

    return 0;
}
