#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
	int listenfd, connfd, n;
	struct sockaddr_in servaddr;
	char ch;
	
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
		
		read(connfd,&ch, 1);
		printf("receive ch=%c\n",ch);
		
		sleep(3);		
		ch++;
		write(connfd,&ch,1);
		
		//close(connfd);
	}
}