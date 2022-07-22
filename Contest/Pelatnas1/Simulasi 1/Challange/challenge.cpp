#include "challenge.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1005;
const int maxA = 5005;
const ll mod = 1e9 + 7;

int n;
vector<int> v, adj[maxA];
int mn = 1e9;
int ans[maxA], mx[maxA];
ll table[maxA][maxN], mul[maxA], fac[maxN], iv[maxN];
ll ways[maxA];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int dfs(int curNode){
	if(ans[curNode] != -1){
		return ans[curNode];
	}
	
	int best = 0, cnt = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != curNode){
			cnt++;
			best = max(best, dfs(nxt));
		}
	}
	
	if(cnt == 0){
		return ans[curNode] = curNode;
	}
	return ans[curNode] = best;
}

ll dfs2(int curNode, int length){
	if(table[curNode][length] != -1){
		return table[curNode][length];
	}
	
	ll cnt = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != curNode){
			if(mx[nxt] == mx[curNode]) cnt += dfs2(nxt, mul[curNode]+1);
			if(cnt >= mod) cnt -= mod;
		}
	}
	
	if(adj[curNode].size() == 0){
		return table[curNode][length] = fac[n-length] % mod;
	}
	
//	cout << curNode << " " << length << " = "  << mul << " " << fac[n-length] % mod * iv[n-length-(mul-length)] % mod << " " << cnt * fac[n-length-1] % mod * iv[n-length-1-(mul-length)] % mod << "\n";
	return table[curNode][length] = cnt * fac[n-length] % mod * iv[n-length-(mul[curNode]-length)] % mod;
}

void initialize(int N, vector<int> A) {
	n = N;
	v = A;
	fill(ans, ans+maxA, -1);
	fill(ways, ways+maxA, -1);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	for(int i=0;i<maxA;i++){
		mul[i] = 0;
		for(int x=0;x<N;x++){
			if(i < A[x]){
				mul[i]++;
			}
			if(i%A[x] != i){
				adj[i].push_back(i%A[x]);
			}
		}
	}
	
	for(int i=0;i<maxA;i++){
		ans[i] = dfs(i);
	}
	
	for(int i=0;i<maxA;i++){
		mx[i] = 0;
		for(int x=0;x<n;x++){
			mx[i] = max(mx[i], ans[i%v[x]]);
		}
	}
	
	fill(table[0], table[maxN], -1);
	for(int i=0;i<maxA;i++){
		ways[i] = dfs2(i, 0);
	}
}

int solve_challenge(int val, int t) {
	assert(t >= 0 && t <= 1);
	
	if(t == 0){ // cari nilai optimal
		return mx[val];
	} else if(t == 1){ // cari banyak konfigurasi
		int curmx = 0;
		ll cnt = 0;
		for(int x=0;x<n;x++){
			if(val%v[x] > curmx){
				curmx = val%v[x];
				cnt = 0;
			}
			if(val%v[x] == curmx){
				cnt += ways[val%v[x]];
				if(cnt >= mod) cnt -= mod;
			}
		}
		return cnt;
	}
	return -1;
}
