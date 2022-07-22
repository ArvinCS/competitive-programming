#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	a[0] = -1;
	for(int x=1;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
    return 0;
}

