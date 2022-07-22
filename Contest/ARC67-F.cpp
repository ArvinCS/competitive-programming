#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 5005;
const int maxM = 205;
const int logN = log2(maxN)+2;

struct SparseTable {
	ll table[logN][maxN];
	
	void build(int n, ll b[]){
		fill(table[0], table[logN], -1e18);
		for(int x=0;x<n;x++){
			table[0][x] = b[x];
		}
		for(int x=1;x<logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y] = max(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	ll query(int l, int r){
		int lg = log2(r-l+1);
		int length = (1 << lg);
		
		return max(table[lg][l], table[lg][r-length+1]);
	}
};

int n, m;
ll a[maxN], b[maxN][maxM];
SparseTable table[maxM];

ll calc(int i, int j){
	if(i > j) swap(i, j);
	return a[j] - a[i];
}

ll compute(int l, int r, int optL, int optR){
	if(l > r) return -1e18;
	
	int mid = (l+r) >> 1;
	pair<ll, int> best = {-1e18, -1};
	
	for(int k=optL;k<=min(mid, optR);k++){
		ll val = -calc(k, mid);
		
		for(int x=0;x<m;x++){
			val += table[x].query(k, mid);
		}
		
		best = max(best, {val, k});
	}
	
	ll ans = best.first;
	int opt = best.second;
	ans = max(ans, compute(l, mid-1, optL, opt));
 	ans = max(ans, compute(mid+1, r, opt, optR));
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	a[0] = 0;
	for(int x=1;x<n;x++){
		cin >> a[x];
		a[x] += a[x-1];
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> b[x][y];
		}
	}
	
	for(int y=0;y<m;y++){
		ll new_b[n];
		for(int x=0;x<n;x++){
			new_b[x] = b[x][y];
		}
		
		table[y].build(n, new_b);
	}
	
	cout << compute(0, n-1, 0, n-1) << "\n";
    return 0;
}

