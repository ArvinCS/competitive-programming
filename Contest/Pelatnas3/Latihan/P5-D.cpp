#include <bits/stdc++.h>

using namespace std;

#define ll long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int maxN = 7505;

class FastMod {
	private:
		using ull = unsigned long long;
		using L = __uint128_t;
		ull b, m;

 public:
  FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
  ull reduce(ull a) {
    ull q = (ull)((L(m) * a) >> 64);
    ull r = a - q * b;
    return r >= b ? r - b : r;
  }
};

FastMod f2(2);
int m;

void madd(int &a, int b){
	if(b >= m) b -= m;
	if(b < 0) b += m;
	
	a += b;
	if(a >= m) a -= m;
	if(a < 0) a += m;
}

ll powmod(int a, int b){
	ll ans = 1;
	
	if(a >= m) a -= m;
	if(a < 0) a += m;
	
	while(b > 0){
		if(b&1) ans = f2.reduce(ans * 1ll * a);
		
		b >>= 1;
		a = f2.reduce(a * 1ll * a);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n >> m;
	
	int fac[n+1], c[n+1][n+1];
	int dp[n+1], dp2[n+1];
	int ways[n+1];
	
	FastMod f(m-1);
	f2 = FastMod(m);
	fill(c[0], c[n+1], 0);
	
	m--;
	
	fac[0] = fac[1] = 1;
	for(int x=2;x<=n;x++){
		fac[x] = f.reduce(x * 1ll * fac[x-1]);
	}
	
	c[0][0] = 1;
	c[1][0] = c[1][1] = 1;
	for(int x=2;x<=n;x++){
		c[x][0] = c[x][x] = 1;
		for(int y=1;y<x;y++){
			c[x][y] = (c[x-1][y-1] + c[x-1][y]);
			if(c[x][y] >= m) c[x][y] -= m;
		}
	}
	
	ll ans = 1;
	for(int d=n;d>=2;d--){
		int mn = n/d;
		for(int x=0;x<=mn;x++){ // O(N/D * N/D)
			dp[x] = (x == 0);
			for(int y=1;y<=x;y++){
				madd(dp[x], f.reduce(f.reduce(dp[x-y] * 1ll * c[x*d-1][y*d-1]) * 1ll * fac[y*d-1]));
			}
		}
		
		for(int x=mn;x>=0;x--){
			dp2[x] = fac[n-x*d];
			
			for(int y=x+1;y<=mn;y++){
				madd(dp2[x], -(f.reduce(f.reduce(dp2[y] * 1ll * dp[y-x]) * 1ll * c[n-x*d][n-y*d])));
			}
		}
		
		ways[d] = fac[n];
		madd(ways[d], -dp2[0]);

		for(int y=2;y<=mn;y++){
			madd(ways[d], -ways[y*d]);
		}

		ans = f2.reduce(ans * powmod(d, ways[d]));
	}
	
	cout << ans << "\n";
    return 0;
}

