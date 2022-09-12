#include <stdio.h>

int partition();

void quickSort(int* array, int esq, int dir){
    if (esq < dir){
        int s;
        s = partition(array, esq, dir);
        quickSort(array, esq, s - 1);
        quickSort(array, s + 1, dir);

    }
}

int partition(int* array, int esq, int dir){
    int pivo = array[esq];
    int i = esq;
    int j = dir+1;
    do{
        do{
            i = i+1;
        } while(array[i] < pivo && i < dir);
        do{
            j = j-1;
        } while(array[j]>pivo);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } while(i<j);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    temp = array[esq];
    array[esq] = array[j];
    array[j] = temp;
    return j;
}

int main(){
    return 0;
}

