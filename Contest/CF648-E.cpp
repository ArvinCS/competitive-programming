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

ll pw[64];

ll mostLeftBit(ll n){
	ll pos = -1;
	for(ll x=0;x<64;x++){
		if((n&(1ll << x))){
			pos = x;
		}
	}
	return pos;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	pw[0] = 1;
	pw[1] = 2;
	
	for(ll x=2;x<64;x++){
		pw[x] = 2ll*pw[x-1];
	}
	
	int n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll ans[n];
	fill(ans, ans+n, 0);
	
	ll sum = 0, bound = mostLeftBit(data[0]);
	for(int start=0;start<n;start++){		
		ans[0] = data[start];
		ll cur = ans[0];
		for(int i=1;i<n;i++){
			ll best = -1, idx = -1;
			for(int x=0;x<n;x++){
				ll cnt = data[x]-(cur&data[x]);
				if(cnt > best){
					idx = x;
					best = cnt;
				}
			}
			if(idx >= 0){
				ans[i] = data[idx];
				cur |= data[idx];
			}
		}
		
		int cnt[64];
		fill(cnt, cnt+64, 0);
		for(ll x=0;x<n;x++){
			ll best = 0;
			for(ll i=0;i<64;i++){
				if((ans[x]&pw[i])){
					cnt[i]++;
				}
				if(cnt[i] >= max(1ll, x-1)){
					best += pw[i];
				}
			}
			sum = max(sum, best);
		}
	}

	cout << sum << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

