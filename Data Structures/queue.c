#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int element;
    struct Link* next;
    } Link;

typedef struct Queue{
    Link* front;
    Link* rear;
    int tamanho;
    } Queue;

Link* create_link(int n, Link* next){
    Link* node = (Link*) malloc(sizeof(Link));
    node->element = n;
    node->next = next;
    return node;
}

Link* create_header(Link* next){
    Link* node = (Link*) malloc(sizeof(Link));
    node->next = next;
    return node;
}

Queue* create_queue(){
    Queue* fila = (Queue*) malloc(sizeof(Queue));
    fila->front = fila->rear = create_header(NULL);
    fila->tamanho = 0;
    return fila;
}

void enqueue(Queue* fila, int n){
    fila->rear->next = create_link(n, NULL);
    fila->rear = fila->rear->next;
    fila->tamanho++;
}

int dequeue(Queue* fila){
    if (fila->tamanho == 0){
        return NULL;
    }
    else{
        int n = fila->front->next->element;
        Link* temp = fila->front->next;
        fila->front->next = fila->front->next->next;
        if (fila->front->next == NULL){
            fila->rear = fila->front;
        }
        fila->tamanho--;
        return n;
        free(temp);
    }
}

int main(){
    

    return 0;
}