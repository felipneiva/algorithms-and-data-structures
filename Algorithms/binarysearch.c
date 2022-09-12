#include <stdio.h>
int binarySearch(int* array, int esq, int dir, int chave){
    if (dir >= esq){
        int meio = (esq + dir) / 2;
        if (chave == array[meio]){
            return meio;
        }
        else if (chave < array[meio]){
            return binarySearch(array, esq, meio-1, chave);
        }
        else{
            return binarySearch(array, meio+1, dir, chave);
        }
    }
    else{
        return -1;
    }
}

int main(){
  
    return 0;
}

