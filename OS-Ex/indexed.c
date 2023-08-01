#include <stdio.h>
#define MAX 100
int files[MAX];
void createFile(int fileNumber, int blockNumber)
{
    files[fileNumber] = blockNumber;
}
void deleteFile(int fileNumber)
{
    files[fileNumber] = -1;
}
void displayFiles()
{
    int i;
    printf("File Number\tBlock Number\n");
    for (i = 0; i < MAX; i++)
    {
        if (files[i] != -1)
            printf("%d\t\t%d\n", i, files[i]);
    }
}

int main()
{
    int i;
    for (i = 0; i < MAX; i++)
        files[i] = -1;
    createFile(0, 100);
    createFile(1, 200);
    createFile(2, 300);

    displayFiles();

    deleteFile(1);

    displayFiles();

    return 0;
}
