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

mvprintw(rows - 2, 0, "Type 's' to skip a dot");

	do {
	 k = getch();
	 if ( k == KEY_LEFT ) { x--; }
 	 if ( k == KEY_RIGHT ) { x++; }
	 if ( k == KEY_UP ) { y--; }
 	 if ( k == KEY_DOWN ) { y++; }
	 if ( k == 's' ) { spaceplace(); } else {
	dotplace();
	}
 	} while (1);

 return 0;
}
