#include<bits/stdc++.h>

using namespace std;

class Person{
    string name;
    int index;
    int ranking;

public:
    Person(string name, int index){
        this->name = name;
        this->index = index;
        this->ranking = 100000;
    }

     bool operator < (const Person& person) const{
        if (ranking != person.ranking) return (ranking < person.ranking);
        else return (name < person.name);
    }


    string getName(){
        return name;
    }

    int getIndex(){
        return index;
    }

    void setRank(int dist){
        ranking = dist;
    }

    int getRank(){
        return ranking;
    }

};

class Members{
    vector<Person> names;

public:
    Members(){
    }



    void add(Person name){
        names.push_back(name);
    }

    int find(string name){
        for(int i=0;i<names.size();i++){
            if (names[i].getName() == name){
                return i;
            }
        }
        return -1;
    }


    void print(){
        sort(names.begin(), names.end());
        cout << names.size() << "\n";
        for(int i=0;i<names.size();i++){
            cout << names[i].getName() << " ";
            int ranking = names[i].getRank();
            if (ranking > 99999) cout << "undefined" << "\n";
            else cout << names[i].getRank() << "\n";
        }
    }

    void setRankings(int* distance){
        for (int i=0;i<names.size();i++){
            if (distance[i] < 99999) names[i].setRank(distance[i]);
            else names[i].setRank(100000);
        }
    }
};

class Graph{
    int** matrix;
    int nodes;
    int edges;
    int* mark;
    int* distance;

public:
    Graph(int nodes){
        this->matrix = new int*[nodes];
        for(int i=0;i<nodes;i++){
            this->matrix[i] = new int[nodes];
            for(int j=0;j<nodes;j++){
                this->matrix[i][j] = 0;
            }
        }
        this->nodes = nodes;
        this->mark = new int[nodes];
        this->distance = new int[nodes];
        for(int i=0;i<nodes;i++){
            if (i==0) distance[i] = 0;
            else distance[i] = 100000;
        }
        this->edges = 0;
    }

    int first(int v){
        for (int i=0;i<nodes;i++){
        if (matrix[v][i] != 0 ) return i;
        }
        return nodes;
    }

    int next(int v, int w){
        for(int i=w+1;i<nodes;i++){
            if (matrix[v][i] != 0) return i;
        }
        return nodes;
    }

    void setEdge(int i, int j){
        if (matrix[i][j] == 0){
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            edges++;
        }
    }

    void setMark(int v, int is_visited){
        mark[v] = is_visited;
    }

    int getMark(int v){
        return mark[v];
    }

    void print(){
        for (int i=0;i<nodes;i++){
            for (int j=0;j<nodes;j++){
                cout << matrix[i][j] << " " << "\n";
            }
        }
    }

    void printDistance(){
        for (int i=0;i<nodes;i++){
            cout << distance[i] << " ";
        }
    }

    void BFS(int start){
        queue<int> fila;
        fila.push(start);
        setMark(start, 1);
        while (!fila.empty()){
            int v = fila.front();
            fila.pop();
            int w = first(v);
            while (w < nodes){
                if (getMark(w) == 0){
                    setMark(w, 1);
                    fila.push(w);
                    distance[w] = distance[v] + 1;
                }
                w = next(v, w);
            }
            //pós visita//
        }
    }

    void findRanking(){
        for (int v=0;v<nodes;v++) setMark(v, 0);
        for (int v=0;v<nodes;v++){
            if (getMark(v) == 0) BFS(v);
        }
    }

    int* getDistances(){
        return distance;
    }



};

int main(){
    int i, j, cases, teams;
    string name1, name2, name3;
    cin >> cases;
    for(i=0;i<cases;i++){
        Members names;
        Person Ahmad("Ahmad", 0);
        names.add(Ahmad);
        cin >> teams;
        Graph grafo((3*teams));
        int cnt = 1;
        for(j=0;j<teams;j++){
            cin >> name1 >> name2 >> name3;
            int idx1 = names.find(name1);
            if (idx1 == -1){
                idx1 = cnt;
                Person p1(name1, cnt);
                names.add(p1);
                cnt++;
            }
            int idx2 = names.find(name2);
            if (idx2 == -1){
                idx2 = cnt;
                Person p2(name2, cnt);
                names.add(p2);
                cnt++;
            }
            int idx3 = names.find(name3);
            if (idx3 == -1){
                idx3 = cnt;
                Person p3(name3, cnt);
                names.add(p3);
                cnt++;
            }
            grafo.setEdge(idx1, idx2);
            grafo.setEdge(idx1, idx3);
            grafo.setEdge(idx2, idx3);


        }
        grafo.findRanking();
        names.setRankings(grafo.getDistances());
        names.print();
    }



    return 0;
}
