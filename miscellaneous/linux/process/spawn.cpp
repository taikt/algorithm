/* how to use posix_spawn to create new child process
 * https://www.systutorials.com/37124/a-posix_spawn-example-in-c-to-create-child-process-on-linux/
 * 
 * gcc spawn.c
 * ./a.out "program_name"
 *  ./a.out ls (==> run sh -c ls)
 * */


#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

extern char **environ;

void run_cmd(char *cmd)
{
    pid_t pid;
    //char *argv[] = {"sh", "-c", cmd, NULL};
    string str_cmd="8.8.8.8";
    char * cmd1 = const_cast<char*>(str_cmd.c_str());
    int status;
    printf("Run command: %s\n", cmd1);
    //char *argv[] = {"sh", "-c",cmd1, NULL};
    //char *argv[] = {"ping",cmd1, NULL};
    //char *argv[] = {"ping","8.8.8.8", NULL};
    //char *argv[] = {"tcpdump","-i","enp0s8", NULL};
    char *argv[] = {"sh","-c","tcpdump -i enp0s8 &> /var/log.txt", NULL};
    status = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);
    //status = posix_spawn(&pid, "/bin/ping", NULL, NULL, argv, environ);
    //status = posix_spawn(&pid, "/usr/sbin/tcpdump", NULL, NULL, argv, environ);
    if (status == 0) {
        printf("Child pid: %i\n", pid);
#if 0
        if (waitpid(pid, &status, 0) != -1) {
            printf("Child exited with status %i\n", status);
        } else {
            perror("waitpid");
        }
#endif
    } else {
        printf("posix_spawn: %s\n", strerror(status));
    }
}

int main(int argc, char* argv[])
{
    run_cmd(argv[1]);
    return 0;
}
