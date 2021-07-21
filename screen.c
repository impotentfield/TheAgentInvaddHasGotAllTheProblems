#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <signal.h>
#include <sys/time.h>
#include <ncurses.h>

WINDOW * mainwin;

static int rows, cols;

void initialize_curses_screen()
{

    if ( (mainwin = initscr()) == NULL ) {
        perror("error initialising ncurses");
        exit(EXIT_FAILURE);
    }

    noecho();
    keypad(mainwin, TRUE);
    oldcur = curs_set(0);

}


void keyup()
{
    while ( 1 ) {
        int key = getch();

        switch ( key ) {

        case KEY_UP:

        break;
      
      	}
   }
}


void keydown()
{
    while ( 1 ) {
        int key = getch();

        switch ( key ) {

        case KEY_LEFT:

        break;
      
      	}
   }

}

void keyleft()
{

    while ( 1 ) {
        int key = getch();

        switch ( key ) {

        case KEY_DOWN:

        break;
      
      	}
   }

}

void keyright()
{

    while ( 1 ) {
        int key = getch();

        switch ( key ) {

        case KEY_RIGHT:

        break;
      
      	}
   }
}


void GetTermSize() {

    struct winsize ws;


    /*  Get terminal size  */

    if ( ioctl(0, TIOCGWINSZ, &ws) < 0 ) {
        perror("couldn't get window size");
        exit(EXIT_FAILURE);
    }
    

    /*  Update globals  */

    *rows = ws.ws_row;
    *cols = ws.ws_col;
}


/*  Signal handler  */

void handler(int signum) {

    extern WINDOW * mainwin;
    extern int oldcur;


    /*  Switch on signal number  */

    switch ( signum ) {

    case SIGALRM:

        /*  Received from the timer  */

        MoveWorm();
        return;

    case SIGTERM:
    case SIGINT:

        /*  Clean up nicely  */

        delwin(mainwin);
        curs_set(oldcur);
        endwin();
        refresh();
        FreeWorm();
        exit(EXIT_SUCCESS);

    }
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
