#include <ncurses.h>
#include "trie.c"

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}

void prompt(int y)
{
    attron(COLOR_PAIR(1));
    mvprintw(y, 0, "%s", "starts_with $ ");
    attroff(COLOR_PAIR(1));
}

int main()
{

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    trie root = init('/');

    insert("teja", root);
    insert("meeha", root);
    insert("mohan", root);
    insert("meeter", root);

    trie temp = root;

    char ch;

    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
    }

    start_color();

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);


    int Xmax=0,Ymax=0;
    getmaxyx(stdscr,Ymax,Xmax);
    move(Ymax-2,0);
    hline('-',Xmax);
    prompt(Ymax-1);
    int l = 0;
    do
    {
        if (kbhit())
        {
            
            int x = 0, y = 0;
            getsyx(y, x);
            move(y-1,0);
            hline('-',Xmax);
            move(y, x - l);
            clrtobot();
            ch = getch();
            char buff[2];
            buff[0] = ch;
            buff[1] = '\0';

            if(ch>='a' && ch<='z'){
                attron(COLOR_PAIR(2));
                printw("%c", ch);
                attroff(COLOR_PAIR(2));
                if (temp){
                    temp = traverse(buff, temp);
                    char *str;
                    l = 0;
                    if (temp)
                    {
                        str = top(startsWith("", temp, 1));
                        printw("%s", str);
                        l = strlen(str);
                    }
                }else{l=0;}
            }
            attroff(COLOR_PAIR(1));
            if (ch == 10)
            {
                temp = root;
                clear();
                int x = 0, y = 0;
                getsyx(y, x);
                move(y-1,0);
                hline('-',Xmax);
                l=0;
                prompt(Ymax-1);
            }
        }
        refresh();
    } while (ch != '!');

    endwin();
    return 0;
}