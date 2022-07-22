#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2 * 1e5 + 5;

ll cost[maxN];
ll visited[maxN];
vector<int> adj[maxN];

ll dfs(int curNode){
	if(visited[curNode] != -1) return visited[curNode];
	
	ll ans = cost[curNode];
	if(adj[curNode].size() > 0){
		for(auto x : adj[curNode]){
			ans = min(ans, dfs(x));
		}
	}
	
	return visited[curNode] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> cost[x];
		visited[x] = -1;
	}
	
	for(int x=0;x<m;x++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		adj[tmp2-1].push_back(tmp1-1);
	}
	
	ll ans = -inf_int;
	for(int x=0;x<n;x++){
		if(adj[x].size() > 0){
			for(auto y : adj[x]){
//				cout << x << " to " << y << "\n";
//				cout << cost[x] << " " << dfs(y) << "\n";
				ans = max(ans, cost[x] - dfs(y));
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

