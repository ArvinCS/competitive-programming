#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct SegTree {
	int tree[2*maxN];
	int n;
	
	void reset(int n){
		this->n = n;
		
		fill(tree, tree+2*maxN, 0);
		
		for(int x=0;x<n;x++){
			tree[n+x] = 1;
		}
		for(int x=n-1;x>0;x--){
			tree[x] = tree[x<<1] + tree[x<<1|1];
		}
	}
	
	void update(int pos, int val){
		pos += n;
		
		tree[pos] += val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = tree[x] + tree[x^1];
		}
	}
	
	int query(int left, int right){
		int ans = 0;
		
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans += tree[left++];
			}
			if(right&1){
				ans += tree[--right];
			}
		}
		return ans;
	}
};

SegTree l, r; // dekat jalur
int cnt[maxN][6];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	ll a, b;
	cin >> n >> m >> a >> b;
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		char c;
		
		cin >> p[x].first >> c;
		p[x].first--;
		p[x].second = (c - 'A');
	}
	
	l.reset(n);
	r.reset(n);
	fill(cnt[0], cnt[maxN], 1);
	
	ll cur = 0;
	priority_queue<ll> pq;
	
	for(int x=0;x<m;x++){
		ll ans = 0;
		if(p[x].second >= 3){
			for(int y=p[x].second-1;y>=2;y--){
				ans += cnt[p[x].first][y];
			}
		} else {
			for(int y=p[x].second+1;y<=3;y++){
				ans += cnt[p[x].first][y];
			}
		}
		
		ll depan = a*(ans+l.query(0, p[x].first)+r.query(0, p[x].first));
		ll belakang = a*(ans+l.query(p[x].first+1, n)+r.query(p[x].first+1, n));
		
		pq.push(depan-belakang);
		cur += depan;
		
		if(p[x].second == 2){
			l.update(p[x].first, -1);
		}
		if(p[x].second == 3){
			r.update(p[x].first, -1);
		}
		cnt[p[x].first][p[x].second] = 0;
	}
	
	ll ans = 1e18;
	for(int y=0;y<=m;y++){
		if(y > 0){
			cur -= pq.top();
			pq.pop();
		}
		
		ans = min(ans, cur+(m-y)*b*(m-y-1)/2+y*b*(y-1)/2);
	}
	
	cout << ans << "\n";
	return 0;
}
