#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e4 + 5;
const int logN = log2(maxN)+1;
const int maxK = 25;
const ll mod = 1e9 + 7;

struct SparseTable {
	int table[logN][maxN];
	
	void build(int n, int a[]){
		for(int x=0;x<n;x++){
			table[0][x] = a[x];
		}
		for(int x=1;x<logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y] = __gcd(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	int query(int left, int right){
		int log = log2(right-left+1);
		int length = (1 << log);
		
		return __gcd(table[log][left], table[log][right-length+1]);
	}
};

SparseTable table;
ll ways[maxK][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(ways[0], ways[maxK], 0);
	for(int y=0;y<maxN;y++) ways[0][y] = 1;
	for(int x=0;x<maxK-3;x++){
		ll cur = 0, val = 0;
		for(int y=0;y<maxN-3;y++){
			val += ways[x][y];
			val %= mod;
			
			cur += val;
			cur %= mod;
			
			ways[x+1][y+1] = cur;
		}
	}
	
	string subsoal;
	cin >> subsoal;
	
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}	
	
	table.build(n, a);
	
	ll b[n+1][k+1];
	fill(b[0], b[n+1], 0);
	
	for(int x=0;x<n;x++){
		int r = x;
		while(r < n){
			int cur = table.query(x, r);
			
			int left = r, right = n-1, mx = x;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(table.query(x, mid) == cur){
					mx = max(mx, mid);
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			for(int y=0;y<=min(k-1, x);y++){
				b[r][y] += ways[y][x] * cur % mod;
				b[r][y] %= mod;
				
				b[mx+1][y] -= ways[y][x] * cur % mod;
				if(b[mx+1][y] < 0) b[mx+1][y] += mod;				
			}
			
			r = mx+1;
		}
	}
	
	ll ans = 0;
	for(int y=0;y<=k-1;y++){
		ll cur = 0;
		for(int x=0;x<n-y;x++){			
			cur += b[x][k-1-y];
			cur %= mod;
			
			ans += ways[y][n-x-1] * cur % mod;
			ans %= mod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

