/* vsnprintf example */
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <string>
using namespace std;

#define TAG __FILE__,__func__
void PrintFError (const char *file, const char *func, const char * format, ... )
{
  char buffer[1000]={0,};
  cout<<func;
  va_list args;
  va_start (args, format);
  vsnprintf (buffer,999,format, args);
  perror (buffer);
  va_end (args);
}

int main ()
{
   FILE * pFile;
   char szFileName[]="myfile.txt";
   string st = " Error opening 2342";

   pFile = fopen (szFileName,"r");
   if (pFile == NULL)
     //PrintFError ("Error opening '%s'",szFileName);
     PrintFError(TAG,st.c_str());
   else
   {
     // file successfully open
     fclose (pFile);
   }
   return 0;
}
