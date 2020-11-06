//user signal

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void hello(int signum) {
printf("hello world\n");
}
int main()
{
	signal(SIGUSR1,hello);
	while(1)
	{};
	return 0;
}