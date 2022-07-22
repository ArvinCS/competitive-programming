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

ll mul(ll a, ll b){
	ll ans = 0;
	a %= mod;
	
	while(b > 0){
		if(b&1) ans = (ans + a) % mod;
		
		a = (2 * a) % mod;
		b /= 2;
	}
	return ans % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		ull ans = 0;
		if(m > 1){
			for(int x=m-1;x<n;x++){
				ll bound = data[x]-k, left = 0, right = n-1, p = 0;
				while(left <= right){
					ull mid = (left+right)/2;
					if(data[mid] >= bound){
						right = mid-1;
						p = mid;
					} else {
						left = mid+1;
					}
				}
				
				if(p <= x-m+1){
					ull cnt = x-p;
					for(ull y=1;y<m-1;y++){
						cnt *= (x-p-y);
					}
					for(ull y=m-1;y>0;y--){
						cnt /= y;
					}
					ans = (ans % mod + cnt % mod) % mod;
				}
			}
		} else {
			ans = n % mod;
		} 
		
		cout << ans % mod << "\n";
	}
	
    return 0;
}

