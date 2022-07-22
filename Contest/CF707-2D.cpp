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

inline long long normalize(ll x, ll m) { x %= m; if (x < 0) x += m; return x; }

struct GCD_type {
	ll x, y, d;
};

GCD_type ex_GCD(ll a, ll b){
    if (b == 0) return {1, 0, a};
    
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

const int maxN = 5e5 + 5;

ll a[maxN], b[maxN], pos[2*maxN];

ll crt(ll x, ll n, ll y, ll m){ // x (mod n), y (mod m)
	ll ans = x, lcm = n;
	
//	cout << x << " " << n << " " << y << " " << m << "\n";
	auto pom = ex_GCD(lcm, m);
	ll x1 = pom.x, d = pom.d;
	
//	cout << x1 << " " << d << "\n";
	if((y-ans) % d != 0) return -1;
	
	ans = normalize(ans + x1 * (y - ans) / d % (m / d) * lcm, lcm * m / d);
	lcm = (lcm*y)/__gcd(lcm, y);
    
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m, k;
	cin >> n >> m >> k;
	
	int sz = max(n,m);
	ll lcm = (n*m)/__gcd(n, m);
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	if(m > n){
		swap(a, b);
		swap(n, m);
	}
	
	fill(pos, pos+2*sz+5, -1);
	for(int x=0;x<n;x++){
		pos[a[x]] = x;
	}
	
	vector<ll> v;
	for(int x=0;x<m;x++){
		if(pos[b[x]] == -1) continue;
		
//		cout << x << ":\n";
		ll meet = crt(normalize(pos[b[x]]+1, n), n, normalize(x+1, m), m);
		if(meet >= 0){
			if(meet == 0) meet = n;
			
//			cout << x << " -> " << meet << "\n";
			v.push_back(meet-1);
		}
	}
	
	sort(v.begin(), v.end());
	ll bad = lcm-v.size();
	ll order = (k-1)%bad + 1;
	
//	cout << bad << " " << order << " " << lcm << "\n";
	ll cur = 0, cnt = 0;
	for(auto good : v){
		ll space = good-cur;
		
//		cout << cur << " " << cnt << " " << good << " -> " << space << "\n";
		if(cnt < order && order <= cnt+space){
			cout << (k-1)/bad * lcm + cur + (order-cnt) << "\n";
			return 0;
		}
		
		cnt += space;
		cur = good+1;
	}
	
	ll space = lcm-cur;
//	cout << space << "--\n";
	if(cnt < order && order <= cnt+space){
		cout << (k-1)/bad * lcm + cur + (order-cnt) << "\n";
	}
	
    return 0;
}

