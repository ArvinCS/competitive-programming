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

ll table[64];
ll n, k;
ll solve(int idx, ll val, bool less){
	if(idx == 0){
		if(k == 1) return n;
		else return 0;
	}
	
	ll bit = (1ll << idx);
	ll cur = (val|(bit-1))^(bit-1);
	ll mx = ((cur|bit)^bit)|((1ll << (idx+(val&bit?0:1)))-1);
	ll cnt = min(mx, n)-cur+1 + ((1ll << (idx)) - (val&bit?1:0));
	
	cout << idx << " " << val << " " << cnt << " " << cur/bit << " " << mx << " " << cur << "\n";
	ll ans = 0;
	if(cnt >= k) ans = cur/bit;
	if(!less) ans = max(ans, solve(idx, val^(1ll << idx), true));
	ans = max(ans, solve(idx-1, val, less));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> k;
	
//	ll cur = 1;
//	while(cur < k){
//		n--;
//	}
//	
//	cout << n << "\n";
	
	map<int, int> mp;
	for(int x=1;x<=n;x++){
		int cur = x;
		
		while(cur > 0){
			mp[cur]++;
			
			if(cur%2 == 0) cur /= 2;
			else cur--;
		}
	}
	
	int cur = n;
	while(cur > 0){
//		cout << cur << " -> " << mp[cur] << "\n";
		
		if(cur%2 == 0) cur /= 2;
			else cur--;
	}
	for(auto p : mp){
		cout << p.first << " -> " << p.second << "\n";
	}
	
	cout << solve(2, n, false) << "\n";
    return 0;
}

