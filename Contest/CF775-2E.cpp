#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxS = 2e5 + 5;
const int maxN = 2e5 + 5;

struct SegmentTreeAdd {
	ll tree[2*maxS];
	
	void reset(int val1, int val2){
		for(int x=0;x<maxS;x++){
			tree[x+maxS] = val1;
			tree[x] = val2;
		}
	}
	
	void update(int pos, ll val){
		pos += maxS;
		
		tree[pos] += val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = (tree[x] + tree[x^1]) % mod;
		}
	}
	
	ll query(int left, int right){
		ll ans = 0;
		
		for(left += maxS, right += maxS; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans += tree[left];
				ans %= mod;
				left++;
			}
			if(right&1){
				--right;
				ans += tree[right];
				ans %= mod;
			}
		}
		return ans % mod;
	}
};

struct SegmentTreeMul {
	ll tree[2*maxS];
	
	void reset(int val1, int val2){
		for(int x=0;x<maxS;x++){
			tree[x+maxS] = val1;
			tree[x] = val2;
		}
	}
	
	void update(int pos, ll val){
		pos += maxS;
		
		tree[pos] = val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = (tree[x] * tree[x^1]) % mod;
		}
	}
	
	ll query(int left, int right){
		ll ans = 1;
		
		for(left += maxS, right += maxS; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans *= tree[left];
				ans %= mod;
				left++;
			}
			if(right&1){
				--right;
				ans *= tree[right];
				ans %= mod;
			}
		}
		return ans % mod;
	}
};

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

ll cnt[maxS];
ll fac[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
	}
	
	int n, m;
	cin >> n >> m;
	
	int s[n], t[m];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	for(int x=0;x<m;x++){
		cin >> t[x];
	}
	
	SegmentTreeAdd sum;
	SegmentTreeMul mul;
	
	mul.reset(1, 1);
	sum.reset(0, 0);
	
	
	fill(cnt, cnt+maxS, 0);
	
	for(int x=0;x<n;x++){
		cnt[s[x]]++;
	}
	for(int x=1;x<maxS;x++){
	    mul.update(x, fac[cnt[x]]);
		sum.update(x, cnt[x]);
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(x >= m) break;
		
		ans += sum.query(1, t[x]) * fac[n-x-1] % mod * powmod(mul.query(1, maxS), mod-2) % mod;
		ans %= mod;
		
// 		cout << x << " -> " << ans << " " << sum.query(1, t[x]) << " " << fac[n-x-1] << " " << mul.query(1, maxS) << "\n";
		if(sum.query(t[x], t[x]+1) <= 0){
			break;
		}
		
		mul.update(t[x], fac[sum.query(t[x], t[x]+1)-1]);
		sum.update(t[x], -1);
		
		if(x == n-1 & n < m){
		    ans++;
		    ans %= mod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

