#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
}posizione;

#define MAXX 80
#define MAXY 24
#define Q_CHAR 113

int main(int argc, char const *argv[])
{
    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(0);

    posizione oggetto = {MAXX/2, MAXY/2};

    mvaddch(oggetto.y, oggetto.x, '+');
    refresh();

    while (true)
    {
        int c = getch();

        switch (c)
        {
        case KEY_UP:
            if (oggetto.y > 0)
                oggetto.y -= 1;
            break;
        
        case KEY_DOWN:
            if (oggetto.y < MAXY - 1)
                oggetto.y += 1;
            break;
        
        case KEY_LEFT:
            if (oggetto.x > 0)
                oggetto.x -= 1;
            break;

        case KEY_RIGHT:
            if (oggetto.x < MAXX -1)
                oggetto.x += 1;
            break;
        
        case Q_CHAR: 
            endwin();
            exit(0);
        }

        clear();
        mvaddch(oggetto.y, oggetto.x, '+');
        refresh();
    }
    
    return 0;
}

