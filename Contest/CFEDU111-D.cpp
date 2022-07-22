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

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

ll combin(ll n, ll r){
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n, l, r;
		cin >> n >> l >> r;
		
		vector<int> v, w;
		for(int x=n;x>=1;x--){
			v.push_back(r-x);
		}
		for(int x=1;x<=n;x++){
			w.push_back(x-l);
		}
		
		int left = 1, right = max(-l, r), pos = 0;
		while(left <= right){ // finding bound so time complexity become O(NlogN + log^2N)
			ll mid = (left+right) >> 1;
			
			int p = (lower_bound(w.begin(), w.end(), mid) - w.begin());
			int q = n-(lower_bound(v.begin(), v.end(), mid) - v.begin());	
			
			if(q < p || n-p < n-q){ // number that fixed to add || number that fixed to subtract
				right = mid-1;
				continue;
			}
			
			int mustAdd = p, mustSub = n-q;
			if(mustAdd <= (n+1)/2 && mustSub <= (n+1)/2){
				pos = max(pos, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		ll ans = 0;
		int p = n;
		for(int x=pos;x>0;x--){
			int q = n - (lower_bound(v.begin(), v.end(), x) - v.begin());
			while(p > 0 && p-x >= l){
				p--;
			}
			
			if(q < p || n-p < n-q){ // number that fixed to add || number that fixed to subtract
				continue;
			}
			
			int mustAdd = p, mustSub = n-q;
			
			ll cnt = 0;
			if(mustAdd <= n/2 && mustSub <= (n+1)/2){
				cnt += combin(n-mustAdd-mustSub, n/2-mustAdd);
			}
			cnt %= mod;
			if(n % 2 == 1 && mustAdd <= (n+1)/2 && mustSub <= n/2){
				cnt += combin(n-mustAdd-mustSub, (n+1)/2-mustAdd);
			}
			cnt %= mod;
			
			if(mustAdd == 0 && mustSub == 0){
				ans += cnt*x % mod;
				ans %= mod;
				break;
			} else {
				ans += cnt;
				ans %= mod;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

