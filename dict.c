void get(char* str){
    if(strcmp(str,"same")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"adjective\n1. identical with what is about to be or has just been mentioned:\neg: This street is the same one we were on yesterday.\n2. being one or identical though having different names, aspects, etc.:\neg: These are the same rules though differently worded.\n3. agreeing in kind, amount, etc.; corresponding:\neg: two boxes of the same dimensions.");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"sameeha")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"its your name");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"samaritan")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"some randome thing");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"samaria")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"noun\n1. a district in ancient Palestine: later part of the Roman province of Syria; taken by Jordan 1948; occupied by Israel 1967.\n2. the northern kingdom of the ancient Hebrews; Israel.\n3. the ancient capital of this kingdom.");
        move(y,x);
        refresh();
    }
    if(strcmp(str,"samurai")==0){
        refresh();
        int x = 0, y = 0;
        getsyx(y, x);
        mvprintw(5,1,"hello");
        move(y,x);
        refresh();
    }

}