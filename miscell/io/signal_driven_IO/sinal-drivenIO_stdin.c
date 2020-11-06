// 63.3, LPI
// enalle signal-driven IO on standard input

// Chuong trinh chinh lap vo han, tang bien cnt, trong 
// khi doi input co data de in ra man hinh gia tri cnt
// khi co data, kernel signal cho chuong trinh chinh biet input 
// da san sang data hoac chua.

#include <signal.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>


static volatile sig_atomic_t gotSigio = 0; // khong cho phep compiler toi uu bien gotSigio

static void sigioHandler(int sig) {
	gotSigio = 1;
}

int main() 
{
	int flags, j, cnt;
	char ch;
	int done;
	struct sigaction sa;
	struct termios origTermios;
	
	// thanh lap bo xu ly cho tin hieu "IO possible"
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sigioHandler;
	if (sigaction(SIGIO, &sa, NULL) == -1) {
		perror("error on sigaction");
		exit(1);
	}
	
	// set owner process de nhan tin hieu "IO possible"
	fcntl(fileno(stdin), F_SETOWN, getpid());
	
	// enable tin hieu "IO possible" va set IO nonblocking cho fd
	flags = fcntl(fileno(stdin), F_GETFL);
	fcntl(fileno(stdin), F_SETFL, flags | O_ASYNC | O_NONBLOCK);
	
	// set terminal in cbreak mode?
	// Normally, the tty driver buffers typed characters until 
	// a newline or carriage return is typed. The cbreak routine 
	// disables line buffering and erase/kill character-processing 
	// (interrupt and flow control characters are unaffected), making 
	// characters typed by the user immediately available to the program. 
	
	//ttySetCbreak(fileno(stdin), &origTermios);
	
	for (done = 0, cnt = 0; !done ; cnt++) {
		for (j = 0; j < 100000000; j++)
			continue; /* Slow main loop down a little */
		
		if (gotSigio) { /* Is input available? */
			/* Read all available input until error (probably EAGAIN)
			or EOF (not actually possible in cbreak mode) or a
			hash (#) character is read */
			while (read(fileno(stdin), &ch, 1) > 0 && !done) {				
				if (ch == '\n') printf("cnt=%d; read %s\n", cnt, "\\n");
				else printf("cnt=%d; read %c\n", cnt, ch);
				
				done = ch == '#';
			}
			
			gotSigio = 0;
		}
	}
	/* Restore original terminal settings */
	//tcsetattr(fileno(stdin), TCSAFLUSH, &origTermios);

	exit(0);
	
}