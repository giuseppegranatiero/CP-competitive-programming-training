#include <bits/stdc++.h>
using namespace std;

vector<string> final;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //assert(freopen("inputSpan.txt","r",stdin)!=NULL);
    //assert(freopen("outputSpan.txt","w",stdout)!=NULL);
    assert(freopen("input.txt","r",stdin)!=NULL);
    assert(freopen("output.txt","w",stdout)!=NULL);
	int n;
	cin >> n;
	string user;
	string usernames[n];
	set<string> users;
	for (int i=0; i<n; i++){
		cin >> user;
		users.insert(user);
		usernames[i] = user;
	}
	// if last element of array is in the set delete it
	for (int i=n-1; i>=0; i--){
		if (users.find(usernames[i]) != users.end()) {
			final.push_back(usernames[i]);
			users.erase(users.find(usernames[i]));
		}
	}
	int size = final.size();
	for (int i=0; i<size; i++){
		cout << final[i] << endl;
	}
}