// 14.2, apiue

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>

char buf[500000];
int ntowrite;

void* read_func() {
	int opts;

    while (1) {
        sleep(2);
        opts = fcntl(fileno(stdin), F_GETFL);
        if (opts < 0) perror("error to get fcntl");

        opts = opts & (~O_NONBLOCK);

        if (fcntl(fileno(stdin), F_SETFL, opts) < 0)
        perror("error to set fcntl");

        ntowrite = read(fileno(stdin), buf, sizeof(buf));
	    fprintf(stderr, "[reader] read %d bytes\n", ntowrite-1);
    }
}

void* write_func() {

    int nwrite, val, opts;
	char *ptr;
    char buf2[500000];
		
	// set nonblocking
	val = fcntl(fileno(stdout), F_GETFL, 0);
	fcntl(fileno(stdout), F_SETFL, val | O_NONBLOCK); // turn flag on

	
	ptr = buf;
	
	while (1) {
		errno = 0;
        sleep(2);
        
		nwrite = write(fileno(stdout), ptr, ntowrite);
        fprintf(stderr, "[writer] nwrite = %d, errno = %d\n", nwrite-1, errno);
        memset(buf,0,sizeof(buf));
        nwrite = 0;
        ntowrite = 0;
	}
	
	// clear nonblocking
	//val = fcntl(fileno(stdout), F_GETFL, 0);
        
    opts = fcntl(fileno(stdout), F_GETFL);
    if (opts < 0) perror("error to get fcntl");

    opts = opts & (~O_NONBLOCK);

    if (fcntl(fileno(stdout), F_SETFL, opts) < 0)
    perror("error to set fcntl");
        
	
}

int main(void)
{

    pthread_t readth, writeth;
    pthread_create(&readth, NULL, read_func, NULL);
    pthread_create(&writeth, NULL, write_func, NULL);
    
    pthread_join(readth, NULL);
    pthread_join(writeth, NULL);

	exit(0);
}
