#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

// gcc s1.c -pthread -lrt
// http://blog.superpat.com/2010/07/14/semaphores-on-linux-sem_init-vs-sem_open/

// this program have bug
// parent and child access critical session at same time.
// reason: mutex need to belong a share memory area
#if 0
int main(int argc, char **argv)
{
  int fd, i,count=0,nloop=10,zero=0,*ptr;
  sem_t mutex;

  //open a file and map it into memory

  fd = open("log.txt",O_RDWR|O_CREAT,S_IRWXU);
  write(fd,&zero,sizeof(int));
  ptr = mmap(NULL,sizeof(int),PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);

  /* create, initialize semaphore */
  if( sem_init(&mutex,1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(&mutex);
      printf("child entered crititical section: %d\n", (*ptr)++);
      sleep(2);
      printf("child leaving critical section\n");
      sem_post(&mutex);
      sleep(1);
    }
    exit(0);
  }
  /* back to parent process */
  for (i = 0; i < nloop; i++) {
    sem_wait(&mutex);
    printf("parent entered critical section: %d\n", (*ptr)++);
    sleep(2);
    printf("parent leaving critical section\n");
    sem_post(&mutex);
    sleep(1);
  }
  exit(0);
}
#endif

#if 1
// this program fix the bug: v1 use share memory and unnamed semaphore
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
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(mutex);
      printf("child entered crititical section: %d\n", (*ptr)++);
      sleep(2);
      printf("child leaving critical section\n");
      sem_post(mutex);
      sleep(1);
    }
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
#endif 

#if 0
// this program fix the bug: v2 anonymous memory and unnamed semaphore
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

  mutex = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
  if (!mutex) {
    perror("out of memory\n");
    exit(1);
  }
  
  /* create, initialize semaphore */
  if( sem_init(mutex,1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(mutex);
      printf("child entered crititical section: %d\n", (*ptr)++);
      sleep(2);
      printf("child leaving critical section\n");
      sem_post(mutex);
      sleep(1);
    }
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
#endif

#if 0
// this program fix the bug: v3 use named semaphore
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
  if ((mutex = sem_open("mysemap", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
	perror("semaphore initilization");
    exit(0);  
  }
  // remove semaphore name from filesystem, but destruction is not happend yet
  // semaphore stays until sem_close()
  sem_unlink("mysemap"); 

  
  // still need init value for a named semaphore?

  /* create, initialize semaphore */
  //if( sem_init(mutex,1,1) < 0)
  //  {
  //    perror("semaphore initilization");
  //    exit(0);
  //  }
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(mutex);
      printf("child entered crititical section: %d\n", (*ptr)++);
      sleep(2);
      printf("child leaving critical section\n");
      sem_post(mutex);
      sleep(1);
    }
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
#endif