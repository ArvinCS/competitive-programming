#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 2e5 + 5;

int n;
ll tree[2*maxN];

void update(int pos, ll val){
	pos += n;
	
	tree[pos] = val % mod;
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = (tree[x]+tree[x^1]) % mod;
	}
}

ll query(int left, int right){
	ll ans = 0;
	
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
		if(left&1) ans += tree[left++];
		if(right&1) ans += tree[--right];
		ans %= mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	pair<ll, ll> p[n+1];
	bool active[n+1];
	vector<ll> v;
	
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second >> active[x];
		v.push_back(p[x].first);
	}
	
	p[n] = {p[n-1].first+1, p[n-1].first+1};
	active[n] = true;
	
	fill(tree, tree+2*maxN, 0);
	
	ll ans = 0;
	ll last = 0;
	for(int x=0;x<=n;x++){
		ll dist = (p[x].first - last) % mod;
		
		int low = lower_bound(v.begin(), v.end(), p[x].second) - v.begin();
		ll need = (query(low, x) + (p[x].first - p[x].second)) % mod;
		
		if(active[x]){
			ans += need+dist;
			ans %= mod;
			last = p[x].first;
		}
		
		update(x, need);
	}
	
	cout << ans << "\n";
    return 0;
}

