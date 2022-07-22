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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll l, r;
		cin >> l >> r;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		ll ans = 0;
		for(int x=1;x<n;x++){
			ll left = 0, right = x-1, leftBound = x, rightBound = -1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(data[x]+data[mid] >= l){
					right = mid-1;
					leftBound = mid;
				} else {
					left = mid+1;
				}
			}
			
			left = 0, right = x-1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(data[x]+data[mid] <= r){
					left = mid+1;
					rightBound = mid;
				} else {
					right = mid-1;
				}
			}
			
//			cout << leftBound << " " << rightBound << "\n";
			ans += max(rightBound-leftBound+1, 0ll);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}



