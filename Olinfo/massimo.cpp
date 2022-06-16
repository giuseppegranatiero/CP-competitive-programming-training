#include <bits/stdc++.h>
using namespace std;

int trova_massimo(int N, vector<int> V){
    int ris = V[0];
    for(int i=1; i<N; ++i){
        ris = max(ris, V[i]);
    }
    return ris;
}