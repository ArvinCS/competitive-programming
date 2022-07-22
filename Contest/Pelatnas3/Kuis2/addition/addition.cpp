#include <bits/stdc++.h>
#include "addition.h"

using namespace std;

#define ll long long

const ll mod = 998244353;

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

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int count_addition(std::vector<std::string> S, int X) {
	int N = S.size();
	int K = S[0].size();
	
	ll pw2[X*K+1];
	pw2[0] = 1;
	for(int x=1;x<=X*K;x++){
		pw2[x] = (2ll * pw2[x-1]) % mod;
	}
	
	if(N <= 5000 || K > 60){
		ll val[N][(K+59)/60];
		for(int x=0;x<N;x++){
			for(int y=0;y<(K+59)/60;y++){
				val[x][y] = 0;
				for(int z=0;z<min(60, K-y*60);z++){
					if(S[x][y*60+z] == '1'){
						val[x][y] += (1ll << z);
					}
				}
			}
		}
		
		ll ans = 0;
		for(int x=0;x<N;x++){
			for(int y=x+1;y<N;y++){
				ll res = 0;
				for(int z=0;z<(K+59)/60;z++){
					res += (val[x][z] ^ val[y][z]) % mod * pw2[60*z] % mod;
					if(res >= mod) res -= mod;
				}
				
				ll cur = 1;
				for(int y=1;y<=X;y++){
					cur *= res;
					cur %= mod;
				}
				
				ans += cur;
				if(ans >= mod) ans -= mod;
			}
		}
		
		return ans;
	} else {
		ll ans = 0;
		if(X == 1){
			for(int x=0;x<K;x++){
				int one = 0, zero = 0;
				for(int y=0;y<N;y++){
					if(S[y][x] == '1') one++;
					else zero++;
				}
				
				chadd(ans, one * 1ll * zero % mod * pw2[x] % mod);
			}
		} else if(X == 2){
			for(int x=0;x<K;x++){
				int one = 0, zero = 0;
				for(int y=0;y<N;y++){
					if(S[y][x] == '1') one++;
					else zero++;
				}
				
				chadd(ans, one * 1ll * zero % mod * pw2[2*x] % mod);
			}
			
			for(int x=0;x<K;x++){
				for(int y=x+1;y<K;y++){
					if(x == y) continue;
					
					int cnt[2][2];
					fill(cnt[0], cnt[2], 0);
					
					for(int z=0;z<N;z++){
						cnt[(S[z][x] == '1' ? 1 : 0)][(S[z][y] == '1' ? 1 : 0)]++;	
					}
					
					chadd(ans, cnt[1][1] * 1ll * cnt[0][0] % mod * pw2[x+y] % mod * 2 % mod);
					chadd(ans, cnt[1][0] * 1ll * cnt[0][1] % mod * pw2[x+y] % mod * 2 % mod);
				}
			}
		} else if(X == 3){
			for(int x=0;x<K;x++){
				int one = 0, zero = 0;
				for(int y=0;y<N;y++){
					if(S[y][x] == '1') one++;
					else zero++;
				}
				
				chadd(ans, one * 1ll * zero % mod * pw2[3*x] % mod);
			}
			
			for(int x=0;x<K;x++){
				for(int y=x+1;y<K;y++){
					int cnt[2][2];
					fill(cnt[0], cnt[2], 0);
					
					for(int z=0;z<N;z++){
						cnt[(S[z][x] == '1' ? 1 : 0)][(S[z][y] == '1' ? 1 : 0)]++;	
					}
					
					chadd(ans, cnt[1][1] * 1ll * cnt[0][0] % mod * pw2[2*x+y] % mod * 3 % mod);
					chadd(ans, cnt[1][1] * 1ll * cnt[0][0] % mod * pw2[x+2*y] % mod * 3 % mod);
					
					chadd(ans, cnt[1][0] * 1ll * cnt[0][1] % mod * pw2[2*x+y] % mod * 3 % mod);
					chadd(ans, cnt[1][0] * 1ll * cnt[0][1] % mod * pw2[x+2*y] % mod * 3 % mod);
				}
			}
			
			for(int x=0;x<K;x++){
				for(int y=x+1;y<K;y++){
					for(int z=y+1;z<K;z++){
						int cnt[2][2][2];
						for(int a=0;a<2;a++){
							for(int b=0;b<2;b++){
								for(int c=0;c<2;c++){
									cnt[a][b][c] = 0;
								}
							}
						}
						
						for(int i=0;i<N;i++){
							cnt[(S[i][x] == '1' ? 1 : 0)][(S[i][y] == '1' ? 1 : 0)][(S[i][z] == '1' ? 1 : 0)]++;	
						}
						
						for(int a=0;a<8;a++){
							int b = (7^a);
							if(a <= b){
								chadd(ans, cnt[a&1][((a&2) != 0)][((a&4) != 0)] * 1ll * cnt[b&1][((b&2) != 0)][((b&4) != 0)] * pw2[x+y+z] % mod * 6 % mod);
							}
						}
					}
				}
			}
		}
		return ans;
	}
	
	assert(false);
} 
