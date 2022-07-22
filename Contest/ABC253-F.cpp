#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxQ = 2e5 + 5;

vector<pair<ll, ll>> tree[4*maxQ];

void update(int v, int curL, int curR, int l, int r, ll t, ll val) {
	if(curL > curR || l > r) return;
	if(curL == l && curR == r){
		tree[v].push_back({t, (tree[v].empty() ? 0 : tree[v].back().second)+val});
		return;
	}
	
	int curM = (curL+curR) >> 1;
	update(2*v+1, curL, curM, l, min(curM, r), t, val);
	update(2*v+2, curM+1, curR, max(l, curM+1), r, t, val);
}

ll query(int v, int curL, int curR, int pos, ll t) {
	if(curL > curR) return 0;
	
	ll ans = (tree[v].empty() ? 0 : tree[v].back().second);
	auto it = lower_bound(tree[v].begin(), tree[v].end(), make_pair(t, -1ll));
	if(it != tree[v].begin()){
		it--;
		ans -= (*it).second;
	}
	
	if(curL == curR){
		return ans;
	}
	
	int curM = (curL+curR) >> 1;
	
	if(pos <= curM){
		ans += query(2*v+1, curL, curM, pos, t);
	} else {
		ans += query(2*v+2, curM+1, curR, pos, t);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	ll row[n], curT[n];
	fill(row, row+n, 0);
	fill(curT, curT+n, 0);
	
	for(int x=0;x<q;x++){ // O(log^2Q)
		int t;
		cin >> t;
		
		if(t == 1){
			int l, r;
			ll val;
			cin >> l >> r >> val;
			
			l--; r--;
			update(0, 0, m-1, l, r, x, val);
		} else if(t == 2){
			int pos;
			ll val;
			cin >> pos >> val;
			
			pos--;
			row[pos] = val;
			curT[pos] = x;
		} else if(t == 3){
			int r, c;
			cin >> r >> c;
			
			r--; c--;
			cout << row[r] + query(0, 0, m-1, c, curT[r]) << "\n";
		}
	}
	
    return 0;
}

