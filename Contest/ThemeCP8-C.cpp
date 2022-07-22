#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;
const ll mod = 1e9 + 7;

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
	
	int p, k;
	cin >> p >> k;
	
	if(k == 0){
		ll ans = 1;
		for(int x=0;x<=p-2;x++){
			ans *= p;
			ans %= mod;
		}
		
		cout << ans << "\n";
		return 0;
	}
	
	dsu.reset();

	for(int x=0;x<=p-1;x++){
		dsu.merge(x, (k*1ll*x)%p);
	}
	
	int cnt = 0;
	for(int x=0;x<=p-1;x++){
		if(dsu.getParent(x) == x){
			cnt++;
		}
	}
	
	ll ans = 1;
	for(int x=0;x<cnt-(k > 1);x++){
		ans *= p;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

