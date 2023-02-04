#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int file1, file2;
    ssize_t nread;
    char buffer[1024];

    if(argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    file1 = open(argv[1], O_RDONLY);
    if(file1 == -1) {
        perror("Error opening source file");
        return 2;
    }

    file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(file2 == -1) {
        perror("Error opening destination file");
        return 3;
    }

    while((nread = read(file1, buffer, sizeof(buffer))) > 0) {
        if(write(file2, buffer, nread) != nread) {
            perror("Error writing to destination file");
            return 4;
        }
    }

    close(file1);
    close(file2);

    return 0;
}
