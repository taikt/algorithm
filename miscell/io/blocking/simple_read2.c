#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void* read_func() {
    int opts,n;
    char buf[1024];
    while (1) {
        sleep(2);
        opts = fcntl(fileno(stdin), F_GETFL);
        if (opts < 0) perror("error to get fcntl");

        opts = opts & (~O_NONBLOCK);

        if (fcntl(fileno(stdin), F_SETFL, opts) < 0)
        perror("error to set fcntl");

        n = read(fileno(stdin), buf, sizeof(buf));
        printf("[reader] read %d bytes from keyboard: %s\n", n-1, buf);
    }
}

void* other_func() {
	while (1) {
		sleep(1);
		printf("[other] do somthing else\n");
	}
}

int main()
{
    char buffer[128];
    int nread;
    int opts;

    //fcntl(fileno(stdout), F_GETFL, 0);
    //fcntl(fileno(stdin), F_GETFL, 0);
    pthread_t readth, otherth;
	pthread_create(&readth, NULL, read_func, NULL);
	pthread_create(&otherth, NULL, other_func, NULL);

	pthread_join(readth, NULL);
	pthread_join(otherth, NULL);
	    

    exit(0);
}
