#include <ncurses.h>

int main(int argc, char const *argv[])
{
    int keycode;

    initscr();
    curs_set(0);
    noecho();

    mvprintw(2, 1, "Premi un cazzo di tasto (q per uscire coglione)");
    refresh();

    while (true)
    {
        keycode = getch();
        deleteln();
        mvprintw(2, 1, "Codice merdoso del cazzo di tasto premuto (q per uscire coglione): %d", keycode);
        refresh();

        if (keycode == 113)
            break;
    }

    endwin();

    return 0;
}
