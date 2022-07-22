#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
	
	while(t--){
		int n, m, a, b, c, d;
		ll p;
		cin >> n >> m >> a >> b >> c >> d >> p;
		
		bool valid[4*n*m];
		fill(valid, valid+4*n*m, false);
		
		set<tuple<int, int, int, int>> visited;
		int cnt = 0, moveX = 1, moveY = 1;
		while(true){
			if(a == c || b == d){
				valid[cnt] = true;
			}
			
			if(a+moveX <= 0 || a+moveX > n){
				moveX *= -1;
			}
			if(b+moveY <= 0 || b+moveY > m){
				moveY *= -1;
			}
			
			if(visited.count(make_tuple(a, b, moveX, moveY))){
				break;
			}
			visited.insert(make_tuple(a, b, moveX, moveY));
			
			a += moveX;
			b += moveY;
			
			cnt++;
		}
		cnt--;
		
		ll q = (100 - p) * powmod(100, mod-2) % mod;
		p *= powmod(100, mod-2);
		p %= mod;
		
		ll ans = 0;
		ll prob = 1;
		
		for(int x=0;x<=cnt;x++){
			if(valid[(x == cnt ? 0 : x+1)]){
				ans += prob * p % mod * x % mod;
				ans %= mod;
				
				prob *= q;
				prob %= mod;
			}
		}
		
//		cout << cnt << " " << ans << "\n";
		cout << ((ans + prob*(cnt+1) % mod) % mod * powmod((1-prob+mod)%mod, mod-2) % mod + 1) % mod * (a == c || b == d ? q : 1) % mod << "\n";
	}
    return 0;
}

