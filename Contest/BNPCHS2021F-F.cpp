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

const int maxN = 1e5 + 5;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % 2;
		
		y >>= 1;
		x = (x * x) % 2;
	}
	return ans;
}

int combin(int a,int b){
	int res = 1;
	if(a == 0 || b == 0) return 1;
	for(int x=1;x<=a;x++) res *= x;
	for(int x=1;x<=b;x++) res /= x;
	for(int x=1;x<=a-b;x++) res /= x;
	return res % 2;
}

int lucas(int a,int b){
	if(b > a) return 0;
	if(a <= 2 && b <= 2) 
		return combin(a,b)%2;
		
	return lucas(a/2,b/2) * lucas(a%2,b%2) % 2; 
}

ll combin(ll p, ll r){
	if(p < r) return -1;
	return fac[p] * iv[p-r] % 2 * iv[r] % 2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		freopen("output.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(fac[1], 0);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % 2;
		iv[x] = powmod(fac[x], 0);
	}
		
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans[n+1];
	fill(ans, ans+n+1, 0);
	
	for(int x=0;x<n;x++){
		int p = m, r = x-m;
		for(int y=max(0, r);y<n-m;y++){
			int q = y-r;
			if(q < 0 || p < q) break;
						
			if(lucas(p, q) % 2 == 1){
				ans[y] ^= a[x];
			}
		}
	}
	
	for(int x=0;x<n-m;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
	
    return 0;
}

