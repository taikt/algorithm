#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#if 0
main(int argc, char **argv)
{
	if (fork())		/* fork, assume it always works */
		for (;;)	/* parent prints a message forever */
			printf("I’m the parent\n");
	else {	/* we’re the child */
		sleep(3);	/* do nothing for three seconds */
		kill(getppid(), SIGKILL);	/* kill the parent */
	}
}
#endif


main(int argc, char **argv)
{
	if (fork())	{	/* fork, assume it always works here */
		/* --------- parent --------- */
		void catchme();			/* signal handling function */
		signal(SIGUSR1, catchme);	/* call catchme if we get SIGUSR1 */
		for (;;)	/* parent prints a message forever */
			printf("I’m the parent\n");
	}
	else {	/* we’re the child */
		sleep(3);	/* do nothing for 3 seconds */
		kill(getppid(), SIGUSR1);	/* send SIGUSR1 to the parent */
	}
}

void
catchme() {	/* signal handler */
	printf("got the signal!\n");
	exit(0);
}