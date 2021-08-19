#include <ncurses.h>

int x = 0;
int y = 0;

void setplace(int _x, int _y)
{
	x = _x;
	y = _y;
}

void dotplace()
{
	move(y, x);
	addch('.');
}

void spaceplace()
{
	move(y, x);
	addch(' ');
}
