#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<string> tags(n);
    unordered_map<string, int> hash;
    set<pair<int, string>> trend;
    for(int i=0; i<n; i++){
        cin >> tags[i];
    }
    for(int i=0; i<t; i++){
        hash[tags[i]]++;
        trend.insert(make_pair(-hash[tags[i]], tags[i]));
    }
    cout << (*trend.begin()).second << endl;
    set<pair<int, string>>::iterator it;
    for(int i=1; i<=n-t; i++){
        //vector<string> subvector = {tags.begin() + i, tags.end() - (n-t-i)};
        it = trend.find(pair<int,string>(-hash[tags[i-1]], tags[i-1]));
        if(it!=trend.end()) trend.erase(it);
        hash[tags[i-1]]--;
        trend.insert(make_pair(-hash[tags[i-1]], tags[i-1]));
        it = trend.find(pair<int,string>(-hash[tags[i+t-1]], tags[i+t-1]));
        if(it!=trend.end()) trend.erase(it);
        hash[tags[i+t-1]]++;
        trend.insert(make_pair(-hash[tags[i+t-1]], tags[i+t-1]));
        cout << (*trend.begin()).second << endl;
    }
}