#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DIRECTORIES 10

struct file {
  char name[20];
  int directory;
};

struct directory {
  char name[20];
  int index;
};

struct file files[MAX_FILES];
struct directory directories[MAX_DIRECTORIES];
int file_count = 0;
int directory_count = 0;

void add_directory(char name[]) {
  strcpy(directories[directory_count].name, name);
  directories[directory_count].index = directory_count;
  directory_count++;
}

void add_file(char name[], int directory) {
  strcpy(files[file_count].name, name);
  files[file_count].directory = directory;
  file_count++;
}

void display_directory(int directory) {
  printf("Directory: %s\n", directories[directory].name);
  printf("Files:\n");
  for (int i = 0; i < file_count; i++) {
    if (files[i].directory == directory) {
      printf("  %s\n", files[i].name);
    }
  }
}

int main() {
  add_directory("Root");
  add_directory("Sub1");
  add_directory("Sub2");
  add_file("File1", 0);
  add_file("File2", 0);
  add_file("File3", 1);
  add_file("File4", 2);

  printf("Two-Level File System:\n");
  for (int i = 0; i < directory_count; i++) {
    display_directory(i);
  }

  return 0;
}
