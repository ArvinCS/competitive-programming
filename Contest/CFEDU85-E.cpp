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

const ll logD = 2e5 + 5;

vector<ll> v, w;
ll fac[logD], iv[logD];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(fac[1], smod-2);
	
	for(int x=2;x<logD;x++){
		fac[x] = (x * fac[x-1]) % smod;
		iv[x] = powmod(fac[x], smod-2);
	}
	
	ll d;
	cin >> d;
	
	for(ll x=1;x*x<=d;x++){
		if(d % x == 0){
			v.push_back(x);
			if(d/x != x) v.push_back(d/x);
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int x=1;x<v.size();x++){
		bool prime = true;
		for(int y=0;y<w.size();y++){
			if(v[x]%w[y] == 0){
				prime = false;
				break;
			}
		}
		
		if(prime){
			w.push_back(v[x]);
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		ll a, b;
		cin >> a >> b;
		
		if(a > b) swap(a, b);
		
		ll gc = __gcd(a, b);
		
		b = b / gc;
		a = a / gc;
		
		int sumA = 0, sumB = 0;
		ll divA = 1, divB = 1;
		
		for(int i=0;i<w.size();i++){
			int cnt = 0;
			while(a > 0 && a%w[i] == 0){
				a /= w[i];
				cnt++;
			}
			if(cnt > 0){
				sumA += cnt;
				divA *= iv[cnt];
				divA %= smod;
			}
			
			cnt = 0;
			while(b > 0 && b%w[i] == 0){
				b /= w[i];
				cnt++;
			}
			if(cnt > 0){
				sumB += cnt;
				divB *= iv[cnt];
				divB %= smod;
			}
		}
		
		cout << fac[sumA] * divA % smod * fac[sumB] % smod * divB % smod << "\n";
	}

    return 0;
}

