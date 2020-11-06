// http://www.tldp.org/LDP/lpg/node12.html

#include <stdio.h>

#define MAXSTRS 5

int main(void)
{
        int  cntr, i;
        FILE *pipe_fp;
        char *strings[MAXSTRS] = { "echo", "bravo", "alpha",
                                  "charlie", "delta"};

for (i=0; i<10; i++)
{	
        /* Create one way pipe line with call to popen() */
        if (( pipe_fp = popen("sort", "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        /* Processing loop */
        for(cntr=0; cntr<MAXSTRS; cntr++) {
                fputs(strings[cntr], pipe_fp);
                fputc('\n', pipe_fp);
        }

        /* Close the pipe */
        pclose(pipe_fp); 
		printf("------------------------------\n");
}       
        return(0);
}