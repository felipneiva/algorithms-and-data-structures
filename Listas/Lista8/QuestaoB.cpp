#include<bits/stdc++.h>

using namespace std;

void printA(int* a, int s){
    for(int i=0;i<s;i++) cout << a[i] << " ";
}

void DP(int* heights, int* costs, int N, int K){
    for(int i=0;i<N;i++){
        if(i==0)costs[i] = 0;
        else{
            for(int j=1;j<K+1;j++){
                if(i - j >= 0) costs[i] = min(costs[i-j]+ abs(heights[i] - heights[i-j]), costs[i]);
                else break;
            }
        }
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    int* heights = new int[N];
    int* costs = new int[N];
    for(int i=0;i<N;i++){
        cin >> heights[i];
        costs[i] = INT_MAX;
    }

    DP(heights, costs, N, K);
    cout << costs[N-1];


    return 0;
}
