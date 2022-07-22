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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int a[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}

	int left = 1, right = 1e9;
	int ans1 = 0, ans2 = 0, mx = -1;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		int pos[600];
		fill(pos, pos+600, -1);
		
		for(int x=0;x<n;x++){
			int mask = 0;
			for(int y=0;y<m;y++){
				if(a[x][y] >= mid){
					mask += (1 << y);
				}
			}
			
			pos[mask] = x;
//			cout << mid << " " << x << " -> " << mask << "\n";
		}
		
		bool found = false;
		int a = -1, b = -1;
		for(int x=0;x<(1 << m);x++){
			for(int y=0;y<(1 << m);y++){
				if(pos[x] != -1 && pos[y] != -1 && (x|y) == ((1 << m)-1)){
	//				cout << pos[x] << " " << pos[y] << "\n";
					found = true;
					a = pos[x];
					b = pos[y];
					break;
				}
			}
		}
		
		if(found){
			if(mid > mx){
				mx = mid;
				ans1 = a;
				ans2 = b;
			}
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans1+1 << " " << ans2+1 << "\n";
    return 0;
}

