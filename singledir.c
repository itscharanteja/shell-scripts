#include <stdio.h>
#include <string.h>

#define MAX_FILES 100

struct File {
    char name[50];
    int size;
};

struct Directory {
    struct File files[MAX_FILES];
    int num_files;
};

void initDirectory(struct Directory *dir) {
    dir->num_files = 0;
}

void addFile(struct Directory *dir, char name[], int size) {
    strcpy(dir->files[dir->num_files].name, name);
    dir->files[dir->num_files].size = size;
    dir->num_files++;
}

void listFiles(struct Directory *dir) {
    printf("Listing files in directory:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("- %s (size: %d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    struct Directory dir;
    initDirectory(&dir);

    addFile(&dir, "file1.txt", 1000);
    addFile(&dir, "file2.txt", 2000);
    addFile(&dir, "file3.txt", 3000);

    listFiles(&dir);

    return 0;
}
