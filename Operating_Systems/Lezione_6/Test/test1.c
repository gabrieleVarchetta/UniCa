#include <unistd.h>
#include <ncurses.h>

typedef struct
{
    int x;
    int y;
}posizione;

int main(int argc, char const *argv[])
{
    int maxx = 0, maxy = 0;
    int newx1 = 0, newy1 = 0;
    int newx2 = 0, newy2 = 0;
    int direzionex1 = 1, direzioney1 = 1;
    int direzionex2 = 1, direzioney2 = 1;

    initscr();
    noecho();
    curs_set(false);
    getmaxyx(stdscr, maxy, maxx);

    posizione palla1, palla2;

    palla1.x = 0;
    palla1.y = maxy;
    palla2.x = maxx - 1;
    palla2.y = maxy;

    while (true)
    {
        clear();

        mvprintw(palla1.y, palla1.x, "O");
        mvprintw(palla2.y, palla2.x, "X");

        refresh();

        usleep(30000);

        newx1 = palla1.x + direzionex1;
        newy1 = palla1.y + direzioney1;
        newx2 = palla2.x + direzionex2;
        newy2 = palla2.y + direzioney2;

        if (newx1 >= maxx || newx1 < 0)
            direzionex1 *= -1;
        else
            palla1.x += direzionex1;
        if (newy1 >= maxy || newy1 < 0)
            direzioney1 *= -1;
        else
            palla1.y += direzioney1;
        
        if (newx2 >= maxx || newx2 < 0)
            direzionex2 *= -1;
        else
            palla2.x += direzionex2;
        if (newy2 >= maxy || newy2 < 0)
            direzioney2 *= -1;
        else
            palla2.y += direzioney2;
       
       if ((palla1.x == palla2.x) && (palla1.y == palla2.y))
       {
           flash();
           break;
       }
       
       timeout(1);

       if (getch() == 113)
            break;
    }
    
    endwin();
    
    return 0;
}

