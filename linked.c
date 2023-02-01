#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct file {
  char name[20];
  int next;
};

struct file files[MAX_FILES];
int file_count = 0;
int free_list = 0;

void add_file(char name[]) {
  strcpy(files[free_list].name, name);
  int current_free_block = free_list;
  free_list = files[free_list].next;
  files[current_free_block].next = -1;
  file_count++;
}

void display_files() {
  printf("Linked File Allocation:\n");
  printf("Files:\n");
  for (int i = 0; i < file_count; i++) {
    printf("  %s\n", files[i].name);
  }
}

int main() {
  for (int i = 0; i < MAX_FILES - 1; i++) {
    files[i].next = i + 1;
  }
  files[MAX_FILES - 1].next = -1;

  char file_name[20];
  int user_choice;
  while (1) {
    printf("1. Add file\n");
    printf("2. Display files\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &user_choice);
    switch (user_choice) {
      case 1:
        if (free_list == -1) {
          printf("No free blocks available\n");
          break;
        }
        printf("Enter file name: ");
        scanf("%s", file_name);
        add_file(file_name);
        break;
      case 2:
        display_files();
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}
