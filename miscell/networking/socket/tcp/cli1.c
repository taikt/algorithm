#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 32

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
	// I cannot make a loop here! why?
#if 0	
	for (ch = 'a';ch < 'x'; ch++)
	{
		printf("send char=%c to server\n", ch);
		write(sockfd, &ch, 1);
		read(sockfd, &res, 1);
		printf("receive char=%c from server\n", res);
    }		
#endif
#if 1
    ch = 'x';
    printf("send char=%c to server\n", ch);
	write(sockfd, &ch, 1);	
	read(sockfd, &res, 1);
	printf("receive char=%c from server\n", res);   
#endif    
	close(sockfd);
    exit(0);	
}