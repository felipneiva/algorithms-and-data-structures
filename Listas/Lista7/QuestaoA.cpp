#include<bits/stdc++.h>

using namespace std;

int mover[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int movec[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int maxDepth;


class Square{
    int visited;
    int blocked;

public:
    Square(int v, int b){
        this->visited = v;
        this->blocked = b;
    }

    int getVisited(){
        return this->visited;
    }

    int getBlocked(){
        return this->blocked;
    }

    void setVisited(int v){
        this->visited = v;
    }

    void setBlocked(int b){
        this->blocked = b;
    }

};

class Board{
    vector<Square>* matrix;

public:
    Board(){
        this->matrix = new vector<Square>[14];
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                Square newSquare(0, 1);
                this->matrix[i].push_back(newSquare);
            }
        }
    }

    void print(){
        for(int i=0;i<14;i++){
            for(int j=0;j<14;j++){
                cout << "(" << this->matrix[i][j].getVisited() << ", " << this->matrix[i][j].getBlocked() << ") ";
            }
            cout << "\n";
        }
    }

    void setSquare(int row, int skip, int squares){
        for(int i=0;i<squares;i++){
            if(row == 0 && i == 0) this->matrix[row+2][i+2+skip].setVisited(1);
            this->matrix[row+2][i+2+skip].setBlocked(0);
        }
    }

    void backTracking(int r, int c, int depth){
        maxDepth = max(maxDepth, depth);
        for(int i=0;i<8;i++){
            int dr = r + mover[i];
            int dc = c + movec[i];
            if(this->matrix[dr][dc].getVisited() == 0 && this->matrix[dr][dc].getBlocked() == 0){
                this->matrix[dr][dc].setVisited(1);
                backTracking(dr, dc, depth+1);
                this->matrix[dr][dc].setVisited(0);
            }
        }
    }
};

int main(){
    int rows, skip, squares;
    int ncase = 0;
    bool input = true;
    while(input){
        cin >> rows;
        if(rows == 0) input = false;
        else{
            maxDepth = -1;
            ncase++;
            Board tabuleiro;
            int totalSquares = 0;
            for(int i=0;i<rows;i++){
                cin >> skip >> squares;
                totalSquares += squares;
                tabuleiro.setSquare(i, skip, squares);
            }
            tabuleiro.backTracking(2, 2, 1);
            cout << "Case " << ncase << ", ";
            int notReach = totalSquares - maxDepth;
            if(notReach == 1) cout << notReach << " square can not be reached.\n";
            else cout << notReach << " squares can not be reached.\n";
        }
    }


    return 0;
}
