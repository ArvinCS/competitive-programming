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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		ull ans = 0;
		
		for(int x=2;x<n;x++){
			ll bound = data[x]-2, left = 0, right = n-1, p = 0;
			while(left <= right){
				ull mid = (left+right)/2;
				if(data[mid] >= bound){
					right = mid-1;
					p = mid;
				} else {
					left = mid+1;
				}
			}
			
			if(p <= x-2){
				ans += (x-p) * (x-p-1) / 2;
			}
//			cout << ans << "\n";
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

