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

void quickSort(int* array, int esq, int dir){
    if (esq < dir){
        int pivo;
        pivo = partition(array, esq, dir);
        quickSort(array, esq, pivo - 1);
        quickSort(array, pivo + 1, dir);

    }
}


int main(){
    long long int preco = 0;
    int barras;
    scanf("%d", &barras);
    int custo_barras[barras];
    for (int i=0;i<barras;i++){
        scanf("%d", &custo_barras[i]);
        preco = preco + custo_barras[i];
    }
    int cupons;
    scanf("%d", &cupons);
    int barras_cupom[cupons];
    for (int i=0;i<cupons;i++){
        scanf("%d", &barras_cupom[i]);
    }
    quickSort(custo_barras, 0, barras-1);
    for (int i=0; i<cupons; i++){
        long long int preco_novo = preco;
        printf("%lld\n", preco_novo - custo_barras[barras-barras_cupom[i]]);
    }
    return 0;
}


