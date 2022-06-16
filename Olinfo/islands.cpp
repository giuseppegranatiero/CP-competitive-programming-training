#include <bits/stdc++.h>
// constraints
#define MAXN 1000

using namespace std;

// input data
int R, C, i, j, tot=0, flag;
int M[MAXN][MAXN];
int visto[MAXN][MAXN];

void island(int r, int c){
    if (M[r][c]==1){
        if (r==0 ||  r==R-1 || c==0 || c==C-1){
            flag=0;
            return;
        }
    }
    M[r][c] = 0;
    if (M[r+1][c]==1){
        island(r+1, c);
    }
    if (M[r-1][c]==1){
        island(r-1, c);
    }
    if (M[r][c+1]==1){
        island(r, c+1);
    }
    if (M[r][c-1]==1){
        island(r, c-1);
    }
    else return;
}

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    // insert your code here
    for (int r=1; r<R-1; r++){
        for (int c=1; c<C-1; c++){
            if (M[r][c] == 1)
            {
                flag=1;
                island(r,c);
                if (flag==1) tot++;
            }
        }
    }
    printf("%d\n", tot); // print the result
    return 0;
}