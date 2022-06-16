#include <iostream>
#include <queue>
#include <vector>
#define MAXN 500001
#define INF 999999999
using namespace std;

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* inizio;
static int* fine;

struct Node
{
    int next;
    int inizio;
    int fine;
};

Node Nodes[1];

vector<Node> adj[MAXN];

vector<int> tempo;

priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> q;

void dijkstra(){
    while(!q.empty()){
        int node = q.top().second;
        int time = q.top().first;
        //cout << node << endl;
        q.pop();
        if(node == N-1) return;
        
        for(auto x: adj[node]){
            if(time+1 > x.inizio && time+1 <= x.fine){
                if(time+1 < tempo[x.next]){
                    tempo[x.next] = time+1;
                    //cout << "aggiungo " << tempo[x.next] << " " << x.next << endl;
                    q.push(make_pair(tempo[x.next], x.next));
                }
            } 
            else if(time+1 <= x.inizio){
                if(x.inizio+1 < tempo[x.next]){
                    tempo[x.next] = x.inizio+1;
                    //cout << "aggiungo " << tempo[x.next] << " " << x.next << endl;
                    q.push(make_pair(tempo[x.next], x.next));
                }
            } 
        }
    }
}

// Declaring functions
int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]){
	for(int i=0; i<M; i++){
    	Nodes[0].inizio = inizio[i];
		Nodes[0].fine = fine[i];
        Nodes[0].next = B[i];
        adj[A[i]].push_back(Nodes[0]);
        Nodes[0].next = A[i];
        adj[B[i]].push_back(Nodes[0]);
    }
    tempo.resize(N, INF);
    tempo[0] = 0;
    q.push(make_pair(0, 0));
    dijkstra();
    if(tempo[N-1]==INF) return -1;
    else return tempo[N-1];
}