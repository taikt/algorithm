#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFSIZE 4096

int main(){
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	// This keeps content of existing file, or creates new file
    // int fd = open("tempfile.txt", O_RDWR | O_CREAT, mode);
	
	// To erase content of existing file, use O_RDONLY | O_WRONLY | O_TRUNC. 
	// or creates new file
    int fd = open("tempfile.txt", O_RDONLY | O_WRONLY | O_TRUNC, mode); 
	
    //char buf[BUFFSIZE] = {'t', 'h', 'y', ' ', 'f', 'a', 'l', 'l'};
	char buf[BUFFSIZE] = "hello";
    //size_t n = sizeof(buf);
	printf("sizeof buf=%d, strlen=%d\n", sizeof buf, strlen(buf));
	size_t n = strlen(buf);
    if(write(fd, buf, n) < 0){
        printf("Error in write\n");
        printf("%s", strerror(errno));
        return 1;
    }

    close(fd);

    int fd2 = open("tempfile.txt", O_RDWR | O_APPEND);

    printf("appending dude:\n");
    //char buf2[6] = {',', ' ', 'd', 'u', 'd', 'e'};
	char buf2[6] = "world";
    //size_t p = sizeof(buf2);
	size_t p = strlen(buf2);
    if(write (fd2, buf2, p) < 0){
        printf("Error in write\n");
        printf("%s", strerror(errno));
        return 1;
    }

    char buf3[BUFFSIZE];
    lseek(fd2, 2, SEEK_SET);
    if(read(fd2, buf3, BUFFSIZE) < 0){
        printf("Error in read\n");
        printf("%s", strerror(errno));
        return 2;
    }
    int i;
	printf("final string\n");
    for (i = 0; i < strlen(buf3); ++i){
        printf("%c", buf3[i]);
    }
    printf("\n");

    close(fd2);

    return 0;
}