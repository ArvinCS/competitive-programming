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

const int maxM = 2e5 + 5;

ll tree[maxM][2];

void update(int pos, ll val, int id){
	pos++;
	
	while(pos < maxM){
		tree[pos][id] += val;
		pos += pos&(-pos);
	}
}

ll query(int pos, int id){
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos][id];
		pos -= pos&(-pos);
	}
	return ans;
}

struct Plan {
	int l, r;
	ll c, p;
	
	operator <(const Plan &b) const {
		if(p == b.p){
			return c > b.c;
		}
		return p < b.p;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k, m;
	cin >> n >> k >> m;
	
	Plan p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].l >> p[x].r >> p[x].c >> p[x].p;
	}
	
	sort(p, p+m);
	
	vector<pair<ll, int>> v;
	for(int x=0;x<m;x++){
		v.push_back({p[x].l-1, x});
		v.push_back({p[x].r, x});
	}
	
	bool active[m];
	fill(active, active+m, false);
	fill(tree[0], tree[maxM], 0);
	
	sort(v.begin(), v.end());
	
	ll ans = 0;
	ll pos = 0;
	for(int x=0;x<n;x++){
		while(pos < v.size() && v[pos].first == x){
			int idx = v[pos].second;
			
			if(active[idx]){
				update(idx, -p[idx].c, 0);
				update(idx, -(p[idx].p*p[idx].c), 1);
			} else {
				update(idx, p[idx].c, 0);
				update(idx, p[idx].p*p[idx].c, 1);
			}
			
			active[idx] ^= 1;
			pos++;
		}
		
		int left = 0, right = m-1, bound = m-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(query(mid, 0) >= k){
				bound = min(bound, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		ll cost = query(bound, 1);
		ll remain = query(bound, 0)-k;
		if(remain > 0){
			cost -= p[bound].p*remain;
		}
		
		ans += cost;
	}
	
	cout << ans << "\n";
    return 0;
}

