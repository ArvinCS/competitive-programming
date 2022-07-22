#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int maxN = 1e5 + 5;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
} dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		dsu.reset(n);
		
		vector<pair<int, int>> v;
		int c[n], l[n], r[n];
		for(int x=0;x<n;x++){
			cin >> c[x] >> l[x] >> r[x];
			v.push_back({l[x], x});
			v.push_back({r[x], x});
		}
		
		bool active[n];
		fill(active, active+n, false);
		
		set<pair<int, int>> cnt[2];
		set<int> st[2];
		
		int ans = 0;
		for(int x=0;x<v.size();x++){
			if(!active[v[x].second]){
				if(c[v[x].second]){
					if(!cnt[0].empty()){
						pair<int, int> mx = *(cnt[0].rbegin());
						cnt[0].clear();
						
						cnt[0].insert(mx);
						dsu.merge(v[x].second, mx.second);
					}
				} else {
					if(!cnt[1].empty()){
						pair<int, int> mx = *(cnt[1].rbegin());
						cnt[1].clear();
						
						cnt[1].insert(mx);
						dsu.merge(v[x].second, mx.second);
					}
				}
				
				cnt[c[v[x].second]]++;
				ans++;
			}
			
			active[v[x].second] ^= 1;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

