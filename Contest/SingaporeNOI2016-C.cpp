#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 505;

vector<int> adj[maxN];
int table[maxN];

void dfs(int curNode){
	if(table[curNode] != -1) return;
	
	table[curNode] = 0;
	for(auto nxt : adj[curNode]){
		dfs(nxt);
		table[curNode] += table[nxt];
	}
	table[curNode] = max(table[curNode], 1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	int s[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second >> s[x];
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x == y) continue;
			if(p[x].second < p[y].second && max(abs(p[x].first-p[y].first), abs(p[x].second-p[y].second)) <= max(s[x], s[y])){
				adj[x].push_back(y);
			}
		}
	}
	
	fill(table, table+n, -1);
	
	int ans = 2;
	for(int x=0;x<n;x++){
		if(table[x] == -1){
			dfs(x);
			ans = max(ans, table[x]);
			cout << x << " -> " << table[x] << "\n";
		}
	}
	
	cout << ans << "\n";
    return 0;
}

