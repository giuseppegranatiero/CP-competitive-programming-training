#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

// input data
int N1, N2, tot=0;
int ID1[MAXN], ID2[MAXN];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
  
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
  
    // if we reach here, then element was
    // not present
    return -1;
}

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N1, &N2));
    for(int i=0; i<N1; i++)
        assert(1 == scanf("%d", &ID1[i]));
    for(int i=0; i<N2; i++)
        assert(1 == scanf("%d", &ID2[i]));

    // insert your code here
    qsort(ID2, N2, sizeof(int), compare);
    for (int i=0; i<N1; i++){
    	if(binarySearch(ID2, 0, N2-1, ID1[i]) >-1){
    		++tot;
		}
	}
    printf("%d\n", tot); // print the result
    return 0;
}