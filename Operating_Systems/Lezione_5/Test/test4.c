#include <unistd.h>
#include <ncurses.h>

#define DELAY 1 //secondo
#define KEYCODE_Q 113

int main(int argc, char const *argv[])
{
    int maxy = 0, maxx = 0, newx = 0, newy = 0, direzionex = 1, direzioney = 1;

    initscr();
    noecho();
    curs_set(false);
    getmaxyx(stdscr, maxy, maxx);

    int x = maxx/2, y = maxy/2;

    while (true)
    {
        clear();

        mvprintw(y, x, "o");

        refresh();

        usleep(40000);

        newx = x + direzionex;
        newy = y + direzioney;

        if (newx >= maxx || newx < 0)
            direzionex *= -1;
        else
            x += direzionex;

        if (newy >= maxy || newy < 0)
            direzioney *= -1;
        else
            y += direzioney;
       
        timeout(1);

        if (getch() == KEYCODE_Q) break;
    }
    
    endwin();

    return 0;
}
