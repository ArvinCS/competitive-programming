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

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

const int maxN = 3e5 + 5;

ll tree[maxN];

void update(int pos, ll val){
	pos++;
	
	while(pos < maxN){
		tree[pos] += val;
		tree[pos] %= smod;
		
		pos += pos&(-pos);
	}
}

ll query(int pos){
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos];
		ans %= smod;
		
		pos -= pos&(-pos);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
	}
	
	fill(tree, tree+maxN, 0);
	
	ll ans = 0, cur = 1;
	for(int x=0;x<n;x++){
		ll cnt = query(a[x]) * cur;
		cnt %= smod;
		
		ans += cnt;
		ans %= smod;
		
		cur *= 2;
		cur %= smod;
		
		update(a[x], powmod(cur, smod-2));
	}
	
	cout << ans << "\n";
    return 0;
}
