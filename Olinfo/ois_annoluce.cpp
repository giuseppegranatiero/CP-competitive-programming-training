#include <bits/stdc++.h>
#define NMAX 100000
#define ll long long
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll int n, k, x, y, z, d;
    vector<double> dist;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y >> z;
        dist.push_back(sqrt(x*x+y*y+z*z));
    }
    sort(dist.begin(), dist.end());
    vector<double>::iterator ris;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> d;
        ris = upper_bound(dist.begin(), dist.end(), d);
        cout << ris - dist.begin() << endl;
    }
}