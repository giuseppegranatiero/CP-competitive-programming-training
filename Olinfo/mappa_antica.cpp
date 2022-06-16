#include <bits/stdc++.h>
using namespace std;

int mappa[100][100];
int n;

void search_path(int r, int c){
	for (int k=-1; k<2; k++){
		for (int j=-1; j<2; j++){
			if (r+k<0 || r+k >= n || c+j<0 || c+j >= n);
			else if (mappa[r+k][c+j] == 0 || mappa[r+k][c+j] > mappa[r][c]+1){
				mappa[r+k][c+j] = mappa[r][c] +1;
				search_path(r+k, c+j);
			}
		}
	}
}

int main(){
	assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
    char element;
    cin >> n;
    for (int r=0; r<n; r++){
    	for (int c=0; c<n; c++){
	    	cin >> element;
	    	if (element == '+') mappa[r][c] = -1;
	    	else mappa[r][c] = 0;
		}
	}
	mappa[0][0] = 1;
	search_path(0,0);
	cout << mappa[n-1][n-1];
}