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


int printStack(sstack theStack){
  struct stack_entry *temp = theStack->head;
  int l = 0;
  while (temp)
  {
    printw("%s",temp->data);
    l+=strlen(temp->data);
    temp = temp->next;
    printw(" || ");
    l+=4;
  }
  return l;
}


#include "dict.c"


int main()
{

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    trie root = init('/');
    trie music = init('/');

    insert("same", root);
    insert("sameeha", root);
    insert("samaritan", root);
    insert("samaria", root);
    insert("samurai", root);


    insert("abc",music);
    insert("dbdfac",music);
    insert("edfasd",music);
    insert("bbc",music);
    insert("cbdfac",music);
    insert("fdfasd",music);

    trie temp = root;
    trie misc = music;
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
    move(1,0);
    hline('-',Xmax);
    prompt(2);
    int l = 0;
    char inp[100];
    int mode =0;
    do{
        if (kbhit()){
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

            if(ch == '1'){mode=1;ch=10;}
            if(ch == '0'){mode=0;ch=10;}

            if(ch>='a' && ch<='z'){
                strcpy(inp,strncat(inp,&ch,1));
                attron(COLOR_PAIR(2));
                printw("%c", ch);
                attroff(COLOR_PAIR(2));
                if(mode==0 && temp){
                    temp = traverse(buff, temp);
                    l = 0;
                    if (temp)
                    {
                        sstack words = startsWith("", temp, 5);
                        l = printStack(words);
                        get(inp);
                    }
                }else if(misc){
                    misc = traverse(buff,misc);
                    l=0;
                    if (misc)
                    {
                        sstack words = startsWith("", misc, 5);
                        l = printStack(words);
                        get(inp);
                    }
                }
                else{l=0;}
            }
            attroff(COLOR_PAIR(1));
            if (ch == 10)
            {
                strcpy(inp,"");
                temp = root;
                misc = music;
                clear();
                int x = 0, y = 0;
                getsyx(y, x);
                move(y-1,0);
                hline('-',Xmax);
                l=0;
                prompt(2);
            }

        }
        refresh();
    } while (ch != '!');
    endwin();
    return 0;
}
