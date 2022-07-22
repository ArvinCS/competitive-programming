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
	
	int n, q;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++) cin >> data[x];

	cin >> q;
	
	sort(data, data+n);
	
	for(int x=0;x<q;x++){
		ll m;
		cin >> m;
		
		int ans = 0;
		int left = 0, right = n-1;
		while(left <= right){
			int mid = (left+right)/2;
			
			if(data[mid] <= m && (mid+1 == n || data[mid+1] > m)){
				ans = mid+1;
				break;
			} else if(data[mid] > m){
				right = mid-1;
			} else {
				left = mid+1;
			}
		}	
		
		cout << ans << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

