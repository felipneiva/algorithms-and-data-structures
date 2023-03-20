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
    int vagao;
    int receber_ordem = 1;
    while (scanf("%d", &vagao) && vagao != 0){
        while(receber_ordem == 1){
            Stack* estacao = create_stack();
            int ordem[vagao];
            scanf("%d", &ordem[0]);
            if (ordem[0] == 0){
                break;
            }
            for (int i = 1; i < vagao; i++){
                scanf("%d", &ordem[i]);
            }
            int contador = 1;
            int index = 0;
            while(index <= vagao){
                if(contador == ordem[index]){
                    contador++;
                    index++;
                }
                else if(estacao->tamanho > 0 && estacao->top->element == ordem[index]){
                    pop(estacao);
                    index++;
                }
                else if(contador <= vagao){
                    push(estacao, contador);
                    contador++;
                }
                else{
                    break;
                }
            }
            if (estacao->tamanho == 0){
                printf("Yes\n");
            }
            else{
                if (receber_ordem != 0){
                    printf("No\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

