#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const ll mod = 1e9 + 7;

struct DSU {
	int parent[maxN], sz[maxN];
	bool f[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
			parent[x] = x;
			sz[x] = 1;
			f[x] = false;
		}
	}
	
	void toggle(int x){
		f[x] ^= 1;
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
			f[a] |= f[b];
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], b[n], d[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		for(int x=0;x<n;x++){
			cin >> d[x];
		}
		
		for(int x=0;x<n;x++){
			a[x]--;
			b[x]--;
			d[x]--;
		}
		
		dsu.reset(n);
		
		for(int x=0;x<n;x++){
			if(d[x] != -1){
				dsu.toggle(d[x]);
			}
		}
		
		for(int x=0;x<n;x++){
			dsu.merge(a[x], b[x]);
		}
		
		ll ans = 1;
		for(int x=0;x<n;x++){
			if(dsu.getParent(x) == x){
				if(dsu.sz[x] > 1 && !dsu.f[x]){
					ans *= 2;
					ans %= mod;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

