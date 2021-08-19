extern int rows;
extern int cols;

void initialize_curses_screen();
void SetSignals(void);
void handler(int signum);
void GetTermSize(int * rows, int * cols);

