#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN);

struct SparseTable {
	int table[logN+1][maxN];
	
	void reset(int n, int a[]){
		for(int x=0;x<n;x++){
			table[0][x] = a[x];
		}
		for(int i=1;i<=logN;i++){
			int length = (1 << i);
			for(int x=0;x+length<=n;x++){
				table[i][x] = __gcd(table[i-1][x], table[i-1][x+length/2]);
			}
		}
	}	
	
	int query(int l, int r){
		int lg = log2(r-l+1);
		int length = (1 << lg);
		return __gcd(table[lg][l], table[lg][r-length+1]);
	}
};

SparseTable table;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	table.reset(n, a);
	
	set<int> st;
	int ans = 0;
	int mx = -1;
	for(int x=0;x<n;x++){
		int bound = -1;
		int pos = x;
		while(pos >= 0){
			int left = 0, right = pos;
			int mn = pos;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(table.query(mid, x) == table.query(pos, x)){
					mn = min(mn, mid);
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			if(x-pos+1 <= table.query(pos, x) && table.query(pos, x) <= x-mn+1){
				bound = x-table.query(pos,x)+1;
				break;
			}
			
			pos = mn-1;
		}
		
		if(bound != -1){
			if(mx < bound){
				mx = x;
				ans++;
			}
		}
		
		if(x > 0) cout << " ";
		cout << ans;
	}
	cout << "\n";
    return 0;
}

