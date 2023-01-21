#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

// Structure to represent a process
struct Process {
  int pid; // Process ID
  int arrival_time; // Arrival time
  int execution_time; // Execution time
};

int main() {
  // Create an array of processes
  struct Process processes[MAX_PROCESSES];
  int num_processes;

  // Read in the processes from the input
  scanf("%d", &num_processes);
  for (int i = 0; i < num_processes; i++) {
    scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].execution_time);
  }

  // Scheduling loop
  int current_time = 0;
  for (int i = 0; i < num_processes; i++) {
    // Wait for the next process to arrive
    while (current_time < processes[i].arrival_time) {
      current_time++;
    }

    // Execute the process
    printf("Executing process %d at time %d\n", processes[i].pid, current_time);
    current_time += processes[i].execution_time;
  }

  return 0;
}
