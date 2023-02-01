#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 100
#define MAX_SEGMENT_SIZE 100

struct Segment {
  int base;
  int limit;
  int size;
};

struct Segment memory[MAX_SEGMENTS];
int segment_count = 0;

void allocate_segment(int size) {
  if (segment_count == MAX_SEGMENTS) {
    printf("Error: Memory full\n");
    return;
  }

  int base = 0;
  for (int i = 0; i < segment_count; i++) {
    if (memory[i].base + memory[i].size == base) {
      base = memory[i].base + memory[i].size;
    }
  }

  memory[segment_count].base = base;
  memory[segment_count].size = size;
  memory[segment_count].limit = base + size - 1;
  segment_count++;

  printf("Segment allocated successfully with base address: %d and limit: %d\n",
         memory[segment_count - 1].base, memory[segment_count - 1].limit);
}

void free_segment(int segment_index) {
  if (segment_index >= segment_count) {
    printf("Error: Invalid segment index\n");
    return;
  }

  for (int i = segment_index; i < segment_count - 1; i++) {
    memory[i] = memory[i + 1];
  }

  segment_count--;

  printf("Segment freed successfully\n");
}

int main() {
  allocate_segment(50);
  //allocate_segment(60);
  allocate_segment(70);

  free_segment(1);

  //allocate_segment(80);

  return 0;
}
