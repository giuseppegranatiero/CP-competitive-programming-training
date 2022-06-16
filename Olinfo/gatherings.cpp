#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll int n, c, ris = 0, i=0;
    cin >> n >> c;
    vector<ll int> dist(n);
    for(int i=0; i<n; ++i){
        cin >> dist[i];
    }
    vector<ll int>::iterator low;
    for(auto x = dist.begin(); x!=dist.end()-1; x++){
        low = lower_bound(x , dist.end(), dist[i]+c);
        ris += (low - x-1);
        i++;
    }
    cout << ris;
}