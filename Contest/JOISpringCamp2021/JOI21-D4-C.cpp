#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> adj[n];
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	int a[n], h[n], c[n];
	for(int x=0;x<n;x++){
		cin >> a[x] >> h[x] >> c[x];
		a[x]--;
		if(a[x] != x){
			adj[a[x]].push_back(x); // rev the edge
		}
	}
	
	ll table[n][2];
	fill(table[0], table[n], 1e18);
	
	bool visited[n];
	fill(visited, visited+n, false);
	
	auto dfs = [&table, &visited, &c, &adj, &h](auto self, int curNode) -> void {
		visited[curNode] = true;
		table[curNode][0] = 0;
		table[curNode][1] = c[curNode];
		for(auto nxt : adj[curNode]){
			self(self, nxt);
			if(h[curNode] <= h[nxt]){
				table[curNode][0] += min(table[nxt][0], table[nxt][1]);
			} else {
				table[curNode][0] += table[nxt][1];
			}
			
			table[curNode][1] += min(table[nxt][0], table[nxt][1]);
		}
	};
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(a[x] == x){
			dfs(dfs, x);
			ans += min(table[x][0], table[x][1]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

