#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stk* stack; 

struct stk{
	int *arr;
	int top;
	int cap;
};

stack NewStack(int cap){
	stack temp =  (stack)malloc(sizeof(stack*));
	temp->top   =  -1;
	temp->cap   =  cap;
	temp->arr   = 	(int*)malloc(cap*sizeof(int));
	return temp;
}

bool isFull(stack s){
	return s->top == s->cap-1;
}

bool isEmpty(stack s){
	return s->top == -1;
}

void push(stack s,int p){
	if(isFull(s)){printf("stack overflow\n");return;}
	s->arr[++s->top]=p;
}

int pop(stack s){
	if(isEmpty(s)){printf("stack underflow\n");return 0;}
	return s->arr[s->top--];
}

int peek(stack s){
    if(isEmpty(s)){return -1;}
    return s->arr[s->top];
}

void show(stack s){
	if(s->top==-1){printf("No element in stack\n");return;}
	printf("arr = ");
	for(int i=0;i<s->top+1;i++){
		printf("%d ",s->arr[i]);
	}
	printf("\n");
}