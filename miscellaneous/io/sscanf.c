#include <stdio.h>
#include <stdlib.h>

int main()
{
   int day, year;
   char weekday[20], month[20], dtm[100];

   strcpy( dtm, "Saturday March 25 1989" );
   //sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );
   sscanf( dtm, "Saturday March %d  %d", &day, &year );

   //printf("%s %d, %d = %s\n", month, day, year, weekday );
   printf("%d, %d\n",day, year); 
   return(0);
}