#include "trie.c"
int main(){
    trie root = init('/');
    insert("teja",root);
    insert("meeha",root);
    insert("mohan",root);
    insert("meeter",root);
    sstack strings = newStack();
    trie tmp = traverse("mee",root);
    strings = startsWith("mee",tmp,3);
    printf("%s\n",top(strings));
    pop(strings);
    printf("%s\n",top(strings));
    return 0;
}

