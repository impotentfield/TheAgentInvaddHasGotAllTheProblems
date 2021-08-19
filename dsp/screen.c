#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <signal.h>
#include <sys/time.h>
#include <ncurses.h>

WINDOW * mainwin;

int rows, cols;

int oldcur;


void initialize_curses_screen()
{

    if ( (mainwin = initscr()) == NULL ) {
        perror("error initialising ncurses");
        exit(EXIT_FAILURE);
    }

	GetTermSize();

    noecho();
    keypad(mainwin, TRUE);
    oldcur = curs_set(0);

}


void GetTermSize() {

	int mx, my;
	getmaxyx(stdscr, mx, my);
   
	rows = mx;
	cols = my;
		
}


/*  Signal handler  */

void handler(int signum) {

    extern WINDOW * mainwin;
    extern int oldcur;


        delwin(mainwin);
        curs_set(oldcur);
        endwin();
        refresh();
        exit(EXIT_SUCCESS);
	
}

/*  Sets up signal handlers we need  */

void SetSignals(void) {

    struct sigaction sa;


    /*  Fill in sigaction struct  */

    sa.sa_handler = handler;
    sa.sa_flags   = 0;
    sigemptyset(&sa.sa_mask);


    /*  Set signal handlers  */

    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGINT,  &sa, NULL);
    sigaction(SIGALRM, &sa, NULL);


    /*  Ignore SIGTSTP  */

    sa.sa_handler = SIG_IGN;
    sigaction(SIGTSTP, &sa, NULL);
}
