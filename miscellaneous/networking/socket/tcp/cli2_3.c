// based on unpv13, 5.2
// client gets lines from standard input and send to server
// server receives the line and send it back to client
// client receives the line and display to standard output

// this version improves str_cli, 16.1, unpv13
// use nonblocking I/O
// this is best version in term of RTT, however, it is complex way.

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
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

// nonblocking IO, RTT=6.9 sec
void str_cli(FILE *fp, int fd)
{
	char buf[MAXLINE];
	int madfdp1, stdineof;
	fd_set rset, wset;
	int n, nwritten;
	char to[MAXLINE], fr[MAXLINE]; // get data from stdin and write to socket
	char *toiptr, *tooptr, *friptr, *froptr;
	int val;
	
	stdineof = 0;
	
	val = fcntl(fd,F_GETFL, 0);
	fcntl(fd, F_SETFL, val | O_NONBLOCK);
	
	val = fcntl(fileno(stdin),F_GETFL, 0);
	fcntl(fileno(stdin), F_SETFL, val | O_NONBLOCK);
	
	val = fcntl(fileno(stdout),F_GETFL, 0);
	fcntl(fileno(stdout), F_SETFL, val | O_NONBLOCK);
	
	toiptr = tooptr = to;
	friptr = froptr = fr;
	
	madfdp1 = max(max(fileno(stdin),fileno(stdout)),fd) + 1;
	
	for (;;) {
		FD_ZERO(&rset);
		FD_ZERO(&wset);
		//printf("start\n");
		if (stdineof == 0 && toiptr < &to[MAXLINE])
			FD_SET(fileno(stdin), &rset); // read from stdin
		if (friptr < &fr[MAXLINE])
			FD_SET(fd, &rset);			/* read from socket */
		if (tooptr != toiptr)
			FD_SET(fd, &wset);			/* data to write to socket */
		if (froptr != friptr)
			FD_SET(fileno(stdout), &wset);	/* data to write to stdout */
			
		select(madfdp1, &rset, &wset, NULL, NULL);
		//printf("dd");
		if (FD_ISSET(fileno(stdin), &rset)) { // input is readable
			if ((n = read(fileno(stdin), toiptr, &to[MAXLINE] - toiptr)) < 0) { 
				if (errno != EWOULDBLOCK) // return immediately if not data available
				{
					perror("read error on stdin");
					exit(1);
				} 
			} else if (n == 0){
				stdineof = 1;
				if (tooptr == toiptr)
				shutdown(fd, SHUT_WR); // send FIN
				//FD_CLR(fileno(fp), &rset);
				//continue;
			} else { // n > 0
				//printf("input is readable\n");
				toiptr += n;
				FD_SET(fd,&wset); //turn on bit of fd on wset, to prepare writing
			}
		}
		
		if (FD_ISSET(fd, &wset) && ((n = toiptr - tooptr) > 0)) {
			if ((nwritten = write(fd, tooptr, n)) < 0) {
				if (errno != EWOULDBLOCK) // return immediately no room avaible to write
				{
					perror("write error to socket");
					exit(1);
				} 
			} else {
					tooptr += nwritten;
					if (tooptr == toiptr) {
						toiptr = tooptr = to;
						if (stdineof) 
							shutdown(fd, SHUT_WR);  //send FIN
					}
				}		
		}
		
		if (FD_ISSET(fd, &rset)) { // socket is readable	       			
			if ((n = read(fd, friptr, &fr[MAXLINE] - friptr)) < 0) {
				if (errno != EWOULDBLOCK)
				{
					perror("write error to socket");
					exit(1);
				} 	
			} else if (n == 0) {				
				if (stdineof == 1)
					return;
				else
				{
					perror("str_cli: sever terminated prematurely");
					exit(1);
				}
			} else {
				friptr += n;
				FD_SET(fileno(stdout),&wset);
			}				
		}
		
		if (FD_ISSET(fileno(stdout), &wset) && ( (n = friptr - froptr) > 0)) {
			if ((nwritten = write(fileno(stdout), froptr, n)) < 0) {
				if (errno != EWOULDBLOCK)
					{
					perror("write error to stdout");
					exit(1);
					} 
			} else {
				froptr += nwritten;		/* # just written */
				if (froptr == friptr)
					froptr = friptr = fr;	/* back to beginning of buffer */
			}
		}
	}
}	

