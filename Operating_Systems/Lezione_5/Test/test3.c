#include <ncurses.h>
#include <unistd.h>

#define MAXX 80
#define MAXY 24
#define DELAY 1 //secondo

typedef struct 
{
    int x;
    int y;
}posizione;

int main(int argc, char const *argv[])
{
    posizione oggetto = {MAXX/2, MAXY/2};

    initscr();
    noecho();
    keypad(stdscr, true);
    curs_set(false);

    while (true)
    {
        clear();
        
        mvprintw(oggetto.y, oggetto.x, "+");
        
        refresh();

        sleep(DELAY);
        
        oggetto.x++;
        oggetto.y++;

        if (oggetto.y > MAXY || oggetto.x > MAXX) break;
    }

    endwin();
    
    return 0;
}
