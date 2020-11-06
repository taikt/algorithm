//https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html


#define HxLog_Print(fmt,args...)\  
printf(fmt,args); \
//#define HxLog_Print1(fmt,args...)  printf(" " fmt, args)
int main()
{
	//printf("%s, %s\n",fmt, args);
	HxLog_Print("test");

	return 0;
}