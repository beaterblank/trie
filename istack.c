typedef struct stk* stack; 

struct stk{
	int *arr;
	int top;
	int cap;
};

stack iNewStack(int cap){
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

void ipush(stack s,int p){
	if(isFull(s)){printf("stack overflow\n");return;}
	s->arr[++s->top]=p;
}

int ipop(stack s){
	int nul;
	if(isEmpty(s)){printf("stack underflow\n");return nul;}
	return s->arr[s->top--];
}

int itop(stack s){
	int nul;
    if(isEmpty(s)){return nul;}
    return s->arr[s->top];
}
