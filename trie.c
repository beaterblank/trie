//include statements 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//include coustom code
#include "sstack.c"

//global constant variables
const int ASCII = 97;

//typedef
typedef struct node *trie;
typedef struct node node;


//struct implementation
struct node{
    char value;
    trie* child;
    int locations[26];
    int top;
};
//init a trie with root charecter
trie init(char root){
    trie temp = (trie)malloc(sizeof(trie));
    temp->value = root;
    temp->child = calloc(26,sizeof(trie));
    temp->top = -1;
    return temp;
}
//debug a node 
void debug(trie root){
    printf("value : '%c'\n",root->value);
    printf("children : ");
    for(int i=0;i<root->top+1;i++){
        printf("|-%c-|",root->child[root->locations[i]]->value);
    }
    printf("\n");
}

//check if trie has a child with given value
bool hasChild(char value,trie t){
    return t->child[(int)value-ASCII]!=NULL;
}


//put a child to trie node
trie putChild(char value,trie t){
    trie child = init(value);
    int location = (int)((int)value-ASCII);
    t->child[location]=child;
    t->locations[++t->top]=(int)location;
    return t->child[location];
}


//get child with char value
trie getChild(char value,trie t){
    int loction = (int)(value)-ASCII;
    return t->child[loction];
}


//insert into trie
void insert(char* string,trie root){
    trie t = root;
    int len =strlen(string); 
    for(int i=0;i<len;i++){
        bool hc = hasChild(string[i],t);
        if(hc){t = getChild(string[i],t);} 
        else{t =  putChild(string[i],t);}
    }
}

//make a search query if a string exists or not with strict enabled
//with strict disabled it will check for prefix
bool search(char * string,trie root,bool strict){
    trie t = root;
    for(int i=0;string[i];i++){
        if(hasChild(string[i],t)){
            t = getChild(string[i],t);
        }else{return false;}
    }
    if(strict){return t->top==-1;}
    else return true;
}



// //getting all string from the tree using dfs
void getStrings(sstack strings,int n,trie root,char* word){
    int nchild = root->top+1;
    if(nchild==0){
        push(strings,word);
        return;
    }
    if(strings->stackSize>n){
        return;
    }
    for(int i=0;i<nchild;i++){
        int k = root->locations[i];
        char *newWord = append(word,root->child[k]->value);
        getStrings(strings,n,root->child[k],newWord);
    }
}


//to traverse the trie and reuturn the trie
trie traverse(char* string,trie root){
    trie tmp = root;
    for(int i=0;string[i];i++){
        if(hasChild(string[i],tmp)){
            tmp = getChild(string[i],tmp);
        }else{return NULL;}
    }
    return tmp;
}

//get all strings but with return type
sstack startsWith(char* string,trie root,int n){
    sstack strings = newStack();
    getStrings(strings,n,root,string);
    return strings;
}
