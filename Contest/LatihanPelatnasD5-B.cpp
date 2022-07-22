#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

struct SparseTable {
	ll table[maxN][logN+1];
	int n;
	
	void build(int n, ll a[]){
		this->n = n;
		
		for(int x=0;x<n;x++){
			table[x][0] = a[x];
		}
		for(int i=1;i<=logN;i++){
			int length = (1 << i);
			
			for(int x=0;x+length<=n;x++){
				table[x][i] = __gcd(table[x][i-1], table[x+length/2][i-1]);
			}
		}
	}
	
	ll query(int left, int right){
		int lg = log2(right-left+1);
		int length = (1 << lg);
		
		return __gcd(table[left][lg], table[right-length+1][lg]);
	}
};

SparseTable table;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		table.build(n, a);
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			int pos = x;
			
			while(pos < n){
				ll gcd = table.query(x, pos);
				
				int left = pos, right = n-1, bound = pos;
				while(left <= right){
					int mid = (left+right) >> 1;
					
					if(table.query(x, mid) == gcd){
						bound = max(bound, mid);
						left = mid+1;
					} else {
						right = mid-1;
					}
				}
				
				ll cnt = (bound-x+1)*gcd;
				ans = max(ans, cnt);
				pos = bound+1;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
