// based on unpv13, 5.2
// concurrent server using fork()
// client gets lines from standard input and send to server
// server receives the line and send it back to client
// client receives the line and display to standard output

#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#define MAXLINE 1024

int main()
{
	int listenfd, connfd, n;
	struct sockaddr_in servaddr;
	char ch;
	pid_t childpid;
	
	// create and name a socket for the server
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr,0,sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	
	servaddr.sin_port = 13; //servaddr.sin_port = htonl(13);
	
	bind(listenfd,(struct sockaddr *)&servaddr, sizeof(servaddr));
	
	// create a connection queue
	listen(listenfd, 1024);
	
	for (;;) {
		printf("server waiting..\n");
		
		connfd = accept(listenfd,(struct sockaddr*) NULL, NULL);
		printf("servering client on fd=%d\n",connfd);
		
		if ((childpid = fork()) == 0) {
			close(listenfd); // close listening socket
			str_echo(connfd); // process the request
			exit(0);
		}
		
		close(connfd); //parent closes connected socket		
	}
}

void str_echo(int fd)
{
	int n;
	char buf[MAXLINE];
	
	again:
	while ((n = read(fd,buf,MAXLINE)) > 0)
		write(fd,buf,n);
	
	if (n < 0 && errno == EINTR) // check errno here http://man7.org/linux/man-pages/man3/errno.3.html
		goto again;
	else if (n < 0) 
		perror("read error");
}