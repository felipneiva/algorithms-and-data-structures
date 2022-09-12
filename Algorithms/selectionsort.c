#include <stdio.h>
#include <stdlib.h>

void selectionSort(int array[], int tamanho)
{
    int i, j, menor;
    for (i=0;i<tamanho-1;i++){
        menor = i;
        for (j=i+1;j<tamanho;j++){
            if (array[j]<array[menor]){
                menor = j;
            }
        }
        int salvar = array[i];
        array[i] = array[menor];
        array[menor] = salvar;
    }
}


int main(){
    
    return 0;
}

