// https://github.com/skuhl/sys-prog-examples/blob/master/simple-examples/chroot.c

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h> // EXIT_FAILURE

int main() {

	char buf[1024];
	getcwd(buf, 1024);
	printf("current directory:%s\n",buf);

	struct stat statBuf;
	if (stat("/file",&statBuf) == -1)
		perror("stat(/file)");
	else
		printf("/file exist\n");

	if (chroot(buf) == -1) {
		perror("chroot");
		exit(EXIT_FAILURE);
	}

	chdir(buf); // de tao "secure" chroot jail

	// tu luc nay, chuong trinh xem duong dan root "/" 
	// nam tai duong dan hien tai
	getcwd(buf, 1024);
	printf("current directory:%s\n",buf);

	if (stat("/file",&statBuf) == -1)
		perror("stat(/file)");
	else
		printf("/file exist\n");

	return 0;
}