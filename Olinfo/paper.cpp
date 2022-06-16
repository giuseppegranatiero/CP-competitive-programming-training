#include <bits/stdc++.h>
#define MAXN 75001
using namespace std;

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int res;

vector<int> adj[MAXN], rev[MAXN], new_adj[MAXN];
stack<int> s;
vector<int> visited, scc;
unordered_map<int, int> mp;
int n, m, a, b, scc_level=0;

void dfs(int node){
    visited[node] = 1;
    for(int j: adj[node]){
        if(visited[j] == 0) dfs(j);
    }
    s.push(node);
}

void dfs2(int node, int scc_level){
    mp[scc_level]++;
    scc[node] = scc_level;
    visited[node] = 1;
    for(int j: rev[node]){
        if(visited[j] == 0){
            dfs2(j, scc_level);
        } 
    }
}

void kosaraju(){
    visited.resize(n+1, 0);
    for(int i=1; i<=n; ++i){
        if(visited[i]==0) dfs(i);
    }
    visited.clear();
    visited.resize(n+1, 0);
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(visited[node] == 0){
            scc_level++;
            dfs2(node, scc_level);
        } 
    }
}

void condensation(){
    set<pair<int, int>> c;
    for(int i=1; i<=n; ++i){
        for(int j: adj[i]){
            if(scc[i] != scc[j]){
                c.insert(make_pair(scc[i], scc[j]));
            }
        }
    }
    for(auto j: c){
        new_adj[j.first].push_back(j.second);
        //cout << j.first << " -> " << j.second << endl;
    }
}

int bfs(int start){
    queue<pair<int,int>> q;
    q.push(make_pair(start, 0));
    int ris = 0;
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        visited[node] = 1;
        q.pop();
        ris = max(ris, dist);
        for(int j: new_adj[node]){
            if(visited[j]==0) q.push(make_pair(j, dist+1));
        }
    }
    return ris;
}


// Declaring functions
int paper(int N, int M, int* from, int* to){
	n = N;
	m = M;
    for(int i=0; i<m; ++i){
        a = from[i];
        b = to[i];
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    scc.resize(n+1);
    kosaraju();
    condensation();
    int ris = 0;
    for(int i=1; i<=scc_level; ++i){
        visited.clear();
        visited.resize(scc_level+1, 0);
        if(bfs(i) == scc_level-1) ris += mp[i];
    }
    return ris;
}