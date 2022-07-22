#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

vector<int> adj[maxN];

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
	
	bool check(int x, int y){
		return getParent(x) == getParent(y);
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	dsu.reset();
	
	bool self[n];
	fill(self, self+n, false);
	
	int cnt = n;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(a == b){
			self[a] = true;
			continue;
		}
		
		if(!dsu.check(a, b)){
			dsu.merge(a, b);
			cnt--;
		}
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if(cnt > 1){
		cout << "0\n";
		return 0;
	}
	if(m == 2){
		cout << "1\n";
		return 0;
	}
	
	bool leaf[n];
	fill(leaf, leaf+n, false);
	
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			leaf[x] = true;
		}
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		int cnt = 0, cnt2 = 0;
		for(auto nxt : adj[x]){
			if(leaf[nxt]){
				if(!self[nxt]) cnt++;
				else cnt2++;
			}
		}
		
		ans += cnt*1ll*(cnt-1)/2;
		
		if(adj[x].size() == 2){
			for(auto nxt : adj[x]){
				if(leaf[nxt]){
					if(!self[nxt]) cnt++;
					else cnt2++;
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

