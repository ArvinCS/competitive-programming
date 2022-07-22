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

const int maxN = 2e5 + 5;

ll n, tree[2*maxN][2];

void build(){
	fill(tree[0], tree[2*maxN], 0);
}

void update(ll pos, ll val, ll cnt){
	pos += n;
	tree[pos][0] += val;
	tree[pos][1] += cnt;
	
	for(int x=pos;x>1;x>>=1){
		tree[x>>1][0] = tree[x][0] + tree[x^1][0];
		tree[x>>1][1] = tree[x][1] + tree[x^1][1];
	}
}

pair<ll, ll> query(int l, int r){ // [l, r)
	pair<ll, ll> ans = {0, 0};
	
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1){
			ans.first += tree[l][0];
			ans.second += tree[l][1];
			l++;
		}
		if(r&1){
			--r;
			ans.first += tree[r][0];
			ans.second += tree[r][1];
		}
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
	
	pair<int, int> point[n];
	for(int x=0;x<n;x++){
		cin >> point[x].first;
	}
	
	set<ll> st;
	for(int x=0;x<n;x++){
		cin >> point[x].second;
		st.insert(point[x].second);
	}
	
	int cnt = 0;
	map<ll, ll> mp;
	for(auto it=st.begin();it!=st.end();it++){
		mp[*it] = cnt++;
	}
	
	sort(point, point+n);
	build();
	
	for(int x=0;x<n;x++){
		point[x].second = mp[point[x].second];
	}
	
	update(point[0].second, point[0].first, 1);
		
	ll ans = 0;
	for(int x=1;x<n;x++){
		pair<ll, ll> tmp = query(0, point[x].second+1);
		ll dist = tmp.second*point[x].first - tmp.first;
		ans += dist;
		
		update(point[x].second, point[x].first, 1);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

