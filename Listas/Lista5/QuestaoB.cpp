#include<bits/stdc++.h>

using namespace std;

class Graph{
    vector<int>* adj;
    stack<int> order;
    int nodes;
    int edges;
    int cycle;
    int* mark;

public:
    Graph(int nodes){
        this->adj = new vector<int>[nodes];
        this->nodes = nodes;
        this->mark = new int[nodes];
        this->edges = 0;
        this->cycle = 0;
    }

    void setEdge(int v1, int v2){
        adj[v1].push_back(v2);
    }

    void setMark(int v, int is_visited){
        mark[v] = is_visited;
    }

    int getMark(int v){
        return mark[v];
    }

    int getCycle(){
        return cycle;
    }

    void printOrder(){
        while(!order.empty()){
            cout << order.top()+1 << " ";
            order.pop();
        }
    }

    void DFS(int v){
        setMark(v, 1);
        sort(adj[v].begin(), adj[v].end());
        for(int i=adj[v].size()-1;i>=0;i--){
            int next = adj[v][i];
            if (getMark(next) == 0) DFS(next);
            else if(getMark(next) == 1){
                cycle = 1;
                return ;
            }
        }
        setMark(v, 2);
        order.push(v);


    }

    void topoSort(){
        for (int v=0;v<nodes;v++){
            setMark(v, 0);
        }
        for (int v=nodes-1;v>=0;v--){
            if (getMark(v) == 0) DFS(v);
        }
    }




};

int main(){
    int nodes, edges, i, v1, v2;
    cin >> nodes >> edges;
    Graph grafo(nodes);
    for(i=0;i<edges;i++){
        cin >> v1 >> v2;
        grafo.setEdge(v1-1, v2-1);
    }
    grafo.topoSort();

    if (grafo.getCycle() == 1) cout << "Sandro fails.";
    else grafo.printOrder();

    return 0;
}
