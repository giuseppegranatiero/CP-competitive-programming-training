#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

vector<pair<int,int>> adj[MAXN];
int visto[MAXN];

// Declaring functions
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D){
    for(int i=0; i<N; ++i){
        D[i] = -1;
        visto[i] = 0;
    }
    for(int i=0; i<M; ++i){
        adj[X[i]].push_back(make_pair(P[i], Y[i]));
    }

    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    D[0] = 0;

    while(!q.empty()){
        int nodo = q.top().second;
        int peso = q.top().first;
        q.pop();
        if(visto[nodo] == 0){
            for(int i=0; i<adj[nodo].size(); i++){
                if(visto[adj[nodo][i].second]==0 ){
                    if(D[adj[nodo][i].second] != -1){
                        D[adj[nodo][i].second] = min(D[adj[nodo][i].second], D[nodo]+adj[nodo][i].first);
                    }
                    else{
                        D[adj[nodo][i].second] = D[nodo]+adj[nodo][i].first;
                    }
                    //D[adj[nodo][i].second] = D[nodo]+adj[nodo][i].first;
                    q.push(make_pair(-D[adj[nodo][i].second], adj[nodo][i].second));
                }
            }
            visto[nodo] = 1;
        }
        
    }
    return;

}