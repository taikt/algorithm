#include <stdio.h>
#include <pthread.h>

void thread() {
	for (int i=0; i<5; i++) {
		printf("%d \n",i);
	}
	sleep(15);	
}

int main() {
	pthread_t t;

	pthread_create(&t,NULL,thread, NULL);
	sleep(40);
	return 0;
}
