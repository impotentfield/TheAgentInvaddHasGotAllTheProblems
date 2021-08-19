#include "screen.h"
#include "dotplace.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>



int main()
{

	int k;
    
	SetSignals();
	initialize_curses_screen();

	
	setplace(cols/2, rows/2);

	do {
	 k = getch();
	 if ( k == KEY_LEFT ) { x--; }
 	 if ( k == KEY_RIGHT ) { x++; }
	 if ( k == KEY_UP ) { y--; }
 	 if ( k == KEY_DOWN ) { y++; }
	
	dotplace();
 	} while (1);

 return 0;
}
