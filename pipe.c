#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Create an unnamed pipe
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("Error creating pipe");
    exit(1);
  }

  // Create a child process to execute the "ls" command
  pid_t pid = fork();
  if (pid == 0) {
    // In the child process, close the read end of the pipe
    close(pipefd[0]);

    // Redirect the output of the "ls" command to the write end of the pipe
    dup2(pipefd[1], 1);

    // Execute the "ls" command
    execlp("ls", "ls", NULL);

    // If execlp returns, there was an error
    perror("Error executing ls");
    exit(1);
  } else {
    // In the parent process, close the write end of the pipe
    close(pipefd[1]);

    // Create another child process to execute the "sort" command
    pid_t pid2 = fork();
    if (pid2 == 0) {
      // In the second child process, redirect the input of the "sort" command to the read end of the pipe
      dup2(pipefd[0], 0);

      // Execute the "sort" command
      execlp("sort", "sort", NULL);

      // If execlp returns, there was an error
      perror("Error executing sort");
      exit(1);
    }
  }

  return 0;
}
