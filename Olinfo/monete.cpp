#include <bits/stdc++.h>

#define MAXN 10000
#define MAXM 100000

using namespace std;

int monete[MAXN];
int A,B;
vector <int> adj[MAXN];
int tot=0;
bool visti[MAXN];

void dfs(int nodo){
	if (visti[nodo] == true) return;
	tot+=monete[nodo];
	visti[nodo] = true;
	for(int i = 0; i < adj[nodo].size();i++){
		int next = adj[nodo][i];
		if(visti[next]==false) dfs(next);
	}	
}

int main() {
    FILE *fr, *fw;
    int N, M, i;

	fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &monete[i]));
    for(i=0; i<M; i++){
    	assert(2 == fscanf(fr, "%d%d", &A, &B));
    	adj[A].push_back(B);
    	adj[B].push_back(A);
	}
	
	dfs(0);
	
    fprintf(fw, "%d\n", tot);
    fclose(fr);
    fclose(fw);
    return 0;
}