
// rand()
int x = 0;
int y = 0;

void setplace(int _x, int _y)
{
	x = _x;
	y = _y;
}

void dotplace(void)
{
	move(y, x);
	addch('.');
}

