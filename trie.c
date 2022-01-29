#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "intstack.c"

const int ASCII = 97;


typedef struct node *trie;
typedef struct node node;

struct node{
    char value;
    int count;
    trie child[26];
    stack locations;
};

void debug(trie root){
    printf("value : '%c'\nchildren : %d\n",root->value,root->count);
}

trie init(char root){
    trie temp = (trie)malloc(sizeof(trie));
    temp->value = root;
    temp->count = 0;
    *temp->child = malloc(26*sizeof(node));
    temp->locations = NewStack(26);
    return temp;
}

bool hasChild(char value,trie t){
    //printf("searching for %c as %d ",value,value);
    int location = (int)value-ASCII;
    //printf("at %d\n",location);
    bool has = (t->child[location]!=NULL);
    if(has){
        if(t->child[location]->value==0){return false;}
        return has;
    }
    return false;
}

trie putChild(char value,trie t){
    //printf("putting %c to %c\n",value,t->value);
    trie child = init(value);
    int location = (int)value-ASCII;
    t->child[location]=child;
    t->count++;
    push(t->locations,location);
    return t->child[location];
}

trie getChild(char value,trie t){
    //printf("getting %c from %c ",value,t->value);
    int loction = (int)(value)-ASCII;
    //printf("got %d\n",t->child[loction]->value);
    return t->child[loction];
}


void insert(char* string,trie root){
    trie t = root;
    //printf("\ninserting %s\n",string);
    for(int i=0;string[i];i++){
        bool hc = hasChild(string[i],t);
        //printf("for %c from %c ,hasChild returned %d\n",string[i],t->value,hc);
        if(hc){t = getChild(string[i],t);} 
        else{t =  putChild(string[i],t);}
    }
    return;
}


bool search(char * string,trie root){
    trie t = root;
    for(int i=0;string[i];i++){
        if(hasChild(string[i],t)){
            t = getChild(string[i],t);
        }else{return false;}
    }
    //printf("%c-%d\n",t->value,t->count);
    return t->count==0;
}

char* starts_with(){

}