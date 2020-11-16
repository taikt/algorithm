// 14.2, apiue

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

char buf[500000];

int main(void)
{
	int ntowrite, nwrite, val;
	char *ptr;
	
	ntowrite = read(fileno(stdin), buf, sizeof(buf));
	fprintf(stderr, "read %d bytes\n", ntowrite);
	
	// set nonblocking
	val = fcntl(fileno(stdout), F_GETFL, 0);
	fcntl(fileno(stdout), F_SETFL, val | O_NONBLOCK); // turn flag on

	
	ptr = buf;
	
	while (ntowrite > 0) {
		errno = 0;
		nwrite = write(fileno(stdout), ptr, ntowrite);
		printf("no data available\n");
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
		if (nwrite > 0) {
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
	
	// clear nonblocking
	val = fcntl(fileno(stdout), F_GETFL, 0);
	fcntl(fileno(stdout), F_SETFL, val & ~O_NONBLOCK); // turn flags off
	
	exit(0);
}
