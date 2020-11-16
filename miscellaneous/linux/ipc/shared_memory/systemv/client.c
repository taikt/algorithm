#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    unsigned short *g_pAmixCheck;
    //int *g_pAmixCheck;
    void * shm_addr;
    int shm_id;
    key_t key;
    
    key = ftok("/tmp/shared_key",'K');

    if ( -1 == ( shm_id = shmget(key,12, IPC_CREAT | 0666)))
    {
        printf("eroor to allocate mem\n");
    }
    if ( ( void *)-1 == ( shm_addr = shmat( shm_id, ( void *)0, 0)))
    {
        printf("eroor to mapping mem\n");
    }


    g_pAmixCheck = (unsigned short*)(shm_addr);
    //g_pAmixCheck = (int*)(shm_addr);
    /*
    g_pAmpGainCheck = ((unsigned short*)(shm_addr)+1);
    g_pMicGainCheck = ((unsigned short*)(shm_addr)+2);
    g_pQCAmixCheck = ((unsigned short*)(shm_addr)+3);
    g_pBUBAmpGain = ((unsigned short*)(shm_addr)+4);
    g_pPowerStatus = ((unsigned short*)(shm_addr)+5);
    */
    printf("SHM(%d,%d) : %d\n",shm_id, (int)g_pAmixCheck,(int)*g_pAmixCheck);

    return 0;
}
