#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = 1e5;
vector<int> adj[maxN+1];

int dfs(int start, bool visited[]){
	visited[start] = true;
	int best = 0;
	for(int x=0;x<adj[start].size();x++){
		if(visited[adj[start][x]]) continue;
		best = max(best, dfs(adj[start][x], visited) + 1);
	}	
//	cout << "best: " << best << "\n";
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bool visited[n+1];
	fill(visited, visited+n+1, false);
	
	int maxDistance = 0, oddDistance = 0;
	bool leaves[n+1];
	fill(leaves, leaves+n+1, false);
	
	for(int x=1;x<=n;x++){
		if(adj[x].size() == 1){
			int tmp = dfs(x, visited);
			
			if(tmp % 2 == 1) oddDistance++;
			maxDistance = max(maxDistance, tmp);
			leaves[x] = true;
		}
	}
	
	int ans = n-1, cnt[n+1];
	fill(cnt, cnt+n+1, 0);
	for(int x=1;x<=n;x++){
		if(leaves[x]){
			cnt[adj[x][0]]++;
			if(cnt[adj[x][0]] > 1){
				ans--;
			}
		}
	}
	
	cout << ((maxDistance == 1 || oddDistance == 0) ? 1 : 3) << " " << ans << "\n";
    return 0;
}

