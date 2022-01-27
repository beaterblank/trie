#include "intstack.c"

int main(){
    stack child = NewStack(26);
    push(child,5);
    push(child,6);
    show(child);
    return 0;
}