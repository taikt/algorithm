// this program fix the bug: v1 use shared memory and unnamed semaphore

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
  int shm, shm_fd;

  //open a file and map it into memory
  
  /* create the shared memory segment as if it was a file */
  shm_fd = shm_open("shm_data", O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
    printf("prod: Shared memory failed: %s\n", strerror(errno));
    exit(1);
  }
  
  ftruncate(shm_fd, 4096);
  
  ptr = mmap(NULL,sizeof(int),PROT_READ |PROT_WRITE,MAP_SHARED,shm_fd,0);
 

  if ((shm = shm_open("myshm", O_RDWR | O_CREAT, S_IRWXU)) < 0) {
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
  
  /* create, initialize semaphore */
  if( sem_init(mutex,1,1) < 0)
    {
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
  
   close(shm_fd);
   
  exit(0);
}