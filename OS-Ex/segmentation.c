#include<stdio.h>
#include<stdlib.h>
int main()
{
int size, i;
int *segment_start, *segment_end;
printf("Enter the size of the segment: ");
scanf("%d", &size);
segment_start = (int *)malloc(size * sizeof(int));
segment_end = segment_start + size - 1;
printf("Start address of segment: %p\n", segment_start);
printf("End address of segment: %p\n", segment_end);
printf("Enter values for the segment: \n");
for(i = 0; i < size; i++)
{
    scanf("%d", segment_start + i);
}
printf("Values in the segment: \n");
for(i = 0; i < size; i++)
{
    printf("%d ", *(segment_start + i));
}
free(segment_start);
return 0;
}