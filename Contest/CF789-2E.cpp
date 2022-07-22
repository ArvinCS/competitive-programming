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
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
		}
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
		for(int x=0;x<n;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			dsu.merge(a, b);
		}
		
		ll ans = 0;
		int cnt = 0;
		for(int x=0;x<n;x++){
			if(dsu.getParent(x) == x){
				if(dsu.sz[x] > 1){
					cnt++;
				}
			}
		}
		
		for(int x=1;x<=cnt;x++){
			ans += abs((n-x+1)-x)*2;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

