#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

int a[maxN];

struct SparseTable {
	pair<int, int> table[logN+1][maxN];
	int n;
	void build(int n){
		this->n = n;
		
		for(int x=0;x<n;x++){
			table[0][x] = {a[x], x};
		}
		for(int x=1;x<=logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y] = max(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	pair<int, int> query(int left, int right){
		int lg = log2(right-left+1);
		int length = (1 << lg);
		
		return max(table[lg][left], table[lg][right-length+1]);
	}
};

SparseTable table;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		cin >> a[x];
		a[x]--;
	}
	a[n-1] = n-1;
	
	table.build(n);
	
	ll dp[n];
	dp[n-1] = 0;
	
	ll ans = 0;
	for(int x=n-2;x>=0;x--){
		pair<int, int> p = table.query(x+1, a[x]);
		
		dp[x] = dp[p.second] - max(0, a[x]-p.second) + (n-x-1);
		ans += dp[x];
	}
	
	cout << ans << "\n";
    return 0;
}

