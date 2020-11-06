// http://www.cs.miami.edu/home/burt/learning/Csc521.111/notes/process-life-cycle.html
// tai
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#define LONG_SLEEP 20
#define SHORT_SLEEP 10
#define N_CHILD 4

int main(int argc, char * argv  []) {
#if 0	
   int i = 0 ;
   pid_t pid ;
   int exit_status ;

   printf("Parent: starts\n") ;
   for (i=1;i<N_CHILD;i++ ) { 
      if ( !(pid = fork()) ) {
         /* child */
         printf("Child: starting %d\n", i ) ;
         fflush(NULL) ;
         sleep(SHORT_SLEEP) ;
         printf("Child: ending %d\n", i ) ;
         fflush(NULL) ;
         exit(i) ;
      }
      printf("Parent: forked child %d with pid %d\n", i, pid ) ;
      fflush(NULL) ;
   }
   sleep(LONG_SLEEP) ;
   printf("Parent: reaps ...\n") ;  
   for (i=1;i<N_CHILD;i++) {
      pid = wait(&exit_status) ;
      printf("Parent: child %d has exit code %d\n", 
         pid, WEXITSTATUS(exit_status)) ;
   }
   sleep(SHORT_SLEEP) ;
   printf("Parent: exits\n") ;  
   exit(0) ;
#endif

#if 1
	int i=0;
	while (1)
	{
		printf("%d\n",i); //process is always on sleeping status because I/O waiting 
		i++; //process is on running status 
	}
#endif	
}
