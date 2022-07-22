#include "addition.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1000000007;
const int maxN = 2e5 + 5;

ll fac[maxN], iv[maxN];

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

ll p(int n, int r){
	if(n < r) return 0;
	assert(n >= 0 && r >= 0);
	return fac[n] * iv[n-r] % mod;
}

ll comb(int n, int r){
	if(n < r) return 0;
	assert(r >= 0 && n >= 0);
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

int count_arrangements(string A, string B, string C) {
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * 1ll * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n = A.length();
	ll rem[n], carry[n];
	fill(rem, rem+n, 0);
	fill(carry, carry+n, 0);
	
	assert(n > 1);
	
	ll cnt[2][2], zero[2][2];
	fill(cnt[0], cnt[2], 0);
	fill(zero[0], zero[2], 0);
	
	ll ans = 0;	
		
	for(int x=0;x<n;x++){
		int sum = (A[x] - '0') + (B[x] - '0');
		rem[x] = (((C[x] - '0') - sum)+1000)%10;
		carry[x] = (sum+rem[x])/10;
		
		if(rem[x] > 1) return 0;
		assert(carry[x] <= 1 && rem[x] >= 0);
		
		cnt[carry[x]][rem[x]]++;
		
		if(A[x] == '0' || B[x] == '0' || C[x] == '0'){
			zero[carry[x]][rem[x]]++;
		}
	}
	
	// ....[consecutive 0.0][consecutive 1.1][remain]
	// ....[carry 0 remain 0][carry 1 remain 1][remain]
	
	if(cnt[0][0]-zero[0][0] > 0 && cnt[0][1]-cnt[1][0] >= 0 && cnt[0][1]-cnt[1][0] <= 1){
		ll val = cnt[0][0]-zero[0][0]; // first 0
		val *= p(cnt[1][0], cnt[1][0]); // nxt 0
		val %= mod;
		
		if(cnt[1][0]+(cnt[0][0]-zero[0][0] > 0 ? 1 : 0) > 0) val *= fac[cnt[0][0]-1] * comb(cnt[0][0]-1+cnt[1][0]+1-1, cnt[1][0]+1-1) % mod; // place 0
		else if(cnt[0][0]-(cnt[0][0]-zero[0][0] > 0 ? 1 : 0) > 0) val = 0;

		val %= mod;
		
		val *= p(cnt[0][1], cnt[0][1]); // place carry 0 remain 1
		val %= mod;
				
		if(cnt[0][1] > 0) val *= fac[cnt[1][1]] * comb(cnt[1][1]+cnt[0][1]-1, cnt[0][1]-1) % mod; // place carry 1 remain 1
		else if(cnt[1][1] > 0) val = 0;
		
		val %= mod;
		
		ans += val;
		ans %= mod;
		
		assert(val >= 0);
	}
	
	if(cnt[0][1]-zero[0][1] > 0 && cnt[1][0]-cnt[0][1]+1 >= 0 && cnt[1][0]-cnt[0][1]+1 <= 1){
		ll val = cnt[0][1]-zero[0][1]; // first 1
		if(cnt[0][1] > 0) val *= p(cnt[0][1]-1, cnt[0][1]-1); // nxt 1
		val %= mod;
		
		val *= fac[cnt[1][1]] * comb(cnt[1][1]+cnt[0][1]-1, cnt[0][1]-1) % mod; // place 1
		val %= mod;
		
		val *= p(cnt[1][0], cnt[1][0]); // place carry 1 remain 0
		val %= mod;
		
		if(cnt[1][0] > 0) val *= fac[cnt[0][0]] * comb(cnt[0][0]+cnt[1][0]-1, cnt[1][0]-1) % mod; // place carry 0 remain 0
		else if(cnt[0][0] > 0) val = 0;
		
		val %= mod;
		
		ans += val;
		ans %= mod;
		
		assert(val >= 0);
	}
	
//		// 0..0..0 x times, first is carry 0 remain 0, nxt x-1 bits 0 are carry 1 remain 0
//		// case 1:
//		// means there are x bits 1 which are carry 0 remain 1, and bits 1 which are carry 1 remain 1 are free
//		// case 2:
//		// means there are x-1 bits 1 which are carry 0 remain 1, and bits 1 which are carry 1 remain 1 are free
	
	return ans % mod;
}
