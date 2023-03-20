#include<bits/stdc++.h>

using namespace std;

class DS{
    int n;
    int* parents;
public:
    DS(int n){
        this->n = n;
        this->parents = new int[n];
        for(int i=0;i<n;i++) parents[i] = i;
    }

    int findd(int curr){
        if (parents[curr] == curr) return curr;
        else{
            parents[curr] = findd(parents[curr]);
            return parents[curr];
        }
    }

    void quick_union(int a, int b){
        int root1 = findd(a); int root2 = findd(b);
        if(root1 != root2) parents[root2] = root1;
    }
};

class Triple{
public:
    int origin;
    int destiny;
    int cost;

    Triple(int v, int w, int c){
        this->origin = v;
        this->destiny = w;
        this->cost = c;
    }


};

bool operator<(const Triple& t1, const Triple& t2)
{
    return t1.cost > t2.cost;
}

class Edge{
public:
    int v;
    int weight;
    Edge(int v, int weight){
        this->v = v;
        this->weight = weight;
    }

};

class Graph{
    vector<Edge>* adj;
    vector<int> heavy_edges;
    int nodes;
    int edges;
    int* mark;

public:
    Graph(int nodes){
        this->adj = new vector<Edge>[nodes];
        this->nodes = nodes;
        this->mark = new int[nodes];
        this->edges = 0;
    }

    void setEdge(int v1, int v2, int wt){
        Edge newEdge1(v2, wt);
        Edge newEdge2(v1, wt);
        heavy_edges.push_back(wt);
        adj[v1].push_back(newEdge1); edges++;
        adj[v2].push_back(newEdge2); edges++;
    }

    void setMark(int v, int is_visited){
        mark[v] = is_visited;
    }

    int getMark(int v){
        return mark[v];
    }

    int first(int v){
        if (adj[v].size() > 0) return adj[v][0].v;
        return nodes;
    }

    int next(int v, int w){
        for (int i=0;i<adj[v].size();i++){
            if (adj[v][i].v == w){
                if (i+1<adj[v].size()) return adj[v][i+1].v;
            }
        }
        return nodes;
    }

    int weight(int v, int w){
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i].v == w) return adj[v][i].weight;
        }
        return 0;
    }

    void print(){
        for(int i=0;i<nodes;i++){
            cout << i << ": ";
            for(int j=0;j<adj[i].size();j++){
                cout << "("<< adj[i][j].v << ", " << adj[i][j].weight << ") ";
            }
            cout << "\n";
        }
    }

    void notHeavyEdge(int wt){
        auto it = std::find(heavy_edges.begin(), heavy_edges.end(), wt);
        if(it != heavy_edges.end()) heavy_edges.erase(it);
    }

    void printHeavy(){
        if(heavy_edges.size() > 0){
            sort(heavy_edges.begin(), heavy_edges.end());
            for(int i=0;i<heavy_edges.size();i++){
                if (i < heavy_edges.size() - 1) cout << heavy_edges[i] << " ";
                else cout << heavy_edges[i];
            }
            cout << "\n";
        }
        else cout << "forest" << "\n";;

    }

    void Kruskal(Graph& G){
        priority_queue<Triple> min_heap;
        for(int i=0;i<nodes;i++){
            int w = first(i);
            while(w < nodes){
                Triple t1(i, w, weight(i, w));
                min_heap.push(t1);
                w = next(i, w);
            }
        }
        DS subset(nodes);
        int numMST = nodes;
        while(numMST > 1 && !min_heap.empty()){
            Triple t2 = min_heap.top();
            min_heap.pop();
            int v = t2.origin; int u = t2.destiny; int wt = t2.cost;
            if (subset.findd(v) != subset.findd(u)){
                subset.quick_union(v, u);
                G.setEdge(v, u, wt);
                notHeavyEdge(wt);
                numMST--;
            }
        }
    }




};




int main(){
    int i, nodes, edges, v1, v2, wt;
    bool loop = true;
    while(loop){
        cin >> nodes >> edges;
        if(!(nodes == 0 && edges == 0)){
            Graph grafo(nodes);
            Graph G(nodes);
            for(i=0;i<edges;i++){
                cin >> v1 >> v2 >> wt;
                grafo.setEdge(v1, v2, wt);
            }
            grafo.Kruskal(G);
            grafo.printHeavy();
        }
        else loop = false;
    }


    return 0;
}
