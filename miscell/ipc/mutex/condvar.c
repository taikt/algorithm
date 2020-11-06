/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Supplementary program for Chapter 30 */

/* prod_condvar.c

   A simple POSIX threads producer-consumer example using a condition variable.
   purpse of condition variable: utilize CPU usage. Theads can be go to sleep status 
   and wake up when status of shared resource is changed
   instead of checking the shared resource periodically. This can reduce effectively CPU load.
*/
#include <time.h>
#include <pthread.h>


static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

static void *
threadFunc(void *arg)
{
    int cnt = atoi((char *) arg);
    int j;

    for (j = 0; j < cnt; j++) {
        sleep(1);

        /* Code to produce a unit omitted */

        pthread_mutex_lock(&mtx);        

        avail++;        /* Let consumer know another unit is available */
		printf("thread:%d, #items=%d\n", (int) pthread_self(), avail);
        pthread_mutex_unlock(&mtx);
       
        pthread_cond_signal(&cond);         /* Wake sleeping consumer */      
    }
    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t tid;
    int j;
    int totRequired;            /* Total number of units that all threads
                                   will produce */
    int numConsumed;            /* Total units so far consumed */
    int done;
    time_t t;

    t = time(NULL);

    /* Create all threads */

    totRequired = 0;
    for (j = 1; j < argc; j++) {
        totRequired += atoi(argv[j]);

        pthread_create(&tid, NULL, threadFunc, argv[j]);       
    }

    /* Loop to consume available units */

    numConsumed = 0;
    done = 0;

    for (;;) {
        pthread_mutex_lock(&mtx);
       
        while (avail == 0) {            /* Wait for something to consume */
		// steps on pthread_cond_wait()
		// 1. after get lock mutex above, check condition variable
		// 2. if condition variable is not signaled yet, auto release mutex and go to sleep status
		// 3. When time that condition variable is signaled, wake up current thread (consumer) and auto lock mutex and do next steps on shared resource 
		// after finish action on shared resource, release mutex.	
        printf("consumer: I am waiting\n");		
		pthread_cond_wait(&cond, &mtx);       		
        }
		printf("consumer: I got signal\n");
        /* At this point, 'mtx' is locked... */
        while (avail > 0) {             /* Consume all available units */
            /* Do something with produced unit */
            numConsumed ++;
            avail--;
            printf("T=%ld: numConsumed=%d\n", (long) (time(NULL) - t),
                    numConsumed);
            done = numConsumed >= totRequired;
        }
        pthread_mutex_unlock(&mtx);       
        if (done)
            break;
        /* Perhaps do other work here that does not require mutex lock */
    }
    exit(0);
}
