/* condvar2.c

   purpse of condition variable: utilize CPU usage. Theads can be go to sleep status 
   and wake up when status of shared resource is changed instead of checking the shared 
   resource periodically. This can reduce effectively CPU load.
   
   Main thread starts to increase 'count' when the count is larger than a threshold.
   Before that, main thread just waits the status change of 'count' (so it goes to sleep)
   Another thread increases count from beginning.
   
*/
#include <time.h>
#include <pthread.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int count = 0;
int start = 20;
static void *
threadFunc(void *arg)
{

    int s, j;

    for (;;) {
        sleep(1);
      
        s = pthread_mutex_lock(&mtx);        

        count++;        /* Let consumer know another unit is countable */
		printf("Sub-thread:%d, count=%d\n", (int) pthread_self(), count);
        s = pthread_mutex_unlock(&mtx);
        if (count > start)
        s = pthread_cond_signal(&cond);         /* Wake sleeping Main */      
    }
    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t tid;
    int s, j;
    int totRequired = 100;           
                                       
    int done;
  
	s = pthread_create(&tid, NULL, threadFunc, NULL); 
    done = 0;

	pthread_mutex_lock(&mtx);
   
	while (count <= start) {            
	// steps on pthread_cond_wait()
	// 1. after get lock mutex above, check condition variable
	// 2. if condition variable is not signaled yet, auto release mutex and go to sleep status
	// 3. When time that condition variable is signaled, wake up current thread (consumer) and auto lock mutex and do next steps on shared resource 
	// after finish action on shared resource, release mutex.	
	printf("Main thread: waiting here until count=%d\n", start);		
	s = pthread_cond_wait(&cond, &mtx);       		
	}
	/* At this point, 'mtx' is locked... */
	printf("Main thread: start running, count=%d\n", count);
	pthread_mutex_unlock(&mtx);
	while (count > 0) {             /* Consume all countable units */
		/* Do something with produced unit */
		pthread_mutex_lock(&mtx);
		count++;
		printf("Main thread: count=%d\n",count);								
		done = count >= totRequired;
		s = pthread_mutex_unlock(&mtx);
		sleep(2);
		if (done)
		break;
	}
                    
    exit(0);
}
