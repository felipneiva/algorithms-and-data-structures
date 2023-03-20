#include<bits/stdc++.h>

using namespace std;

int mover[] = {0, 0, -1, 1};
int movec[] = {1, -1, 0, 0};
int spikes_found = -1;
bool treasure = false;


class Square{
    int visited;
    char simbol;

public:
    Square(int v, char s){
        this->visited = v;
        this->simbol = s;
    }

    int getVisited(){
        return this->visited;
    }

    void setVisited(int v){
        this->visited = v;
    }

    char getSimbol(){
        return this->simbol;
    }

    void setSimbol(char simbol){
        this->simbol = simbol;
    }

};

class Maze{
    vector<Square>* matrix;

public:
    Maze(){
        this->matrix = new vector<Square>[42];
        for(int i=0;i<42;i++){
            for(int j=0;j<42;j++){
                Square newSquare(0, '#');
                this->matrix[i].push_back(newSquare);
            }
        }
    }

    void print(){
        for(int i=0;i<42;i++){
            for(int j=0;j<42;j++){
                cout << "(" << this->matrix[i][j].getVisited() << ", " << this->matrix[i][j].getSimbol() << ") ";
            }
            cout << "\n";
        }
    }

    void setMaze(int i, int j, char simbol){
        this->matrix[i+1][j+1].setSimbol(simbol);
    }

    void backTracking(int r, int c, int lifes){
        if(treasure)return;
        if(this->matrix[r][c].getSimbol() == 's'){
            lifes -= 2;
            if(lifes < 0) return;
        }
        if(this->matrix[r][c].getSimbol() == 'x'){
            treasure = true;
            return;
        }
        this->matrix[r][c].setVisited(1);
        for(int i=0;i<4;i++){
            int dr = r + mover[i];
            int dc = c + movec[i];
            if(this->matrix[dr][dc].getVisited() == 0 && this->matrix[dr][dc].getSimbol() != '#'){
                backTracking(dr, dc, lifes);
            }
        }
    }


};

int main(){
    int r, c, spikes, i, j;
    int x, y;
    char simbol;
    Maze labirinto;
    cin >> r >> c >> spikes;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> simbol;
            if(simbol == '@'){
                x = i;
                y = j;
            }
            labirinto.setMaze(i, j, simbol);
        }
    }
    labirinto.backTracking(x+1, y+1, spikes);
    if(treasure) cout << "SUCCESS";
    else cout << "IMPOSSIBLE";


    return 0;
}
