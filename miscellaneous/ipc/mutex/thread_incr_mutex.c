/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 30-1 */

/* thread_incr.c

   This program employs two POSIX threads that increment the same global
   variable, without using any synchronization method. As a consequence,
   updates are sometimes lost.

   See also thread_incr_mutex.c.
*/
#include <pthread.h>


int glob = 0;   
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void * threadFunc_a(void *arg) {
    int loops = *((int *) arg);
    int loc, j;

    for (j = 0; j < loops; j++) {
		pthread_mutex_lock(&mtx);
        loc = glob;
        loc++;
        glob = loc;	
		pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

static void * threadFunc_b(void *arg) {
    int loops = *((int *) arg);
    int loc, j;

    for (j = 0; j < loops; j++) {
		pthread_mutex_lock(&mtx);
        loc = glob;
        loc++;
        glob = loc;	
		pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
    if (argc != 2)
	{
		printf("usage: a.out <#loops>\n");
		exit(0);
	}	
    loops = atoi(argv[1]);

    s = pthread_create(&t1, NULL, threadFunc_a, &loops);
    if (s != 0)
        perror(s, "pthread_create");
    s = pthread_create(&t2, NULL, threadFunc_b, &loops);
    if (s != 0)
        perror("pthread_create");

    s = pthread_join(t1, NULL);
    if (s != 0)
        perror("pthread_join");
    s = pthread_join(t2, NULL);
    if (s != 0)
        perror("pthread_join");

    printf("glob = %d\n", glob);
    exit(0);
}
