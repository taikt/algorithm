#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    ssize_t nrd;
    int fd;
    int fd1;
    char buffer[64];

    fd = open("file1.txt", O_RDONLY);
    fd1 = open("file2.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    printf("fd1=%d, fd2=%d\n",fd,fd1);

    while (nrd = read(fd,buffer,4)) {
        write(fd1,buffer,nrd);
    }

    close(fd);
    close(fd1);
}
