#include <stdio.h>

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

int num_pares(int* array, int dif, int qtd){
    int i, j, pares;
    i = 0;
    j = 1;
    pares = 0;
    while(i < qtd && j < qtd){
        if (array[j] - array[i] == dif){
            pares++;
            i++;
            j++;
        }
        else if (array[j] - array[i] < dif){
            j++;
        }
        else if (array[j] - array[i] > dif){
            i++;
        }
    }
    return pares;
}


void main(){
    int qtd, dif;
    scanf("%d %d", &qtd, &dif);
    int array[qtd];
    for (int i=0;i<qtd;i++){
        scanf("%d", &array[i]);
    }
    quickSort(array, 0, qtd-1);
    if (qtd>1){
        printf("\n%d", num_pares(array, dif, qtd));
    }
    else{
        printf("0");
    }

}

void quickSort(int* array, int esq, int dir){
    if (esq < dir){
        int pivo;
        pivo = partition(array, esq, dir);
        quickSort(array, esq, pivo - 1);
        quickSort(array, pivo + 1, dir);

    }
}



