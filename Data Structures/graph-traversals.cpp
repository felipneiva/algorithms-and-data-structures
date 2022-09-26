#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct Graph{
    int** matrix;
    int* mark;
    int vertices;
    int edges;
    } Graph;

Graph* create_graph(int nodes){
    Graph* grafo = (Graph*) malloc(sizeof(Graph));
    grafo->edges = 0;
    grafo->vertices = nodes;
    grafo->mark = (int*) malloc(nodes * sizeof(int));
    grafo->matrix = (int**) malloc(nodes * sizeof(int*));
    for (int i=0;i<nodes;i++){
        grafo->matrix[i] = (int*) malloc(nodes * sizeof(int));
        for (int j=0;j<nodes;j++){
            grafo->matrix[i][j] = 0;
        }
    }


    return grafo;
}

int first(Graph* grafo, int vertice){
    for (int i=0;i<grafo->vertices;i++){
        if (grafo->matrix[vertice][i] != 0 ){
            return i;
        }
    }
    return grafo->vertices;
}

int next(Graph* grafo, int vertice, int w){
    for (int i=w+1;i<grafo->vertices;i++){
        if (grafo->matrix[vertice][i] != 0 ){
            return i;
        }
    }
    return grafo->vertices;
}

void setEdge(Graph* grafo, int i, int j, int wt){
    if (wt != 0){
        if (grafo->matrix[i][j] == 0){
            grafo->matrix[i][j] = wt;
            grafo->edges++;
        }
    }
}

void delEdge(Graph* grafo, int i, int j){
    if (grafo->matrix[i][j] != 0){
        grafo->matrix[i][j] = 0;
        grafo->edges--;
    }
}

void setMark(Graph* grafo, int v, int is_visited){
    grafo->mark[v] = is_visited;
}

int getMark(Graph* grafo, int v){
    return grafo->mark[v];
}

void printG(Graph* grafo){
    for (int i=0;i<grafo->vertices;i++){
        for (int j=0;j<grafo->vertices;j++){
            printf("%d ", grafo->matrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(Graph* grafo, int v, stack<int> &pilha){
    setMark(grafo, v, 1);
    int w = first(grafo, v);
    while (w < grafo->vertices){
        if (getMark(grafo, w) == 0){
            DFS(grafo, w, pilha);
            }
        w = next(grafo, v, w);
    }
    pilha.push(v);
}

void BFS(Graph* grafo, int start){
    queue<int> fila;
    fila.push(start);
    setMark(grafo, start, 1);
    while (!fila.empty()){
        int v = fila.front();
        fila.pop();
        //pré visita //
        int w = first(grafo, v);
        while (w < grafo->vertices){
            if (getMark(grafo, w) == 0){
                setMark(grafo, w, 1);
                fila.push(w);
            }
            w = next(grafo, v, w);
        }
        //pós visita//
    }
}


void topoSort(Graph* grafo, stack<int> &pilha){
    for (int v=0;v<grafo->vertices;v++){
        setMark(grafo, v, 0);
    }
    for (int v=0;v<grafo->vertices;v++){
        if (getMark(grafo, v) == 0){
            DFS(grafo, v, pilha);
        }
    }
}

void traverseBFS(Graph* grafo){
    for (int v=0;v<grafo->vertices;v++){
        setMark(grafo, v, 0);
    }
    for (int v=0;v<grafo->vertices;v++){
        if (getMark(grafo, v) == 0){
            BFS(grafo, v);
        }
    }
}

int main()
{
    


    return 0;
}
