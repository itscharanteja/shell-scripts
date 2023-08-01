#include <stdio.h>
#include <string.h>
#define MAX_FILES 100
#define MAX_NAME_LEN 50

void initDirectory(int *num_files) {
*num_files = 0;
}
void addFile(char files[][MAX_NAME_LEN], int *sizes, int *num_files, char name[], int size) {
strcpy(files[*num_files], name);
sizes[*num_files] = size;
(*num_files)++;
}
void listFiles(char files[][MAX_NAME_LEN], int *sizes, int num_files) {
printf("Listing files in directory:\n");
for (int i = 0; i < num_files; i++) {
printf("- %s (size: %d bytes)\n", files[i], sizes[i]);
}
}
int main() {
char files[MAX_FILES][MAX_NAME_LEN];
int sizes[MAX_FILES];
int num_files;
initDirectory(&num_files);
addFile(files, sizes, &num_files, "file1.txt", 1000);
addFile(files, sizes, &num_files, "file2.txt", 2000);
addFile(files, sizes, &num_files, "file3.txt", 3000);
listFiles(files, sizes, num_files);
return 0;
}