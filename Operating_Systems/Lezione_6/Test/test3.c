#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

char sprite1[2][7] = { "<-|->"," YOU"};
char sprite2[2][7] = { " BOSS", "<---->" };
char sprite3[2][10] = { "SGHERRO", " <-_->" };

int main()
{
        int maxy = 0, maxx = 0, newx = 0, direzionex = 1, direzioney = 1;
        initscr();
        start_color();
        init_pair(1, COLOR_RED, COLOR_YELLOW);
        init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_CYAN, COLOR_BLACK);

        noecho();
        curs_set(false);

        getmaxyx(stdscr, maxy, maxx); //Ottiene dimensione schermo
        int dimsprite = sizeof(sprite1); //Dimensione Sprite
        int x = maxx - (dimsprite/2), y=(maxy/2);

        while(true)
        {
                clear();

                x+=(1 * direzionex) * 0;
                y+=(1 * direzioney);

                attron(COLOR_PAIR(1));
                attron(A_BOLD);
                printw("IL GIOCO PIU' BELLO DEL MONDO\n");
                attroff(COLOR_PAIR(1));
                attroff(A_BOLD);

                attron(COLOR_PAIR(2));
                mvprintw(y, x-50, sprite1[0]);
                mvprintw(y+1, x-50, sprite1[1]);
                attroff(COLOR_PAIR(2));

                attron(COLOR_PAIR(3));
                mvprintw(y, x, sprite2[0]);
                mvprintw(y+1, x, sprite2[1]);
                attroff(COLOR_PAIR(3));

                attron(COLOR_PAIR(4));
                mvprintw(y+3, x, sprite3[0]);
                mvprintw(y+4, x, sprite3[1]);
                attroff(COLOR_PAIR(4));

                if(x>=(maxx-dimsprite) || x<=0)
                        direzionex *= -1;
                if(y>=maxy || y+5>=maxy || y<=2)
                        direzioney *= -1;

                refresh();
                usleep(100000);
                timeout(1);

                if(getch() == 113)
                        break;
        }

        endwin();
}
