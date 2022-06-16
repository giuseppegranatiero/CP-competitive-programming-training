#include<bits/stdc++.h>
using namespace std;

int sfangate(int N, int V[]) {
    sort(V, V+N);
    int somma = 0;
    for(int i=0; i<N; ++i){
        somma += V[i];
    }
    if(somma > 0) return 0;
    int ris = 0;
    int i = 0;
    while(somma <=0){
        V[i] = -V[i];
        somma += 2*V[i];
        ris++;
        i++;
    }
    return ris;
}




int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");
   int n;
   cin >> n;
   int v[n];
   for(int i=0; i<n; ++i){
       cin >> v[i];
   }
   cout << sfangate(n, v);
}