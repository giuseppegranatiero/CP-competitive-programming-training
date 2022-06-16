#include <bits/stdc++.h>
using namespace std;

double scosse(double N){
    double ris = N*(N-1)/4;
    return ris;
}

int main(){
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    
    double n;
    cin >> n;
    cout << scosse(n) << endl;
}
