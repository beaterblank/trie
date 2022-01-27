#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stkc* stackc; 

struct stkc{
	char *arr;
	int top;
	int cap;
};

stackc cNewStackc(int cap){
	stackc temp =  (stackc)malloc(sizeof(stackc*));
	temp->top   =  -1;
	temp->cap   =  cap;
	temp->arr   = 	(char*)malloc(cap*sizeof(char));
	return temp;
}

bool isFullc(stackc s){
	return s->top == s->cap-1;
}

bool isEmptyc(stackc s){
	return s->top == -1;
}

void pushc(stackc s,char p){
	if(isFullc(s)){printf("stackc overflow\n");return;}
	s->arr[++s->top]=p;
}

char popc(stackc s){
	if(isEmptyc(s)){printf("stackc underflow\n");return 0;}
	return s->arr[s->top--];
}

char peekc(stackc s){
    if(isEmptyc(s)){return -1;}
    return s->arr[s->top];
}

void showc(stackc s){
	if(s->top==-1){printf("No element in stackc\n");return;}
	printf("arr = ");
	for(int i=0;i<s->top+1;i++){
		printf("%c ",s->arr[i]);
	}
	printf("\n");
}