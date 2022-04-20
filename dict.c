void get(char* str){
    if(strcmp(str,"mohan")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"its ma name lol");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"meeha")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"its your name lol");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"meeter")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"some randome thing");
        move(y,x);
        refresh();
    }
}