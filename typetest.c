#include <ncurses.h>

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}


void prompt(){
    attron (COLOR_PAIR (1));
	mvprintw (0,0,"%s", "SEARCH $ ");
	attroff (COLOR_PAIR (1));
}



int main(void)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    char ch;

    if(has_colors() == FALSE)
	{
        endwin();
		printf("Your terminal does not support color\n");
	}

	start_color();
    int  at = 0;
    init_pair(1, COLOR_RED, COLOR_BLACK);
    prompt();
    do{
        if (kbhit()) {
            ch = getch();
            printw("%c", ch);
            at++;
            if(ch==10){
                clear();
                at=0;
                prompt();
            }
        } 
        refresh();
    }while(ch!='!');
    endwin();
    return 0;
}
