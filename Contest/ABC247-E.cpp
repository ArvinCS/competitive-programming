#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

struct SparseTable {
	int table[logN][maxN][2];
	
	void build(int n, int a[]){
		for(int x=0;x<n;x++){
			table[0][x][0] = table[0][x][1] = a[x];
		}
		for(int x=1;x<logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y][0] = min(table[x-1][y][0], table[x-1][y+length/2][0]);
				table[x][y][1] = max(table[x-1][y][1], table[x-1][y+length/2][1]);
			}
		}
	}
	
	pair<int, int> query(int l, int r){
		int lg = log2(r-l+1);
		int length = (1 << lg);
		
		return {min(table[lg][l][0], table[lg][r-length+1][0]), max(table[lg][l][1], table[lg][r-length+1][1])};
	}
};

SparseTable table;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, s, t;
	cin >> n >> s >> t;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	table.build(n, a);
	
	int b[n][2];
	int pos = n-1;
	for(int x=n-1;x>=0;x--){
		if(a[pos] < a[x]){
			pos = x;
		}
		b[x][1] = pos;
	}
	
	pos = 0;
	for(int x=0;x<n;x++){
		if(a[pos] < a[x]){
			pos = x;
		}
		b[x][0] = pos;
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		int left = x, right = n-1, mnLeft = x-1, mnRight = n;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid).first < t){
				mnRight = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		left = x, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid).first > t){
				mnLeft = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		int mxLeft = x-1, mxRight = n;
		left = x, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid).second > s){
				mxRight = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		left = x, right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(table.query(x, mid).second < s){
				mxLeft = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		ans += max(0ll, min(mxRight, mnRight)*1ll-max(mxLeft+1, mnLeft+1));
	}
	cout << ans << "\n";
    return 0;
}

