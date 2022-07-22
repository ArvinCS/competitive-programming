#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
int val[maxN], sz[maxN];
vector<pair<int, int>> q[maxN];
vector<int> v[maxN];
int ans[maxN];

void dfs(int curNode, int prvNode){
	sz[curNode] = 1;
	
	v[curNode].push_back(val[curNode]);
	int mx = -1, id = -1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			
			for(auto x : v[nxt]){
				v[curNode].push_back(x);
			}
		}
	}
	
	sort(v[curNode].rbegin(), v[curNode].rend());
	
	while(v[curNode].size() > 20){
		v[curNode].pop_back();
	}
	
	for(auto p : q[curNode]){
		ans[p.second] = v[curNode][p.first-1];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		cin >> val[x];
	}
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<m;x++){
		int a, k;
		cin >> a >> k;
		
		a--;
		q[a].push_back({k, x});
	}
	
	dfs(0, -1);
	
	for(int x=0;x<m;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

