// this program fix the bug: v1 use mapping file and unnamed semaphore

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

  fd = open("log.txt",O_RDWR,0);
  //write(fd,&zero,sizeof(int));
  ptr = mmap(NULL,sizeof(int),PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);

  if ((shm = shm_open("myshm", O_RDWR, 0)) < 0) {
	  perror("shm_open");
	  exit(1);
  }
  
  if (ftruncate(shm,sizeof(sem_t)) < 0) {
	  perror("shm_open");
	  exit(1);
  }
  
  if ((mutex = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED,shm, 0)) == MAP_SHARED ) {
	  perror("mmap");
	  exit(1);
  }
  
    for (i = 0; i < nloop; i++) {
      sem_wait(mutex);
      printf("child entered crititical section: %d\n", (*ptr)++);
      sleep(5);
      printf("child leaving critical section\n");
      sem_post(mutex);
      sleep(1);
    }
    exit(0);

}