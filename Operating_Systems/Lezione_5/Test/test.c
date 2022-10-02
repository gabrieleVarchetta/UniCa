#include <ncurses.h>

int main(int argc, char const *argv[])
{
    WINDOW *w1;

    initscr();
    curs_set(0);
    noecho();

    w1 = newwin(10, 20, 1, 2); // Crea una finestra in posizione y = 1 e x = 2, grande 10 linee
    box(w1, ACS_VLINE, ACS_HLINE); // Crea un bordo alla finestra con i caratteri delle macro ACS_VLINE e ACS_HLINE
    mvwprintw(w1, 5, 3, "Premi un tasto"); // Scrive a partire dalla riga

    wgetch(w1);
    delwin(w1);

    refresh();
    endwin();

    return 0;
}
