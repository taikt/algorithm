/* Example code for starting
 * 2 threads and synchronizing  
 * their operation using a message_queue.
 *
 * All code provided is as is 
 * and not completely tested
 *
 * Author: Aadil Rizvi
 * Date: 6/1/2016
 * Modified by Thomas
*/

// https://www.youtube.com/watch?v=i0XUbhIBbEc
// https://github.com/arembedded/mq_example
// https://www.cs.cf.ac.uk/Dave/C/node25.html
// compile: gcc mq2.c -lpthread -lrt 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <fcntl.h>
#include <errno.h>

#define MY_MQ_NAME "/my_mq"

pthread_t thread1;
pthread_t thread2;

static struct mq_attr my_mq_attr;
static mqd_t my_mq;

typedef struct msgbuf {
	unsigned int mtype;
	char mtext[128];
} message_buf;

static unsigned int counter;
message_buf sbuf;

void thread1_main(void);
void thread2_main(void);

void sig_handler(int signum) {
    if (signum != SIGINT) {
        printf("Received invalid signum = %d in sig_handler()\n", signum);        
    }

    printf("Received SIGINT. Exiting Application\n");

    pthread_cancel(thread1);
    pthread_cancel(thread2);

    mq_close(my_mq);
    mq_unlink(MY_MQ_NAME);

    exit(0);
}

int main(void) {
    pthread_attr_t attr;
    int status;
	
	
    signal(SIGINT, sig_handler);

    //counter = 0;

    my_mq_attr.mq_maxmsg = 10;
    my_mq_attr.mq_msgsize = sizeof(message_buf);

    my_mq = mq_open(MY_MQ_NAME, \
                    O_CREAT | O_RDWR | O_NONBLOCK, \
                    0666, \
                    &my_mq_attr);


    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 1024*1024);
   
    printf("Creating thread1\n");
    status = pthread_create(&thread1, &attr, (void*)&thread1_main, NULL);
    if (status != 0) {
        printf("Failed to create thread1 with status = %d\n", status);       
    }    

    printf("Creating thread2\n");
    status = pthread_create(&thread2, &attr, (void*)&thread2_main, NULL);
    if (status != 0) {
        printf("Failed to create thread2 with status = %d\n", status);
    }    

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sig_handler(SIGINT);
    
    return 0;
}

void thread1_main(void) {
    unsigned int exec_period_usecs;
    int status;

    exec_period_usecs = 1000000; /*in micro-seconds*/

    printf("Thread 1 started. Execution period = %d uSecs\n",\
                                           exec_period_usecs);
    while(1) {
		sbuf.mtype = counter;
		strcpy(sbuf.mtext,"Hello world");
        status = mq_send(my_mq,&sbuf, sizeof(sbuf), 1);
    
        usleep(exec_period_usecs);
    }
}


void thread2_main(void) {
    unsigned int exec_period_usecs;
    int status;
    int recv_counter;

    exec_period_usecs = 10000; /*in micro-seconds*/

    printf("Thread 2 started. Execution period = %d uSecs\n",\
                                           exec_period_usecs);

    while(1) {
        status = mq_receive(my_mq, (char*)&sbuf, \
                            sizeof(sbuf), NULL);

        if (status > 0) {
            printf("RECVd MSG in THRD_2: %d-%s\n", sbuf.mtype,sbuf.mtext);
            counter += 1;
        }
 
        usleep(exec_period_usecs);
    }
}

