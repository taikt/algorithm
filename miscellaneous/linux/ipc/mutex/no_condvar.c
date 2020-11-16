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

/* no_condvar.c

   A simple POSIX threads producer-consumer example that not use a condition variable.
*/
#include <time.h>
#include <pthread.h>
#include <stdio.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

static void *
threadFunc(void *arg)
{
    int cnt = atoi((char *) arg);
    int j;
    
	//pthread_id_np_t   tid;
    //tid = pthread_getthreadid_np();

    for (j = 0; j < cnt; j++) {
        sleep(1);

        /* Code to produce a unit omitted */

        pthread_mutex_lock(&mtx);   
        avail++;        /* Let consumer know another unit is available */
        printf("thread:%d, #items=%d\n", (int) pthread_self(), avail);
        pthread_mutex_unlock(&mtx);
              
    }

    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t tid;
    int s, j;
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
