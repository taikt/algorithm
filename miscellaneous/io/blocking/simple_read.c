#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    char buffer[128];
    int nread;
    int opts;

    //fcntl(fileno(stdout), F_GETFL, 0);
    //fcntl(fileno(stdin), F_GETFL, 0);
    
    opts = fcntl(fileno(stdin), F_GETFL);
    if (opts < 0) perror("error to get fcntl");
    
    opts = opts & (~O_NONBLOCK);
    
    if (fcntl(fileno(stdin), F_SETFL, opts) < 0)
    perror("error to set fcntl");


    nread = read(0, buffer, 128);
    printf("I have data\n");
    if (nread == -1)
        write(2, "A read error has occurred\n", 26);

    if ((write(1,buffer,nread)) != nread)
        write(2, "A write error has occurred\n",27);

    exit(0);
}
