// https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_73/apis/rzah4mst.htm
// http://man7.org/linux/man-pages/man3/pthread_cancel.3.html
// https://lwn.net/Articles/683118/
// https://www.thegeekstuff.com/2012/04/terminate-c-thread
// https://stackoverflow.com/questions/13285375/how-to-kill-a-running-thread
//
#include <pthread.h>
#include <stdio.h>
#include "check.h"

void *threadfunc(void *parm)
{
  printf("Entered secondary thread\n");
  while (1) {


    printf("Secondary thread is looping\n");
    //pthread_testcancel();
    sleep(1);
  }
  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t             thread;
  int                   rc=0;

  printf("Entering testcase\n");
 
  /* Create a thread using default attributes */
  printf("Create thread using the NULL attributes\n");
  rc = pthread_create(&thread, NULL, threadfunc, NULL);
  checkResults("pthread_create(NULL)\n", rc);
 
  /* sleep() is not a very robust way to wait for the thread */
  sleep(5);

  printf("Cancel the thread\n");
  rc = pthread_cancel(thread);
  checkResults("pthread_cancel()\n", rc);

  /* sleep() is not a very robust way to wait for the thread */
  sleep(3);
  printf("Main completed\n");
  return 0;
}
