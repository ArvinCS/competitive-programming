#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct DSU {
	int comp, parent[maxN], sz[maxN];
	
	void reset(int n){
		comp = n;
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
			comp--;
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
};

vector<int> adj[maxN];
DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll d[n];
	for(int x=0;x<n;x++){
		cin >> d[x];
	}
	
	dsu.reset(n);
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		dsu.merge(a, b);
	}
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += d[x]-((int) adj[x].size());
	}
	
	if(sum % 2 == 1){
		cout << "-1\n";
		return 0;
	}
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		ll need = d[x]-((int) adj[x].size());
		
		if(need < 0 || sum-need < need){
			cout << "-1\n";
			return 0;
		}
		
		if(need > 0) v.push_back({need, x});
	}
	
	sort(v.begin(), v.end());
	
	if(v.size() <= 1){
		cout << "-1\n";
		return 0;
	}
	
	vector<pair<int, int>> ans;
	int pos = ((int) v.size())-1;
	for(int x=0;x<v.size()-1;x++){
		while(v[x].first > 0){
			if(((ll) ans.size()) > n-m-1) break;
			
			ans.push_back({v[x].second, v[pos].second});
			v[x].first--;
			v[pos].first--;
			
			if(v[pos].first < 0){
				cout << "-1\n";
				return 0;
			}
			
			dsu.merge(v[x].second, v[pos].second);
			pos--;
			
			if(pos <= x){
				pos = ((int) v.size())-1;
			}
		}
	}
	for(int x=0;x<v.size();x++){
		if(v[x].first != 0){
			cout << "-1\n";
			return 0;
		}
	}
	
	if(dsu.comp != 1){
		cout << "-1\n";
		return 0;
	}
	if(((ll) ans.size()) != n-m-1){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=0;x<ans.size();x++){
		cout << ans[x].first+1 << " " << ans[x].second+1 << "\n";
	}
    return 0;
}

