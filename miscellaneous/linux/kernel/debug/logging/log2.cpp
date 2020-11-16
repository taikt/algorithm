#include <stdio.h>
#include <stdarg.h> 

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"

#if 1
#define logme  printf("%s[logme] %s-%d-%s%s\n",KRED,__FILE__, __LINE__, __func__,RESET)
#else
#define logme 
#endif

#define LOG_BUF_SIZE 1024
typedef enum {
    FINVALID = -1,
    FAUDIO = 0,
    FPHONE = 1
} log_funcs;

typedef enum {
     LINVALID   = -1// Invalid level
    ,LPSNL      = 0 // Personal logging. Only for the function developer.
    ,LDBG       = 1 // Debug messages.,
    ,LINFO      = 2 // Informational. (default level)
    ,LNOTI      = 3 // Normal but significant condition. Don't use this to logging errors.
    ,LWARN      = 4 // Warning conditions. Not error but the system may become unstable
    ,LERR       = 5 // Error conditions
    ,LCERR      = 6 // The system or the function is unusable
    ,LCOUNT     = 7 // Level count
} log_levels;

#define SLOG(f, l, fmt, args...) do { (void)log_dprintf((f), (l), fmt, ##args); } while(0)
#define PLOG(f, l, tag, fmt, args...) do { (void)log_pprintf((f), (l), tag, fmt, ##args); } while(0)

#define LOGD(f,fmt,args...) SLOG(f,LDBG,fmt, ##args)
#define LOGW(f,fmt,args...) SLOG(f,LWARN,fmt, ##args)
#define LOG_ONEWAY(f,fmt,args...) PLOG(f,LDBG,"ipc",fmt, ##args)
#define LOG_THREADPOOL(f,fmt,args...) PLOG(f,LDBG,"threadpool",fmt, ##args)

int log_dprintf(log_funcs func, log_levels level, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return fprintf(stderr, "[func=%d][level=%d] %s\n", func, level, buf);
}

int log_pprintf(log_funcs func, log_levels level, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return fprintf(stderr, "[func=%d][level=%d] [tag=%s] %s\n", func, level, tag, buf);
}



int main() {
    LOGD(FAUDIO,">>>>audio log %d %s",1,"volume");
    LOGW(FPHONE,"phone log %d",2);
    LOG_ONEWAY(FPHONE,"phone log %d",3);
    LOG_THREADPOOL(FPHONE,"phone log %d",4);
        
    return 0; 
}
