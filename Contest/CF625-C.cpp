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

const ll INF = 1e18;
const int maxVal = 1e6 + 5;

struct Monster {
	int attack, defense, coin;
	
	bool operator <(Monster &b) const {
		if(defense == b.defense){
			if(coin == b.coin){
				return attack < b.attack;
			}
			return coin > b.coin;
		}
		return defense < b.defense;
	}
};

struct SegTree { // index start from 0 (v)
	ll tree[4*maxVal+5], lazy[4*maxVal+5];
	
	int n;
	void resize(int n){
		this->n = n;
		fill(tree, tree+4*n+5, 0);
		fill(lazy, lazy+4*n+5, 0);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = max(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return -inf_ll;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m, p;
	cin >> n >> m >> p;
	
	pair<int, ll> a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x].first >> a[x].second;
	}
	for(int x=0;x<m;x++){
		cin >> b[x].first >> b[x].second;
	}
	
	sort(a, a+n);
	sort(b, b+m);
	
	ll suffixA[n], suffixB[m];
	for(int x=n-1;x>=0;x--){
		suffixA[x] = min((x+1 < n ? suffixA[x+1] : INF), a[x].second);
	}
	for(int x=m-1;x>=0;x--){
		suffixB[x] = min((x+1 < m ? suffixB[x+1] : INF), b[x].second);
	}
	
	Monster t[p];
	for(int x=0;x<p;x++){
		cin >> t[x].defense >> t[x].attack >> t[x].coin;
	}
	
	sort(t, t+p);
	
	tree.resize(maxVal);
	
	for(int x=b[m-1].first-1;x>=0;x--){
		int idx = lower_bound(b, b+m, make_pair(x+1, -1ll)) - b;
		tree.update(0, 0, maxVal, x, x, -suffixB[idx]);
	}
		
	ll ans = tree.query(0, 0, maxVal, 0, b[m-1].first-1)-suffixA[0];
	for(int x=0;x<p;x++){
		if(a[n-1].first <= t[x].defense) break;
		
		tree.update(0, 0, maxVal, t[x].attack, maxVal, t[x].coin);
		
		ll cost = suffixA[(lower_bound(a, a+n, make_pair(t[x].defense+1, -1ll)) - a)];
		
		ans = max(ans, tree.query(0, 0, maxVal, 0, b[m-1].first-1)-cost);
	}
	cout << ans << "\n";
	
    return 0;
}

