#include <stdio.h>
#include <unistd.h>

// chuong trinh nay bi fail, ko the chay chdir1

int main() {
	int res=chroot(".");
	chdir(".");
	if (res == 0)
		printf("ok\n");

	char *arr[]={"./chdir1",NULL};
	execvp("./chdir1",arr);	

	return 0;
}