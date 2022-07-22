#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];

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
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			sz[a] += sz[b];
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, s;
	cin >> n >> m >> s;
	
	s--;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	
	dsu.reset();
	
	vector<int> ans;
	for(int x=n-1;x>=0;x--){
		for(auto nxt : adj[x]){
			if(nxt > x) dsu.merge(nxt, x);
		}
		
		if(x <= s && dsu.getParrent(s) == dsu.getParrent(x)){
			ans.push_back(x);
		}
	}
	
	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

