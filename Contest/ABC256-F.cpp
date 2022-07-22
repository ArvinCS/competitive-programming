#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int mod = 998244353;
const int div2 = 499122177;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void chadd(ll &a, ll b){
	if(b >= mod) b -= mod;
	if(b < 0) b += mod;
	
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

struct Fenwick {
	ll tree[maxN];
	
	void reset(int n = maxN){
		fill(tree, tree+n, 0);
	}		
	
	void update(int pos, ll val){
		pos++;
		
		while(pos < maxN){
			chadd(tree[pos], val);
			pos += pos&(-pos);
		}
	}
	
	ll query(int pos){
		ll ans = 0;
		pos++;
		
		while(pos > 0){
			chadd(ans, tree[pos]);
			pos -= pos&(-pos);
		}
		return ans;
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		b[x] = a[x];
	}
	
	tree.reset();
	
	ll cur[n];
	for(int x=0;x<n;x++){
		cur[x] = a[x];
	}
	for(int i=0;i<3;i++){
		ll sum = 0;
		for(int x=0;x<n;x++){
			chadd(sum, cur[x]);
			cur[x] = sum;
		}
	}
	
	unordered_set<int> st;
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		
		if(st.size() >= 450){ // O(sqrtQ.N)
			for(int x=0;x<n;x++){
				a[x] = b[x];
				cur[x] = a[x];
			}
			for(int i=0;i<3;i++){
				ll sum = 0;
				for(int x=0;x<n;x++){
					chadd(sum, cur[x]);
					cur[x] = sum;
				}
			}
			st.clear();
		}
		
		if(t == 1){ // O(Q)
			int pos;
			ll v;
			cin >> pos >> v;
			
			pos--;
			b[pos] = v;
			st.insert(pos);
		} else if(t == 2){ // O(QsqrtQ)
			int pos;
			cin >> pos;
			
			pos--;
			ll ans = cur[pos];
			for(auto idx : st){
				if(idx <= pos){
					ll l = (pos-idx+1) % mod;
					chadd(ans, l*(l+1) % mod * ((b[idx]-a[idx]+mod) % mod) % mod * div2 % mod);
				}
			}
			
			cout << ans << "\n";
		} else {
			assert(false);
		}
	}
    return 0;
}

