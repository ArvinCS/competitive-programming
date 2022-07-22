#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
bool visited[maxN];

pair<int, int> dfs(int curNode, int prvNode, int depth){
	pair<int, int> ans = {depth, curNode};
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			ans = max(ans, dfs(nxt, curNode, depth+1));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(visited, visited+maxN, false);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(!visited[x]){
			int tmp = dfs(x, x, 0).second;
			ans += dfs(tmp, tmp, 0).first+1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
