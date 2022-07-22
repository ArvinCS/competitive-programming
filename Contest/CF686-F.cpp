#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

ll table[logN+1][maxN];
ll a[maxN];

void build(int n){
	for(int x=0;x<n;x++){
		table[0][x] = a[x];
	}	
	
	for(int x=1;x<=logN;x++){
		int length = (1 << x);
		for(int y=0;y+length<=n;y++){
			table[x][y] = min(table[x-1][y], table[x-1][y+length/2]);
		}
	}
}

ll query(int left, int right){
	int logL = log2(right-left+1);
	int length = (1 << logL);
	
	return min(table[logL][left], table[logL][right-length+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		build(n);
		
		ll suffix[n];
		for(int x=n-1;x>=0;x--){
			suffix[x] = max(a[x], (x+1 < n ? suffix[x+1] : 0));
		}
		
		bool found = false;
		
		ll mx = 0;
		for(int x=0;x+2<n;x++){
			mx = max(mx, a[x]);
			
			int left = x+1, right = n-2;
			int boundLeft = n, boundRight = -1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(query(x+1, mid) > mx){
					left = mid+1;
				} else {
					if(query(x+1, mid) == mx) boundLeft = min(boundLeft, mid);
					right = mid-1;
				}
			}
			
			left = x+1; right = n-2;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(query(x+1, mid) >= mx){
					left = mid+1;
					if(query(x+1, mid) == mx) boundRight = max(boundRight, mid);
				} else {
					right = mid-1;
				}
			}
			
			if(boundRight == -1) continue;
			
			int y = -1;
			left = boundLeft+1, right = min(boundRight+1, n-1);
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(suffix[mid] > mx){
					left = mid+1;
				} else {
					if(suffix[mid] == mx){
						y = mid;
						break;
					}
					right = mid-1;
				}
			}
			if(y == -1) continue;
			
			cout << "YES\n";
			cout << x+1 << " " << (y-x-1) << " " << (n-y) << "\n";
			found = true;
			break;
		}
		
		if(!found) cout << "NO\n";
	}

    return 0;
}

