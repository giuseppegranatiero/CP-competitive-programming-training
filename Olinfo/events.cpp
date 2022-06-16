#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, v;
    cin >> n >> v;
    int event[n], voucher[v];
    for(int i=0; i<n; i++){
        cin >> event[i];
    }
    for(int i=0; i<v; i++){
        cin >> voucher[i];
    }
    sort(event, event+n);
    sort(voucher, voucher+v);
    int i=n-1, j=v-1, ris=0;
    while(i>=0 && j>=0){
        if(voucher[j]>=event[i]){
            ris++;
            i--;
            j--;
        }
        else{
            i--;
        }
    }
    cout << ris;
}