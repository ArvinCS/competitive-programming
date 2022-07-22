#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;
const int logN = log2(maxN)+1;

int lg[maxN];

struct SparseTable {
	int table[logN][maxN];
	
	void build(int n, int m[]){
		fill(table[0], table[logN], 1e9 + 2);
		
		for(int x=0;x<n;x++){
			table[0][x] = m[x];
		}
		for(int x=1;x<logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	int query(int left, int right){
		assert(left <= right);
		int log = log2(right-left+1);
		int length = (1 << log);
		return min(table[log][left], table[log][right-length+1]);
	}
} table;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m[n];
	for(int x=0;x<n;x++){
		cin >> m[x];
	}
	
	table.build(n, m);
	
	ll prefix[n], suffix[n];
	for(int x=0;x<n;x++){
		int bound = x;
		int left = 0, right = x;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(mid, x) == m[x]){
				bound = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		prefix[x] = (x-bound+1)*1ll*m[x] + (bound > 0 ? prefix[bound-1] : 0);
	}
	for(int x=n-1;x>=0;x--){
		int bound = x;
		int left = x, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid) == m[x]){
				bound = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		suffix[x] = (bound-x+1)*1ll*m[x] + (bound+1 < n ? suffix[bound+1] : 0);
	}
	
	pair<ll, int> best = {-1, -1};
	for(int x=0;x<n;x++){
		int boundL = x;
		int left = 0, right = x;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(mid, x) >= m[x]){
				boundL = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		int boundR = x;
		left = x, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid) >= m[x]){
				boundR = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		best = max(best, {(boundR-boundL+1)*1ll*m[x]+(boundL > 0 ? prefix[boundL-1] : 0)+(boundR+1 < n ? suffix[boundR+1] : 0), x});
	}
	
	ll ans[n];
	int cur = m[best.second];
	for(int l=best.second;l>=0;l--){
		cur = min(cur, m[l]);
		ans[l] = cur;
	}
		
	cur = m[best.second];
	for(int r=best.second+1;r<n;r++){
		cur = min(cur, m[r]);
		ans[r] = cur;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

