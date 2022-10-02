#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

char sprite1[5]={"<-|->"};

int main() {
    int maxy =0, maxx=0;
	int newx=0, newy=0;
	int direzionex=1, direzioney=1;
    int x, y;

	initscr();
	noecho();
	curs_set(false);
	getmaxyx(stdscr,maxy,maxx); /* Ottiene dimensioni schermo */
    int dimsprite = sizeof(sprite1);

    x = maxx/2 - dimsprite/2;
    y = maxy/2;

    while(true) {
        clear();

        x += (1 * direzionex);
        y += (1 * direzioney);

        mvprintw(y,x,sprite1);

        if(x >= (maxx-dimsprite) || x <= 0)
            direzionex *= -1;

        if(y >= maxy || y<=0)
            direzioney *= -1;

        refresh();
        usleep(20000);
        timeout(1);
        if(getch() == 113)
        break;
    }
    endwin();
}