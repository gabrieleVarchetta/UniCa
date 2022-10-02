#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int maxx = 0, maxy = 0, x = 0, y = 0;

    initscr();
    noecho();
    curs_set(false);
    srand(time(NULL));

    getmaxyx(stdscr, maxy, maxx);

    while (true)
    {
        clear();

        x = rand() % maxx;
        y = rand() % maxy;

        mvprintw(y, x, "X");

        refresh();
        usleep(200000);

        timeout(1);

        if (getch() == 113)
            break; 
    }
    
    endwin();

    return 0;
}
