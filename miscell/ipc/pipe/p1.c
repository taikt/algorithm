// popen is to open a process by creating a pipe, forking and invoking the shell.
// pipe: | , to connect many process a same time. i.e ps -ef | sort 
// compared to fopen... just open a file
// http://man7.org/linux/man-pages/man3/popen.3.html
// http://www.sw-at.com/blog/2011/03/23/popen-execute-shell-command-from-cc/
// http://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
#include <stdio.h>
  
int main()
{
	FILE * p;
	char str[64];
	p = popen("ping 8.8.8.8","r");

	if (!p) exit(1);
	while (fgets(str,sizeof(str),p))
	{
		printf("%s\n", str);
	}
	
	return 0;
}