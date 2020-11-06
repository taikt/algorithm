#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

int main()
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char ch;
	fd_set readfds, testfds;
	
	// create and name a socket for the server
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr,0,sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	
	servaddr.sin_port = 13; //servaddr.sin_port = htonl(13);
	
	bind(listenfd,(struct sockaddr *)&servaddr, sizeof(servaddr));
	
	// create a connection queue
	listen(listenfd, 1024);
	
	// initialize readfds to handle input from listenfd.
	FD_ZERO(&readfds);
    FD_SET(listenfd, &readfds);
	
	/*  Now wait for clients and requests.
    Since we have passed a null pointer as the timeout parameter, no timeout will occur.
    The program will exit and report an error if select returns a value of less than 1.  */	
	for (;;) {
		int fd, nread;
		
		printf("\nserver waiting..\n");
		testfds = readfds;
		
		if (select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *) 0) < 1) {
			perror("select error\n");
			exit(1);
		}
		
		/*  Once we know we've got activity,
		we find which descriptor it's on by checking each in turn using FD_ISSET.  */
		for(fd = 0; fd < FD_SETSIZE; fd++) {
			if(FD_ISSET(fd,&testfds)) {
				/*  If the activity is on listenfd, it must be a request for a new connection
				and we add the associated client_sockfd to the descriptor set.  */
				if(fd == listenfd) {       
                    connfd = accept(listenfd,(struct sockaddr*) NULL, NULL);
				
                    FD_SET(connfd, &readfds);
                    printf("adding client on fd= %d\n", connfd);
                }
				/*  If it isn't the server, it must be client activity.
				If close is received, the client has gone away and we remove it from the descriptor set.
				Otherwise, we 'serve' the client as in the previous examples.  */
				else {
					ioctl(fd, FIONREAD, &nread);
                    if(nread == 0) {
                        close(fd);
                        FD_CLR(fd, &readfds);
                        printf("removing client on fd %d\n", fd);
                    }
                    else {
						printf("servering client on fd=%d\n",fd);
                        read(fd, &ch, 1);
                        sleep(3);
                        printf("receive ch=%c\n",ch);
                        ch++;
                        write(fd, &ch, 1);
                    }
				}
				
			} 
		}
	}
}