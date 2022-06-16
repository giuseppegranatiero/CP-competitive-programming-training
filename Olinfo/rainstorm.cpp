#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int parent_node[MAXN];
int h[MAXN];



void MAKE_SET(int x){
    parent_node[x] = x;
    h[x] = 0;
}

int FIND(int x){
    if (x == parent_node[x]) return x;
    return parent_node[x] = FIND(parent_node[x]); // path compression
}

void UNION(int x, int y){  // link by rank (h)
    int a = FIND(x);
    int b = FIND(y);
    if(a != b){               
        if (h[a] < h[b]){
            parent_node[a] = b;
        }
        else{
            parent_node[b] = a;
            if(h[a] == h[b]){
                h[a]++;
            }
        }
    }
}

struct arco{
    int a, b;
    int w;
};

vector<arco> Ab;

bool comp(arco d, arco s){
    return d.w > s.w;
}

void swap(arco a, arco b)
{
    arco t = a;
    a = b;
    b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (arco arr[], int low, int high)
{
    int pivot = arr[high].w;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].w <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(arco arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    vector<arco> archi_sol;
    //set<int> sol;
    cin >> n >> m;
    arco A[m];
    //A.resize(m);
    int sol = 100001;
    for(int i=0; i<m; i++){
        cin >> A[i].a >> A[i].b >> A[i].w;
    }
    quickSort(A, 0, m-1);
    for(int i=0; i<n; i++) MAKE_SET(i);
    for(int i=m-1; i>=0; i--){
        if(FIND(A[i].a) != FIND(A[i].b)){
            UNION(A[i].a, A[i].b);
            sol = min(sol, A[i].w);
        }
    }
    cout << sol << endl;
}