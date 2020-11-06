#define _MULTI_THREADED
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include "check.h"

#define BUMP_PRIO 1
#define PRIORITY_MAX_NP 3
static int thePriority = 0;

void showSchedParam(pthread_attr_t *a)
{
  int                 rc=0;
  struct sched_param  param;

  printf("Get scheduling parameters\n");
  rc = pthread_attr_getschedparam(a, &param);
  checkResults("pthread_attr_getschedparam()\n", rc);

  printf("The thread attributes object indicates priority: %d\n",
         param.sched_priority);
  thePriority = param.sched_priority;
  return;
}

int main(int argc, char **argv)
{
  pthread_t             thread;
  int                   rc=0;
  pthread_attr_t        pta;
  struct sched_param    param;

  printf("Enter Testcase - %s\n", argv[0]);

  printf("Create a thread attributes object\n");
  rc = pthread_attr_init(&pta);
  checkResults("pthread_attr_init()\n", rc);

  showSchedParam(&pta);

  memset(&param, 0, sizeof(param));
  if (thePriority + BUMP_PRIO <= PRIORITY_MAX_NP) {
  param.sched_priority = thePriority + BUMP_PRIO;
  }

  printf("Setting scheduling parameters\n");
  rc = pthread_attr_setschedparam(&pta, &param);
  checkResults("pthread_attr_setschedparam()\n", rc);

  showSchedParam(&pta);

  printf("Destroy thread attributes object\n");
  rc = pthread_attr_destroy(&pta);
  checkResults("pthread_attr_destroy()\n", rc);

  printf("Main completed\n");
  return 0;
}