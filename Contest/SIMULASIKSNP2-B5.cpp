#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
int prv[maxN];
bool visited[maxN], active[maxN], mark[maxN];

void dfs(int curNode, int prvNode){
	if(active[curNode]){
		int tmp = prvNode;
		mark[tmp] = true;
		
		while(tmp != curNode){
			tmp = prv[tmp];
			mark[tmp] = true;
		}
		return;
	}
	
	prv[curNode] = prvNode;
	active[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && !visited[nxt]){
			dfs(nxt, curNode);
		}
	}
	
	visited[curNode] = true;
	active[curNode] = false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<n;x++){
		mark[x] = active[x] = visited[x] = false;
	}
	
	vector<ll> v;
	
	queue<pair<int, int>> q;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			
		}
	}
	dfs(0, 0);
	
	for(int x=0;x<n;x++){
		if(!mark[x]){
			if(adj[x].size() == 1){
				v.push_back(c[x]);
			} else if(adj[x].size() == 2){
				
			}
		}
	}
	
	sort(v.rbegin(), v.rend());
	
	int sz = v.size();
	ll ans = 0;
	for(int x=0;x<min(sz, k);x++){
		ans += v[x];
	}
	
	cout << ans << "\n";
    return 0;
}

