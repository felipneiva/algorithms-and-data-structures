#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dictionary{
    int m;
    int count;
    char** hash;
    } Dictionary;

Dictionary* create_dict(int tamanho){
    Dictionary* dict = (Dictionary*) malloc(sizeof(Dictionary));
    dict->m = tamanho;
    dict->count = 0;
    dict->hash = (char**) malloc(tamanho * sizeof(char*));
    for (int i=0;i<tamanho;i++){
        dict->hash[i] = NULL;
    }
    return dict;
}

int h(char* string){
    int soma = 0;
    for (int i = 0; string[i] != '\0'; i++){
        soma += (string[i] * (i+1));
    }
    return 19 * soma;
}

int hash(char* string){
    return abs(h(string)) % 101;
}

int colision(char* string, int j){
    int index = abs(hash(string) + (j * j) + (23 * j)) % 101;
    return index;
}

char* find(Dictionary* dict, char* string){
    int index = hash(string);
    if ((dict->hash[index] != NULL) && (strcmp(dict->hash[index], string) == 0)){
        return dict->hash[index];
    }
    for (int j=1;j<20;j++){
        int index = colision(string, j);
        if ((dict->hash[index] != NULL) && (strcmp(dict->hash[index], string) == 0)){
            return dict->hash[index];
        }
    }
    return NULL;
}

void insert(Dictionary* dict, char* string){
    if ((string != NULL) && (find(dict, string) == NULL) && (dict->count < dict->m)){
        int index = hash(string);
        if (dict->hash[index] == NULL){
            dict->hash[index] = string;
            dict->count++;
        }
        else{
            for (int j=1;j<20;j++){
                int index = colision(string, j);
                if (dict->hash[index] == NULL){
                    dict->hash[index] = string;
                    dict->count++;
                    break;
                }
            }
        }
    }
}

char* delet (Dictionary* dict, char* string){
    int index = hash(string);
    if ((dict->hash[index] != NULL) && (find(dict, string) != NULL) && (strcmp(dict->hash[index], string) == 0)){
        char* temp = dict->hash[index];
        dict->hash[index] = NULL;
        dict->count--;
        return temp;
    }
    for (int j=1;j<20;j++){
        int index = colision(string, j);
        if ((dict->hash[index] != NULL) && (find(dict, string) != NULL) && (strcmp(dict->hash[index], string) == 0)){
            char* temp = dict->hash[index];
            dict->hash[index] = NULL;
            dict->count--;
            return temp;
        }
    }
    return NULL;
}

void printd(Dictionary* dict){
    for (int i = 0; i< dict->m; i++){
        if (dict->hash[i] != NULL){
            printf("%d:%s\n", i, dict->hash[i]);
        }
    }
}

int main(){
    


    return 0;
}
