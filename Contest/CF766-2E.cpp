#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxK = 3e5 + 5;

struct SegTree { // index start from 0 (v)
	ll tree[4*maxK], lazy[4*maxK];

	void reset(int k){
		fill(tree, tree+4*k, 0);
		fill(lazy, lazy+4*k, 0);
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
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 1e18;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

vector<pair<int, int>> v[maxK];
SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		for(int x=0;x<=n;x++){
			v[x].clear();
		}
		
		ll a[n+1];
		for(int x=1;x<=n;x++){
			cin >> a[x];
		}
		
		int b[k+2], d[k+2];
		ll h[k+2];
		b[0] = d[0] = h[0] = 0;
		b[k+1] = m; d[k+1] = m; h[k+1] = 0;
		for(int x=1;x<=k;x++){
			int a, c;
			cin >> a >> b[x] >> c >> d[x] >> h[x];
			
			v[a].push_back({b[x], -x});
			v[c].push_back({d[x], x});
		}
		
		v[n].push_back({b[k+1], -(k+1)});
		v[1].push_back({1, 0});
		
		int sz = 0;
		for(int x=1;x<=n;x++){
			sz += v[x].size();
			if(!v[x].empty()) sort(v[x].begin(), v[x].end());
		}
		
		tree.reset(sz);
		
		ll dist[k+2];
		fill(dist, dist+k+2, 1e18);
		
		dist[0] = 0;
		
		int last = -1;
		for(int x=1;x<=n;x++){			
			int l = last+1, r = last;
			int cnt = 0;
			for(int y=0;y<v[x].size();y++){
				if(v[x][y].second >= 0 && dist[v[x][y].second] != 1e18){
					tree.update(0, 0, sz, l+cnt, l+cnt, dist[v[x][y].second]+(v[x][y].first-1)*a[x]);
					cnt++;	
				}
			}
			r = last+cnt;
			
			if(l > r) continue;
			
			cnt = 0;
			for(int y=0;y<v[x].size();y++){
				int diff = v[x][y].first-(y > 0 ? v[x][y-1].first : 1);
				
				tree.update(0, 0, sz, l, l+cnt-1, diff*1ll*a[x]);
				tree.update(0, 0, sz, l+cnt, r, diff*1ll*-a[x]);
				
				if(v[x][y].second >= 0 && dist[v[x][y].second] != 1e18) cnt++;
				
				if(v[x][y].second < 0 && dist[-v[x][y].second] > tree.query(0, 0, sz, l, r)-h[-v[x][y].second]){
					dist[-v[x][y].second] = tree.query(0, 0, sz, l, r)-h[-v[x][y].second];
				}
			}
			
			last = r;
		}
		
		if(dist[k+1] == 1e18){
			cout << "NO ESCAPE\n";
		} else {
			cout << dist[k+1] << "\n";
		}
	}
	
    return 0;
}

