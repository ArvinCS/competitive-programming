#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct DSU {
	int parrent[maxN], sz[maxN];
	ll ans[maxN];
	map<int, int> mp[maxN];
	
	void reset(int n, int val[]){
		for(int x=0;x<n;x++){
			parrent[x] = x;
			sz[x] = 1;
			ans[x] = 0;
			mp[x][val[x]] = 1;
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];
			
			for(auto p : mp[b]){
				int &ref = mp[a][p.first];
				
				ans[a] -= ref*1ll*(ref-1)/2;
				ref += p.second;
				ans[a] += ref*1ll*(ref-1)/2;
			}
		}
	}
};

vector<pair<int, int>> adj[maxN];
int val[maxN];
DSU dsu;

void dfs(int curNode, int prvNode, int cur){
	val[curNode] = cur;
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			dfs(nxt.first, curNode, cur^nxt.second);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n-1;x++){
		int c;
		cin >> a[x] >> b[x] >> c;
		
		a[x]--; b[x]--;
		adj[a[x]].push_back({b[x], c});
		adj[b[x]].push_back({a[x], c});
	}
	
	int p[n];
	for(int x=1;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	
	dfs(0, 0, 0);
	dsu.reset(n, val);
	
	ll ans[n], cur = 0;
	for(int x=n-1;x>=0;x--){
		ans[x] = cur;
		
		if(x == 0) continue;
		
		cur -= dsu.ans[dsu.getParrent(a[p[x]])] + dsu.ans[dsu.getParrent(b[p[x]])];
		dsu.merge(a[p[x]], b[p[x]]);
		cur += dsu.ans[dsu.getParrent(a[p[x]])];
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

