#include <stdio.h>

int main ()
{
#if 0
   FILE *fp;

   printf("This text is redirected to stdout\n");

   fp = freopen("file.txt", "w+", stdout);

   printf("This text is redirected to file.txt\n");

   fclose(fp);
   
#endif

#if 1
	FILE *fp;
	int N;
	fp = freopen("input.txt","r",stdin);
	// read input is redirected to the file instead of stdin
	scanf("%d",&N);
	printf("N=%d\n", N);

	fclose(fp);
#endif
   return(0);
}