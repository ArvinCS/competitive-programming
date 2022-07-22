#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

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
vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	
	dsu.reset();
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int ans[n], cnt = 0;
	ans[n-1] = 0;
	for(int x=n-1;x>=1;x--){
		cnt++;
		
		for(auto nxt : adj[x]){
			if(nxt >= x){
				if(dsu.merge(x, nxt)) cnt--;
			}
		}
		ans[x-1] = cnt;
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

