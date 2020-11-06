// In this program, parent and child have its own memomy spacce 
// of 'count' global variable.
// 'count' cannot shared between parent and child
// To synchorize the 'count ' variable, we use a named mutex

// make shared memory for 'count'

#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int count = 0;

int main(int argc, char **argv)
{
  int i,nloop=5,zero=0,*count, fd;
  sem_t *mutex;
  int shm, value=0;
  char buf[16];
#if 0
// just use file descriptor by I/O system calls
fd = open("log",O_RDWR|O_CREAT,S_IRWXU);
write(fd,&zero,sizeof(int));
#endif  

#if 0  
  // mapped file
  fd = open("log",O_RDWR|O_CREAT,S_IRWXU);
  write(fd,&zero,sizeof(int));
  count = mmap(NULL,sizeof(int),PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);
#endif  

#if 0 
  // anonymous mapping
  count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, 0, 0);
#endif

#if 1  
  // shared memory
   if ((shm = shm_open("myshmn", O_RDWR | O_CREAT, S_IRWXU)) < 0) {
	  perror("shm_open");
	  exit(1);
  }
  shm_unlink("myshmn");
  if (ftruncate(shm,sizeof(int)) < 0) {
	  perror("shm_open");
	  exit(1);
  }
  
  count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED,shm, 0); 

#endif
  
  //if ((mutex = sem_open("semap", O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED) {
  if ((mutex = sem_open("semat", O_CREAT, 0644, 1)) == SEM_FAILED) {
	perror("semaphore initilization");
    exit(0);  
  }
  sem_unlink("semat");
  
  if (fork() == 0) {
	  for (i =0; i < nloop; i++) {
		  sem_wait(mutex);
		  printf("child:%d\n", (*count)++);
#if 0		  
		  read(fd,buf,sizeof(int));
		  value = atoi(buf);
		  //printf("child: value=%d\n",value);
		  value++;
		  printf("child:%d\n",value);
		  sprintf(buf,"%d",value);
		  write(fd,buf,sizeof(int));
#endif		  
		  sleep(2);
		  sem_post(mutex);
		  sleep(2);
	  }
  }
  
  /* back to parent process */
  for (i = 0; i < nloop; i++) {
    sem_wait(mutex);
    printf("parent: %d\n", (*count)++);
#if 0	
	read(fd,buf,sizeof(int));
	value = atoi(buf);
	value++;
	printf("parent:%d\n",value);
	sprintf(buf,"%d",value);
	write(fd,buf,sizeof(int));
#endif	
    sem_post(mutex);
	sleep(1);
  }
  wait(NULL);
  exit(0);
}