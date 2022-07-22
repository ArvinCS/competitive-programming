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
		ll n, k;
		cin >> n >> k;
		
		ll data[n];
		for(ll x=0;x<n;x++){
			cin >> data[x];
		}
		
		ll ans = -1, cnt = 0;
		bool changed = true;
		while(changed){
			changed = false;
			for(ll x=0;x<n-1;x++){
				if(data[x] < data[x+1]){
					if(cnt+1 == k){
						ans = x+1;
					}
					cnt++;
					data[x]++;
					changed = true;
					break;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

