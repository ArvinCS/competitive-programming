#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxA = 1e11;
const int maxN = 5e5;

pair<ll, ll> p[maxN], p2[maxN];

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	int query(int l, int r){
		if(l > r) return 0;
		return query(r) - query(l-1);
	}
} fenwick;

struct SegmentTree {
	set<pair<ll, ll>> tree[4*maxN];
	
	void reset(){
		for(int x=0;x<4*maxN;x++){
			tree[x].clear();
		}
	}
	
	void update(int v, int curL, int curR, int pos, ll val1, ll val2){
		if(curL > curR) return;
		if(curL == curR){
			tree[v].insert({val1, val2});
			return;
		}
		
		int curM = (curL+curR) >> 1;
		tree[v].insert({val1, val2});
		
		if(pos <= curM) update(2*v+1, curL, curM, pos, val1, val2);
		else update(2*v+2, curM+1, curR, pos, val1, val2);
	}
	
	void query(int v, int curL, int curR, int l, int r, ll mx, ll cur, vector<ll> &ans){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			for(auto p : tree[v]){
				if(p.first > mx) break;
				ans.push_back(p.second-cur);
			}
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		query(2*v+1, curL, curM, l, min(curM, r), mx, cur, ans);
		query(2*v+2, curM+1, curR, max(l, curM+1), r, mx, cur, ans);
	}
} tree;

bool customSort(pair<ll, ll> a, pair<ll, ll> b){
	if(a.second == b.second){
		return a.first > b.first;
	}
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
	
	int n;
	ll k;
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p2[x] = {p[x].second, -p[x].first};
	}
	
	ll max_d = 0;
	{	
		pair<ll, ll> tmp[n];
		for(int x=0;x<n;x++){
			tmp[x] = p[x];
			p[x] = {p[x].first+p[x].second, p[x].first-p[x].second};
		}
		
		vector<ll> val;
		for(int x=0;x<n;x++){
			val.push_back(p[x].second);
		}
		
		sort(val.begin(), val.end());
		val.erase(unique(val.begin(), val.end()), val.end());
		
		ll left = 0, right = maxA;
		while(left <= right){ // log(N.logN.logMaxA)
			ll mid = (left+right) >> 1;
			
			fenwick.reset();
			
			vector<array<ll, 4>> v;
			for(int x=0;x<n;x++){
				int idx =  lower_bound(val.begin(), val.end(), p[x].second-mid) - val.begin();
				int idx2 = lower_bound(val.begin(), val.end(), p[x].second+mid + 1) - val.begin();
				int idx3 = lower_bound(val.begin(), val.end(), p[x].second) - val.begin();
				
				v.push_back({p[x].first-mid-1, x+1, idx, idx2});
				v.push_back({p[x].first+mid, x+1, idx, idx2});
				v.push_back({p[x].first, 0, idx3, x});
			}
			
			sort(v.begin(), v.end());
			
			ll sum = 0;
			for(auto a : v){
				if(a[1] == 0){
					fenwick.update(a[2], 1);
				} else {
					if(p[a[1]-1].first <= a[0]){
						sum += fenwick.query(a[2], a[3]-1) - 1;
					} else {
						sum -= fenwick.query(a[2], a[3]-1);
					}
				}
			}
			
			if(sum >= 2*k){
				max_d = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		for(int x=0;x<n;x++){
			p[x] = tmp[x];
		}
	}
	
	sort(p, p+n, customSort);
	sort(p2, p2+n, customSort);
	
	vector<ll> vX, vX2;
	for(int x=0;x<n;x++){
		vX.push_back(p[x].first);
		vX2.push_back(p2[x].first);
	}
	
	sort(vX.begin(), vX.end());
	vX.erase(unique(vX.begin(), vX.end()), vX.end());
	
	sort(vX2.begin(), vX2.end());
	vX2.erase(unique(vX2.begin(), vX2.end()), vX2.end());
	
	vector<ll> ans;
	auto solve = [&](vector<ll> &vX, pair<ll, ll> p[]) -> void {
		tree.reset();
		
		for(int x=0;x<n;x++){
			int idx = lower_bound(vX.begin(), vX.end(), p[x].first) - vX.begin();
			
			tree.query(0, 0, vX.size()-1, idx+1, vX.size()-1, p[x].first+p[x].second+max_d-1, p[x].first+p[x].second, ans);
			tree.update(0, 0, vX.size()-1, idx, p[x].first+p[x].second, p[x].first+p[x].second);
		}
	};
	
	if(max_d > 1){
		solve(vX, p);
		solve(vX2, p2);
	}
	
	while(ans.size() < k){
		ans.push_back(max_d);
	}
	assert(ans.size() == k);
	sort(ans.begin(), ans.end());
	
	for(auto val : ans){
		cout << val << "\n";
	}
    return 0;
}

