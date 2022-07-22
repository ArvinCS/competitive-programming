#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 35005;
const int maxK = 105;

int a[maxN], n;
ll table[maxK][maxN];
vector<int> v[maxN];

void solve(int k, int l, int r, int optL, int optR){
	if(l > r) return;
		
	int m = (l+r) >> 1;
	ll val = 1e18;
	int idx = -1;
	
	ll cost = 0;
	for(int x=m;x>=optL;x--){
		if(!v[a[x]].empty()){
			cost -= v[a[x]][0] - v[a[x]].back();
		}
		
		v[a[x]].push_back(x);
		
		if(!v[a[x]].empty()){
			cost += v[a[x]][0] - v[a[x]].back();
		}
	}
	
	for(int x=optL;x<=min(m, optR);x++){		
		ll cur = (x > 0 ? table[k-1][x-1] : 0) + cost;
		
		if(cur < val){
			val = cur;
			idx = x;
		}
		
		if(!v[a[x]].empty()){
			cost -= v[a[x]][0] - v[a[x]].back();
		}
		
		v[a[x]].pop_back();
		
		if(!v[a[x]].empty()){
			cost += v[a[x]][0] - v[a[x]].back();
		}
	}
	
	table[k][m] = val;
	
	solve(k, l, m-1, optL, idx);
	solve(k, m+1, r, idx, optR);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int k;
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(table[0], table[maxK], 1e18);
	
	for(int x=1;x<=k;x++){
		solve(x, x-1, n-1, 0, n-1);
	}
	
	cout << table[k][n-1] << "\n";
    return 0;
}

