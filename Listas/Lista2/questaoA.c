#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    char element;
    struct Link* next;
    } Link;

typedef struct LinkedList{
    Link* head;
    Link* tail;
    Link* cursor;
    int tamanho;
    } LinkedList;

Link* create_link(char n, Link* next){
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

void insert(LinkedList* list, char n){
    list->cursor->next = create_link(n, list->cursor->next);
    if (list->tail == list->cursor){
        list->tail = list->cursor->next;
    }
    list->tamanho++;
}

void print(LinkedList* list){
    Link* temp = list->head;
    while(temp->next != NULL){
        printf("%c", temp->next->element);
        temp = temp->next;
    }
    free(temp);
}

void moveToStart(LinkedList* list){
    list->cursor = list->head;
}

void moveToEnd(LinkedList* list){
    list->cursor = list->tail;
}

void next(LinkedList* list){
    if (list->cursor != list->tail){
        list->cursor = list->cursor->next;
    }
}


int main(){
    char letras[100000];
    while (scanf("%s", letras) != EOF){
        LinkedList* frase = create_list();
        for (int i = 0; letras[i] != '\0'; i++){
            if (letras[i]  == '['){
                moveToStart(frase);
            }
            else if (letras[i]  == ']'){
                moveToEnd(frase);
            }
            else if (letras[i]  != '[' && letras[i]  != ']'){
                insert(frase, letras[i]);
                next(frase);
            }
        }
        print(frase);
    }

    return 0;
}
