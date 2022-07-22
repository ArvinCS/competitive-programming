#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;
const int logN = 20;

int a[maxN], lst[maxN];
pair<int, int> table[logN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(lst, lst+maxN, -1);
	
	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int mx = 0;
	for(int x=0;x<n;x++){
		mx = max(mx, lst[a[x]]+1);
		table[0][x] = {x-mx+1, x};
		lst[a[x]] = x;
	}
	
	for(int i=1;i<logN;i++){
		int length = (1 << i);
		for(int x=0;x+length<=n;x++){
			table[i][x] = max(table[i-1][x], table[i-1][x+length/2]);
		}
	}
	
	int last = 0;
	for(int x=0;x<q;x++){
		int l, r;
		cin >> l >> r;
		
		l ^= last; r ^= last;
		l--; r--;
		
		int left = r, right = n-1;
		pair<int, int> ans = {r-l+1, r};
		while(left <= right){
			int mid = (left+right) >> 1;
			
			int lg = log2(mid-r+1);
			pair<int, int> val = max(table[lg][r], table[lg][mid-(1 << lg)+1]);
			if(val.second-val.first+1 <= l){
				if(ans < val) ans = val;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		last = ans.first;
		cout << last << "\n";
	}
    return 0;
}

