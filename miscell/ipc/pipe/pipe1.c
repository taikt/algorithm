// http://tldp.org/LDP/lpg/node11.html

/*****************************************************************************
 Excerpt from "Linux Programmer's Guide - Chapter 6"
 (C)opyright 1994-1995, Scott Burkett
 ***************************************************************************** 
 MODULE: pipe.c
 *****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int fd[2], nbytes;
	pid_t   childpid;
	char    string[] = "Hello, world!\n";
	char    readbuffer[80];
	
	// create two descriptor fd[0], fd[1]
	// fd[0]: input side (read)
	// fd[1]: output side (write)
	// create 1 pipe -> one-drirection flow of data
	// create 2 pipe -> two-drirection flow of data
	pipe(fd);
	
	if((childpid = fork()) == -1)
	{
			perror("fork");
			exit(1);
	}

	if(childpid == 0)
	{
			/* Child process closes up input side of pipe */
			close(fd[0]);

			/* Send "string" through the output side of pipe */
			write(fd[1], string, (strlen(string)+1));
			exit(0);
	}
	else
	{
			/* Parent process closes up output side of pipe */
			close(fd[1]);

			/* Read in a string from the pipe */
			nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
			printf("Received string: %s", readbuffer);
	}
	
	return(0);
}