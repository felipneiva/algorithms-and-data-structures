#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int element;
    struct Link* next;
    } Link;

typedef struct LinkedList{
    Link* head;
    Link* tail;
    Link* cursor;
    int tamanho;
    } LinkedList;

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

LinkedList* create_list(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = list->tail = list->cursor = create_header(NULL);
    list->tamanho = 0;
    return list;
}

void insert(LinkedList* list, int n){
    list->cursor->next = create_link(n, list->cursor->next);
    if (list->tail == list->cursor){
        list->tail = list->cursor->next;
    }
    list->tamanho++;
}

int remov(LinkedList* list){
    if (list->cursor->next == NULL){
        return NULL;
    }
    else{
        int n = list->cursor->next->element;
        if (list->tail == list->cursor->next){
            list->tail = list->cursor;
        }
        Link* temp = list->cursor->next;
        list->cursor->next = list->cursor->next->next;
        list->tamanho--;
        free(temp);
        return n;
    }
}

int count(LinkedList* list, int n){
    int contador = 0;
    Link* temp = list->head;
    while(temp->next != list->tail->next){
        if (temp->next->element == n){
            contador++;
        }
        temp = temp->next;
    }
    return contador;
    free(temp);
}

void moveToStart(LinkedList* list){
    list->cursor = list->head;
}

void prev(LinkedList* list){
    if (list->cursor == list->head){
        printf("\nNÃO HÁ ANTERIOR");
    }
    else{
        Link* temp = list->head;
        while (temp->next != list->cursor){
            temp = temp->next;
        }
        list->cursor = temp;
        free(temp);
    }
}

void next(LinkedList* list){
    if (list->cursor != list->tail){
        list->cursor = list->cursor->next;
    }
}

int main(){
    


    return 0;
}

