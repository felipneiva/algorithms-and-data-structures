#include<bits/stdc++.h>

using namespace std;

void printA(int* a, int s){
    for(int i=1;i<s+1;i++) cout << a[i] << " ";
}

void printM(int** matrix, int W, int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void createM(int** &matrix, int W, int n){
    matrix = new int*[n+1];
    for(int i=0;i<n+1;i++){
        matrix[i] = new int[W+1];
        for(int j=0;j<W+1;j++){
            matrix[i][j] = -1;
        }
    }
}

int Knapsack(int** F, int* weights, int* values, int W, int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0) F[i][j] = 0;
            else if(weights[i]<= j){
                F[i][j] = max(F[i-1][j], values[i] + F[i-1][j - weights[i]]);
            }
            else F[i][j] = F[i-1][j];
        }
    }
    return F[n][W];
}



int main(){
    int W, n;
    int** matrix;
    cin >> W >> n;
    matrix = new int*[n+1];
    createM(matrix, W, n);
    int* weights = new int[n+1];
    int* values = new int[n+1];
    for(int i=1;i<n+1;i++){
        cin >> weights[i] >> values[i];
    }
    int answer = Knapsack(matrix, weights, values, W, n);
    cout << answer << "\n";
    //printM(matrix, W, n);




    return 0;
}
