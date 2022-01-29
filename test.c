#include "trie.c"
#include <ncurses.h>

int main(){
    trie root = init('/');
    insert("teja",root);
    insert("meeha",root);
    debug(root);
    insert("mohan",root);
    printf("%d\n",search("mohan",root));
    return 0;
}

