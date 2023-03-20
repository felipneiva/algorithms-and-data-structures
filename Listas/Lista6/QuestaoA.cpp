#include<bits/stdc++.h>

using namespace std;

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
    int nodes;
    int edges;
    int cycle;
    int* distances;
    int* mark;

public:
    Graph(int nodes){
        this->adj = new vector<Edge>[nodes];
        this->nodes = nodes;
        this->mark = new int[nodes];
        this->distances = new int[nodes];
        this->edges = 0;
        this->cycle = 0;
    }

    void setEdge(int v1, int v2, int wt){
        if (v1 != v2){
            Edge newEdge1(v2, wt);
            Edge newEdge2(v1, wt);
            int already = 0;
            int index1;
            int index2;
            for (int i=0;i<adj[v1].size();i++){
                if(adj[v1][i].v == v2){
                    already = 1;
                    index1 = i;
                    break;
                }
            }
            if (already == 1){
                for (int i=0;i<adj[v2].size();i++){
                    if(adj[v2][i].v == v1){
                        index2 = i;
                        break;
                    }
                }
                if (adj[v1][index1].weight > wt){
                    adj[v1][index1].weight = wt;
                    adj[v2][index2].weight = wt;
                }
            }
            if (already == 0){
                adj[v1].push_back(newEdge1);
                adj[v2].push_back(newEdge2);
            }
        }
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

    void Dijkstra(int s){
        priority_queue<Triple> min_heap;
        Triple tripla(s, s, 0);
        for(int i=0;i<nodes;i++){
            setMark(i, 0);
            distances[i] = INT_MAX;
        }

        min_heap.push(tripla);
        distances[s] = 0;
        int v, p;
        for(int i=0;i<nodes;i++){
            do{
                if (min_heap.empty()) return;
                Triple t1 = min_heap.top();
                p = t1.origin; v = t1.destiny;
                min_heap.pop();
            }
            while(getMark(v) == 1);
            setMark(v, 1);
            int w = first(v);
            while(w < nodes){
                if ((getMark(w) == 0) && (distances[w] > distances[v] + weight(v, w))){
                    distances[w] = distances[v] + weight(v, w);
                    Triple t2(v, w, distances[w]);
                    min_heap.push(t2);
                }
                w = next(v, w);
            }
        }
    }

    void printDistances(){
        for(int i=0;i<nodes;i++){
            cout << distances[i] << " ";
        }
    }

    int* getDistances(){
        return distances;
    }





};




int main(){
    int i, j, cases, n, m, S, T, v1, v2, wt, time;
    cin >> cases;
    for(i=0;i<cases;i++){
        cin >> n >> m >> S >> T;
        Graph grafo(n);
        for(j=0;j<m;j++){
            cin >> v1 >> v2 >> wt;
            grafo.setEdge(v1, v2, wt);
        }
        grafo.Dijkstra(S);
        time = grafo.getDistances()[T];
        cout << "Case #" << i+1 << ": ";
        if (time == INT_MAX) cout << "unreachable" << "\n";
        else cout << time << "\n";
    }


    return 0;
}
