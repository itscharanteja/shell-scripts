#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4

void allocate_memory(int *memory, int size) {
    int page_count = size / PAGE_SIZE;
    if (size % PAGE_SIZE != 0) {
        page_count++;
    }

    int i;
    for (i = 0; i < page_count; i++) {
        int page_start = i * PAGE_SIZE;
        int page_end = (i + 1) * PAGE_SIZE;
        if (page_end > size) {
            page_end = size;
        }
        printf("Allocating page %d [%d-%d]\n", i, page_start, page_end - 1);
    }
}

int main() {
    int memory_size;
    printf("Enter memory size: ");
    scanf("%d", &memory_size);

    int *memory = (int*) malloc(memory_size * sizeof(int));
    if (memory == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    allocate_memory(memory, memory_size);
    free(memory);
    return 0;
}
