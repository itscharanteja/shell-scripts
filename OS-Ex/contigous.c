#include<stdio.h>

int main()
{
    int filesize, n, blocksize, blockno, fileno;
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    printf("Enter the size of each block: ");
    scanf("%d", &blocksize);
    printf("Enter the size of the file: ");
    scanf("%d", &filesize);
    for(blockno=0; blockno<n; blockno++)
    {
        if(filesize<=blocksize)
        {
            fileno=blockno;
            break;
        }
        else
        {
            filesize-=blocksize;
        }
    }
    if(fileno!=-1)
    {
        printf("File is stored in blocks %d to %d\n", fileno, fileno+1);
    }
    else
    {
        printf("File size is greater than the total size of memory\n");
    }
    return 0;
}
