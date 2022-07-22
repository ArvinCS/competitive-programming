#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxK = 1e5 + 5;
const int maxN = 1e5 + 5;
const int maxM = 2e5 + 5;

struct SegTree {
	ll tree[2*maxK];
	int n;
	
	void reset(int n){
		this->n = n;
		fill(tree, tree+2*maxK, 0);
	}
	
	void update(int pos, ll val){
		pos += n;
		
		tree[pos] += val;
		if(tree[pos] < 0) tree[pos] += mod;
		tree[pos] %= mod;
		
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = tree[x] * tree[x^1] % mod;
		}
	}
	
	ll query(int left, int right){ // [L, R)
		ll ans = 1;
		
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = (ans * tree[left++]) % mod;
			}
			if(right&1){
				ans = (ans * tree[--right]) % mod;
			}
		}
		return ans;
	}
};

vector<int> adj[maxN];
vector<pair<int, int>> edge[maxK];
vector<pair<int, int>> cnt[maxM];
SegTree todd, teven, tboth;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int k;
	cin >> k;
	
	int n[k];
	for(int x=0;x<k;x++){
		cin >> n[x];
	}	
	
	int m;
	cin >> m;
	
	int a[m], b[m], c[m];
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x] >> c[x];
		a[x]--; b[x]--; c[x]--;
		
		edge[a[x]].push_back({b[x], c[x]});
	}
	
	for(int x=0;x<k;x++){
		for(int y=0;y<=n[x];y++){
			adj[y].clear();
		}
		for(int y=0;y<edge[x].size();y++){
			adj[edge[x][y].first].push_back(edge[x][y].second);
			adj[edge[x][y].second].push_back(edge[x][y].first);
		}
		
		int dist[n[x]][2];
		fill(dist[0], dist[n[x]], 1e9);
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[0][0] = 0;
		pq.push({dist[0][0], 0});
		
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			
			if(dist[p.second][p.first&1] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(dist[nxt][(p.first&1)^1] > p.first+1){
					dist[nxt][(p.first&1)^1] = p.first+1;
					pq.push({dist[nxt][(p.first&1)^1], nxt});
				}
			}
		}
		
		for(int y=0;y<n[x];y++){
			if(dist[y][0] != 1e9){
				cnt[dist[y][0]].push_back({x, y});
			}
			if(dist[y][1] != 1e9){
				cnt[dist[y][1]].push_back({x, y});
			}
		}
	}
	
	todd.reset(k);
	teven.reset(k);
	tboth.reset(k);
	
	set<pair<int, int>> st;
	
	ll ans = 0;
	for(int x=0;x<maxN;x++){
		for(int y=0;y<cnt[x].size();y++){
			pair<int, int> p = cnt[x][y];
			
			if(x&1){
				ll odd = todd.query(0, p.first) * todd.query(p.first+1, k) % mod;
				if(st.count(p)){
					odd -= tboth.query(0, p.first) * tboth.query(p.first+1, k) % mod;
					if(odd < 0) odd += mod;
				}
				
				ans += odd * x % mod;
				ans %= mod;
				
				todd.update(p.first, 1);
			} else {
				ll even = teven.query(0, p.first) * teven.query(p.first+1, k) % mod;
				if(st.count(p)){
					even -= tboth.query(0, p.first) * tboth.query(p.first+1, k) % mod;
					if(even < 0) even += mod;
				}
				
				ans += even * x % mod;
				ans %= mod;
				
				teven.update(p.first, 1);
			}
			
			if(st.count(p)){
				tboth.update(p.first, 1);
			} else {
				st.insert(p);
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}
