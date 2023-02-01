#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTORIES 10
#define MAX_FILES 10

struct file {
  char name[20];
  int directory;
};

struct directory {
  char name[20];
  int parent;
};

struct file files[MAX_FILES];
struct directory directories[MAX_DIRECTORIES];
int file_count = 0;
int directory_count = 0;

void add_directory(char name[], int parent) {
  strcpy(directories[directory_count].name, name);
  directories[directory_count].parent = parent;
  directory_count++;
}

void add_file(char name[], int directory) {
  strcpy(files[file_count].name, name);
  files[file_count].directory = directory;
  file_count++;
}

void display_directory(int directory, int level) {
  for (int i = 0; i < directory_count; i++) {
    if (directories[i].parent == directory) {
      for (int j = 0; j < level; j++) {
        printf(" ");
      }
      printf("%s/\n", directories[i].name);
      display_directory(i, level + 2);
    }
  }
  for (int i = 0; i < file_count; i++) {
    if (files[i].directory == directory) {
      for (int j = 0; j < level; j++) {
        printf(" ");
      }
      printf("%s\n", files[i].name);
    }
  }
}

int main() {
  add_directory("Root", -1);
  add_directory("Dir1", 0);
  add_directory("Dir2", 0);
  add_directory("Dir3", 1);
  add_directory("Dir4", 2);
  add_file("File1", 1);
  add_file("File2", 1);
  add_file("File3", 3);
  add_file("File4", 4);

  printf("Directories:\n");
  display_directory(0, 0);

  return 0;
}
