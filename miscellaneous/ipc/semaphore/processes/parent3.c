// this program fix the bug: v1 use mapping file and named semaphore

#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv)
{
  int fd, i,count=0,nloop=10,zero=0,*ptr;
  sem_t *mutex;
  int shm;

  //open a file and map it into memory

  fd = open("log.txt",O_RDWR|O_CREAT,S_IRWXU);
  write(fd,&zero,sizeof(int));
  ptr = mmap(NULL,sizeof(int),PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);

  // assign value of 1 to semaphore
  //if ((mutex = sem_open("semap", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
  if ((mutex = sem_open("semap", O_CREAT, 0644, 1)) == SEM_FAILED) {
	perror("semaphore initilization");
    exit(0);  
  }
  
  /* back to parent process */
  for (i = 0; i < nloop; i++) {
    sem_wait(mutex);
    printf("parent entered critical section: %d\n", (*ptr)++);
    sleep(2);
    printf("parent leaving critical section\n");
    sem_post(mutex);
    sleep(1);
  }
  exit(0);
}