#include <iostream>
#define INF 999999999
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, n, m;
    cin >> n >> m;
    double dist[n][n], p;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> p;
        dist[a][b] = 1000-p;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        double tassazione_tot = (dist[i][k])*(dist[k][j])/1000;
                        /*if (i==j) dist[i][j] = 0;
                        else if (dist[i][j] < tassazione_tot && dist[i][k]!=INF && dist[k][j]!=INF){
                            dist[i][j] = tassazione_tot;}*/
                        if(dist[i][k]!=0 && dist[k][j]!=0) dist[i][j] = max(dist[i][j], tassazione_tot);
                
            }
        }
    }
    int ris_a, ris_b;
    double ris=INF;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (dist[i][j]<ris && dist[i][j]!=INF && i!=j){
                ris = dist[i][j];
                ris_a = i;
                ris_b = j;
            }
        }
    }
    /*cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << ris_a << " " << ris_b << endl;
}