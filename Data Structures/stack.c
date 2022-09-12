#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int element;
    struct Link* next;
    } Link;
typedef struct Stack{
    Link* top;
    int tamanho;
    } Stack;
Link* create_link(int n, Link* next){
    Link* node = (Link*) malloc(sizeof(Link));
    node->element = n;
    node->next = next;
    return node;
}
Stack* create_stack(){
    Stack* pilha = (Stack*) malloc(sizeof(Stack));
    pilha->top = NULL;
    pilha->tamanho = 0;
    return pilha;
}
void push(Stack* pilha, int n){
    pilha->top = create_link(n, pilha->top);
    pilha->tamanho++;
}
int pop(Stack* pilha){
    int n;
    if (pilha->top == NULL){
        return NULL;
    }
    else{
        n = pilha->top->element;
        Link* temp = pilha->top;
        pilha->top = pilha->top->next;
        pilha->tamanho--;
        free(temp);
        return n;
    }
}

int main(){
    

    return 0;
}

