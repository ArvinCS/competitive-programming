#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 1e9 + 7;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int p;
		cin >> p;
		
		p--;
		adj[p].push_back(x);
	}
	
	cout << 1 << "\n";
	return 0;
}

