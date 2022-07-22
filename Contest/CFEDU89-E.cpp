#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 2e5 + 5;
const int logN = log2(maxN);

int table[logN+1][maxN];

int query(int left, int right){
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return min(table[lg][left], table[lg][right-length+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
		table[0][x] = a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	for(int x=1;x<=logN;x++){
		int length = (1 << x);
		for(int y=0;y+length<=n;y++){
			table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
		}
	}
	
	map<int, int> mp;
	for(int x=0;x<n;x++){
		mp[a[x]] = x;
	}
	
	for(int x=0;x<m;x++){
		if(mp.find(b[x]) == mp.end()){
			cout << "0\n";
			return 0;
		}
	}
	
	int left[m], right[m];
	fill(left, left+m, inf_int);
	fill(right, right+m, 0);
	
	for(int x=0;x<m;x++){
		int pos = mp[b[x]];
		
		int l = 0, r = pos;
		while(l <= r){
			int mid = (l+r) >> 1;
			
			if(query(mid, pos) >= b[x]){
				left[x] = min(left[x], mid);
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		
		l = pos, r = n-1;
		while(l <= r){
			int mid = (l+r) >> 1;
			
			if(query(pos, mid) >= b[x]){
				right[x] = max(right[x], mid);
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
	}
	
	if(left[0] != 0 || right[m-1] != n-1){
		cout << "0\n";
		return 0;
	}
	
	ll ans = 1;
	for(int x=0;x+1<m;x++){
		if(right[x] < left[x+1]-1 || mp[b[x]] > mp[b[x+1]]){
			cout << "0\n";
			return 0;
		}
		
		ans *= (min(right[x], mp[b[x+1]]-1)-max(mp[b[x]], left[x+1]-1)+1);
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

