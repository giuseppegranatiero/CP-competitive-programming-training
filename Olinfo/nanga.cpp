#include <bits/stdc++.h>
using namespace std;

int mostFrequent(vector<int> arr, int n)
{
    // Insert all elements in hash.
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
 
    // find the max frequency
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return res;
}

int main(){
    assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
    int n, k;
    cin >> n;
    vector<int> ris;
    int last = 5000;
    ris.push_back(5000);
    for(int i=1; i<=n; i++){
        cin >> k;
        last+=k;
        ris.push_back(last);
    }
    cout << mostFrequent(ris, n+1);
}