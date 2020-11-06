#include <stdio.h>
#include <stdlib.h>
//#include <sys/wait.h>
//#include <sys/types.h>
int main()
{
	pid_t pid;
	int n, i, exit_code;
	char* message;
	
	printf("xxx Parent ID=%d\n", getppid());
//#if 0	
	pid = fork();

	switch (pid)
	{
		case -1:
			//printf("create process fail\n");
			perror("fork failed");
			exit(1);
			//break;
		case 0:
			n = 2;
			message = "This is child";
			exit_code = 37;
			break;
		default:
			n = 5;
			message = "This is parent";
			printf("Child ID=%d\n",pid);
			//sprintf(message, "This is parent, ID=%d",pid);
			exit_code = 0;
			break;
	}
	i = n;
	for (i; i>0; i--)
	{
		puts(message);
		sleep(3);
	}
//#if 0	
	if (pid != 0)
	{
		int stat;
		pid_t childID;
		childID = wait(&stat);
		printf("child finished: PID = %d\n", childID);
		if (WIFEXITED(stat))
			printf("child exited with code %d\n", WEXITSTATUS(stat));
		else 
			printf("child exited abnormally\n");
	}
//#endif 
	
//#endif 	
	exit(exit_code);
}