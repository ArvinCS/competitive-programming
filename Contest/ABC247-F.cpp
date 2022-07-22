#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 998244353;

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
};

DSU dsu;
ll fib[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fib[0] = 0;
	fib[1] = 1;
	for(int x=2;x<maxN;x++){
		fib[x] = (fib[x-1] + fib[x-2]) % mod;
	}
	
	int n;
	cin >> n;
	
	int p[n], q[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	for(int x=0;x<n;x++){
		cin >> q[x];
		q[x]--;
	}
	
	dsu.reset();
	
	int idx[n], idx2[n];
	for(int x=0;x<n;x++){
		idx[p[x]] = x;
		idx2[q[x]] = x;
	}
	for(int x=0;x<n;x++){
		dsu.merge(idx[q[x]], x);
		dsu.merge(idx2[p[x]], x);
	}
	
	ll ans = 1;
	for(int x=0;x<n;x++){
		if(dsu.getParent(x) == x){
			if(dsu.sz[x] > 1){
				ans *= (fib[dsu.sz[x]]+2*fib[dsu.sz[x]-1]) % mod;
				ans %= mod;
			}
		}
	}
	
	cout << ans % mod << "\n";
    return 0;
}

