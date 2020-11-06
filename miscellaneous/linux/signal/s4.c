//alarm signal

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alarm_handler(int signum) {
	printf("Buzz buzz\n");
	alarm(2);
}

int main(){
	signal(SIGALRM, alarm_handler);
	alarm(2);
	while(1){};
}