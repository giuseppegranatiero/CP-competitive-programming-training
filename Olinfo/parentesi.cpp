#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	assert(freopen("input.txt", "r", stdin)!=NULL);
	assert(freopen("output.txt", "w", stdout)!=NULL);
	int n;
	cin >> n;
	char parentesi;
	stack<char> open;
	for (int i=0; i<n; i++){
		cin >> parentesi;
		if (parentesi=='(' || parentesi=='[' || parentesi=='<' || parentesi=='{'){
			open.push(parentesi);
		}
		else{
			if (!open.empty() && parentesi == ')' && open.top()=='(') open.pop();
			else if (!open.empty() && parentesi == ']' && open.top()=='[') open.pop();
			else if (!open.empty() && parentesi == '}' && open.top()=='{') open.pop();
			else if (!open.empty() && parentesi == '>' && open.top()=='<') open.pop();
		}
	}
	if (n%2!=0) cout << "malformata";
	else{
		if (open.empty()) cout << "corretta";
		else cout << "malformata";
	}
}