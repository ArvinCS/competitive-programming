#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e3 + 5;

struct DSU {
	int parrent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parrent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}	
	
	bool merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];
			
			return true;
		}
		return false;
	}
};

DSU dsu;
int p[maxN];
vector<pair<int, int>> adj[maxN];
vector<int> ans;

bool dfs(int curNode, int prvNode, int targetNode){
	if(p[curNode] == targetNode){
		return true;
	}
	
	bool valid = false;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			if(dfs(nxt.first, curNode, targetNode)){
				ans.push_back(nxt.second);
				swap(p[nxt.first], p[curNode]);
				valid = true;
			}
		}
	}
	
	return valid;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	
	dsu.reset();
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(dsu.merge(a, b)){
			adj[a].push_back({b, x});
			adj[b].push_back({a, x});
		}
	}
	
	for(int x=0;x<n;x++){
		if(dsu.getParrent(x) != dsu.getParrent(p[x])){
			cout << "-1\n";
			return 0;
		}
	}
	
	bool visited[n];
	int cnt[n];
	fill(cnt, cnt+n, 0);
	fill(visited, visited+n, false);
	
	queue<pair<int, int>> q;
    for(int x=0;x<n;x++){
    	if(adj[x].size() <= 1){
    		q.push({x, -1});
		}
	}
	
	while(!q.empty()){
		int curNode = q.front().first, prvNode = q.front().second;
		q.pop();
		
		if(visited[curNode]) continue;
		visited[curNode] = true;
		
		dfs(curNode, curNode, curNode);
		
		for(auto nxt : adj[curNode]){
			if(nxt.first != prvNode){
				cnt[nxt.first]++;
				
				if(cnt[nxt.first]+1 == adj[nxt.first].size()){
					q.push({nxt.first, curNode});
				}
			}
		}
	}
	
	if(ans.size() > 5e5){
		cout << "-1\n";
		return 0;
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
	return 0;
}

