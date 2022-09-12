#include <stdio.h>
#include <stdlib.h>

typedef struct arrayList{
    int tamanho_max;
    int tamanho;
    int cursor;
    int* array;
    } arrayList;

arrayList* create_list(int size) {
    arrayList* list = (arrayList*) malloc(sizeof(arrayList));
    list->tamanho_max = size;
    list->tamanho = 0;
    list->cursor = 0;
    list->array = (int*) malloc(size * sizeof(int));
    return list;
    }

void insert(arrayList* list, int n){
    if (list->tamanho >= list->tamanho_max){
        printf("TAMANHO MAXIMO EXCEDIDO");
        return -1;
    }
    int i = list->tamanho;
    while (i>list->cursor){
        list->array[i] = list->array[i-1];
        i--;
    }
    list->array[list->cursor] = n;
    list->tamanho++;
}

int remov(arrayList* list){
    if (list->cursor < 0 || list->cursor >= list->tamanho){
        return -1;
    }
    int n = list->array[list->cursor];
    int i = list->cursor;
    while (i < list->tamanho-1){
        list->array[i] = list->array[i+1];
        i++;
    }
    list->tamanho--;
    return n;
}

void append(arrayList* list, int n){
    if (list->tamanho >= list->tamanho_max){
        printf("\nTAMANHO MAXIMO EXCEDIDO");
        return -1;
    }
    list->array[list->tamanho++] = n;
}

int count(arrayList* list, int n){
    int contador = 0;
    int i = 0;
    while (i < list->tamanho){
        if (list->array[i] == n){
            contador++;
        }
        i++;
    }
    return contador;
}

void clear(arrayList* list){
    list->tamanho = 0;
    free(list->array);
    list->array = (int*) malloc(list->tamanho_max * sizeof(int));
}

void moveToStart(arrayList* list){
    list->cursor=0;
}

void moveToEnd(arrayList* list){
    list->cursor=list->tamanho;
}

void prev(arrayList* list){
    if (list->cursor != 0){
        list->cursor--;
    }
}

void next(arrayList* list){
    if (list->cursor < list->tamanho){
        list->cursor++;
    }
}

int posicao(arrayList* list){
    return list->cursor;
}

int atual(arrayList* list){
    return list->array[list->cursor];
}

int main(){
    


    return 0;
}

