
//include statements 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

#include "istack.c"
#include "sstack.c"

const int ASCII = 97;


typedef struct node *trie;
typedef struct node node;

struct node{
    char value;
    trie child[26];
    stack locations;
};


//shows the immediate children of a node
void showChild(trie root){
    printf("children : ");
    for(int i=0;i<root->locations->top+1;i++){
        printf("|-%c-|",root->child[root->locations->arr[i]]->value);
    }
    printf("\n");
}


void debug(trie root){
    printf("value : '%c'\nchildren : %d\n",root->value,root->locations->top+1);
    showChild(root);
}


trie init(char root){
    trie temp = (trie)malloc(sizeof(trie));
    temp->value = root;
    *temp->child = malloc(26*sizeof(node));
    temp->locations = iNewStack(26);
    return temp;
}

bool hasChild(char value,trie t){
    int location = (int)value-ASCII;
    bool has = (t->child[location]!=NULL);
    if(has){
        if(t->child[location]->value==0){return false;}
        return has;
    }
    return false;
}

trie putChild(char value,trie t){
    trie child = init(value);
    int location = (int)value-ASCII;
    t->child[location]=child;
    ipush(t->locations,location);
    return t->child[location];
}

trie getChild(char value,trie t){
    int loction = (int)(value)-ASCII;
    return t->child[loction];
}

void insert(char* string,trie root){
    trie t = root;
    for(int i=0;string[i];i++){
        bool hc = hasChild(string[i],t);
        if(hc){t = getChild(string[i],t);} 
        else{t =  putChild(string[i],t);}
    }
    return;
}

//make a search query if a string exists or 
bool search(char * string,trie root,bool strict){
    trie t = root;
    for(int i=0;string[i];i++){
        if(hasChild(string[i],t)){
            t = getChild(string[i],t);
        }else{return false;}
    }
    if(strict){return isEmpty(t->locations);}
    else return true;
}



//getting all string from the tree using dfs
void getStrings(sstack strings,int n,trie root,char* word){
    int nchild = root->locations->top+1;
    if(nchild==0){
        push(strings,word);
        return;
    }
    if(strings->stackSize>n){
        return;
    }
    for(int i=0;i<nchild;i++){
        int k = root->locations->arr[i];
        char *newWord = append(word,root->child[k]->value);
        getStrings(strings,n,root->child[k],newWord);
    }
}
trie traverse(char* string,trie root){
    trie tmp = root;
    for(int i=0;string[i];i++){
        if(hasChild(string[i],tmp)){
            tmp = getChild(string[i],tmp);
        }else{return NULL;}
    }
    return tmp;
}

sstack startsWith(char* string,trie root,int n){
    sstack strings = newStack();
    getStrings(strings,n,root,string);
    return strings;
}