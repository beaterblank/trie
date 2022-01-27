#include "trie.c"

int main(){
    trie root = init('/');
    insert("teja",4,root);
    insert("meeha",5,root);
    debug(root);
    insert("mohan",5,root);
    printf("%d\n",search("mohan",5,root));
    return 0;
}

