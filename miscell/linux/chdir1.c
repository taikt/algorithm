#include <unistd.h>
#include <stdio.h>

int main() {
	char *directory ="/tmp";
	int ret;
	//printf("change directory");
	ret = chdir(directory);
	system("ls");

	return 0;
}