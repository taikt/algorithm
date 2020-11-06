#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pids[1000];
	int i;
	int n = 1000;

	/* Start children. */
	for (i = 0; i < n; ++i) {
	  if ((pids[i] = fork()) < 0) {
		perror("fork");
		abort();
	  } else if (pids[i] == 0) {
		DoWorkInChild(i+1);
		exit(0);
	  }
	}

	/* Wait for children to exit. */
	int status;
	pid_t pid;
	while (n > 0) {
	  pid = wait(&status);
	  printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
	  --n;  // TODO(pts): Remove pid from the pids array.
	}

	exit(0);
}

void DoWorkInChild(int i)
{
	int k;
	for (k=0; k<i; k++)
	printf("this is child PID=%d, %d,%d\n",getpid(),i,k);
}

