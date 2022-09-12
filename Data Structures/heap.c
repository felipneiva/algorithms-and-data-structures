#include <stdio.h>
#include <stdlib.h>
typedef struct Heap{
    int* array;
    int size;
    } Heap;

Heap* create_heap(int size){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->size = size;
    heap->array = (int*) malloc((size+1) * sizeof(int));
    return heap;
    }

void bottom_up(Heap* heap){
    for (int i=heap->size/2;i>0;i--){
        int k = i;
        int v = heap->array[k];
        int is_heap = 0;
        while (is_heap == 0 && (2*k) <= heap->size){
            int j = 2 *  k;
            if (j < heap->size){
                if (heap->array[j] >= heap->array[j+1]){
                    j++;
                }
            }
            if (v < heap->array[j]){
               is_heap = 1;
            }
            else{
                heap->array[k] = heap->array[j];
                k = j;
            }
        }
        heap->array[k] = v;
    }
}

int remov(Heap* heap){
    int temp = heap->array[1];
    heap->array[1] = heap->array[heap->size];
    heap->array[heap->size] = temp;
    heap->size--;
    bottom_up(heap);
    return temp;
}

void heapsort(Heap* heap, int size){
    for(int i=0;i<size;i++){
        remov(heap);
    }
}

void print(Heap* heap){
    for (int i=1;i<=heap->size;i++){
        printf("%d ", heap->array[i]);
    }
}



int main(){
    

    return 0;
}
