// based on unpv13, 5.2
// client gets lines from standard input and send to server
// server receives the line and send it back to client
// client receives the line and display to standard output

// this version improves str_cli, check 6.7, unpv13
// it corrects standard I/O and operate in buffer (read,write) instead of line (fgets,readline)

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

// select and blocking IO, RTT = 12.3sec
void str_cli(FILE *fp, int fd)
{
	char buf[MAXLINE];
	int madfdp1, stdineof;
	fd_set rset;
	int n;
	
	stdineof = 0;
	FD_ZERO(&rset);
	for (;;) {
		if (stdineof == 0)
			FD_SET(fileno(fp), &rset);
		FD_SET(fd, &rset);
		madfdp1 = max(fileno(fp),fd) + 1;
		select(madfdp1, &rset, NULL, NULL, NULL);
		
		if (FD_ISSET(fd, &rset)) { // socket is readable
			if ((n = read(fd, buf, MAXLINE)) == 0) {
				if (stdineof == 1)
					return;
				else
				{
					perror("str_cli: sever terminated prematurely");
					exit(1);
				}
			}
			write(fileno(stdout), buf, n); //or printf("client:%s\n", buf);			
		}
		
		if (FD_ISSET(fileno(fp), &rset)) { // input is readable
			if ((n = read(fileno(fp), buf, MAXLINE)) == 0) {
				stdineof = 1;
				shutdown(fd, SHUT_WR); // send FIN
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			write(fd, buf, n);			
		}
	}	
}
