// based on unpv13, 5.2
// client gets lines from standard input and send to server
// server receives the line and send it back to client
// client receives the line and display to standard output

// this version improves str_cli, check 6.4, unpv13
// it helps str_cli doesn't block in read at stdin when it needs to read data from socket.
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 1024

#define max(x,y) ((x) > (y) ? (x) : (y))

int main(int argc, char** argv)
{
	int sockfd, n, counter = 0;
	char recv[MAXLINE +1];
	struct sockaddr_in servaddr;
	char ch, res;
	
	if (argc != 2) {
		perror("usage: a.out <IP_server>\n");
		exit(1);
	}
	// create a socket for client
	sockfd = socket(AF_INET, SOCK_STREAM,0);
	memset(&servaddr,0,sizeof(servaddr));
	
	// name the socket with server
	servaddr.sin_family = AF_INET;	
	servaddr.sin_port = 13; //servaddr.sin_port = htons(13);	
	servaddr.sin_addr.s_addr = inet_addr(argv[1]); //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// connect our socket to server socket
	if (connect(sockfd,(struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect error\n");
		exit(1);
	}
	
	// now, read, write via sockfd
    str_cli(stdin,sockfd);  

    exit(0);	
}

// select and blocking IO, RTT = 12.3 sec
void str_cli(FILE *fp, int fd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	int madfdp1;
	fd_set rset;
	
	FD_ZERO(&rset);
	for (;;) {
		FD_SET(fileno(fp), &rset);
		FD_SET(fd, &rset);
		madfdp1 = max(fileno(fp),fd) + 1;
		select(madfdp1, &rset, NULL, NULL, NULL);
		
		if (FD_ISSET(fd, &rset)) { // socket is readable
			if (readline(fd, recvline, MAXLINE) == 0)
				perror("server terminated poorly");
			printf("client: %s\n", recvline);
		}
		
		if (FD_ISSET(fileno(fp), &rset)) { // input is readable
			if (fgets(sendline, MAXLINE, fp) != NULL)
				write(fd, sendline, strlen(sendline));
			else 
				return;
		}
	}	
}

int readline(int fd, void *vptr, int len)
{
	int i, rc;
	char c, *ptr;
	
	ptr = vptr;
	for (i = 1; i < len; i++) {
		if (rc = read(fd,&c,1) == 1) {
			*ptr++ = c;
			if (c == '\n') break;
		} else if (rc == 0) {
			if (i == 1) return 0; // EOF, no data read
			else break; // EOF, some data was read
		} else 
			return -1;
	}
	
	*ptr = '\0'; // or *ptr = 0, similarly
	return i;
}