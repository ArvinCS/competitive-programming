#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

struct SegmentTree {
	pair<int, int> tree[4*maxN];
	int sum[4*maxN];
	int n;
	
	void reset(int n){
		this->n = n;
		for(int x=0;x<n;x++){
			tree[n+x] = {1, 1};
			sum[n+x] = 1;
		}
		
		for(int x=n-1;x>=0;x--){
			tree[x].first = (tree[x<<1].first + tree[x<<1|1].first)&1;
			tree[x].second = (tree[x<<1].second + tree[x<<1|1].second)&1;
			sum[x] = (sum[x<<1]+sum[x<<1|1]+tree[x].first);
		}
	}
	
	void update(int pos, int val){
		tree[pos += n].first += val%2;
		if(tree[pos].first < 0) tree[pos].first += 2;
		tree[pos].first %= 2;
		
		for(int x=pos;x>1;x>>=1){
			tree[x>>1].first = (tree[x].first + tree[x^1].first)&1;
			tree[x>>1].second = (tree[x].second + tree[x^1].second)&1;
			sum[x>>1] = (sum[x]+sum[x^1]+tree[x].first);
		}
	}
	
	int query(int left, int right){
		pair<int, int> ans = {1e9, 1e9};
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = min(ans, tree[left++]);
			}
			if(right&1){
				ans = min(ans, tree[--right]);
			}
		}
		return ans;
	}
};

vector<int> adj[maxN];
int parent[logN][maxN];

void dfs(int curNode, int prvNode){
	for(int x=1;x<logN;x++){
		parent[x][curNode] = parent[x-1][parent[x-1][curNode]];
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parent[0][nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int root = 0;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			root = x;
			break;
		}
	}
	
	parent[0][root] = dist[root] = 0;
	dfs(root, root);
	
	vector<array<ll, 3>> v;
	for(int x=0;x<n;x++){
		if(adj[x].size() == 1){
			v.push_back({t[x], x, 0});
		}
	}
	
	sort(v.begin(), v.end());
	
	int lazy[n];
	fill(lazy, lazy+n, q+1);
	
	while(q--){
		int m;
		cin >> m;
		
		vector<array<ll, 3>> w;
		for(int x=0;x<m;x++){
			int p;
			cin >> p;
			
			p--;
			
			if(adj[p].size() == 1){
				lazy[p] = q;
			}
			
			w.push_back({t[p], p, 1});
		}
		
		for(int x=0;x<v.size();x++){
			if(lazy[v[x][1]] == q) continue;
			w.push_back(v[x]);
		}
		
		if(w.size()&1){
			cout << "-1\n";
			continue;
		}
		
		sort(w.begin(), w.end());
		
		ll ans = findDist(w[0][1], w[w.size()/2][1]) + w[0][2] + w[w.size()/2][2];
		
		queue<pair<int, int>> q;
		q.push({1, w.size()/2-1});
		q.push({w.size()/2+1, w.size()-1});
		
		vector<int> lst;
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(p.first >= p.second){
				if(p.first == p.second) lst.push_back(p.first);
				continue;
			}
			
			ans += findDist(w[p.first][1], w[p.second][1]) + w[p.first][2] + w[p.second][2];
			q.push({p.first+1, p.second-1});
		}
		
		if(!lst.empty()){
			ans += findDist(w[lst[0]][1], w[lst[1]][1]) + w[lst[0]][2] + w[lst[1]][2];
		}
		
		cout << ans << "\n";
	}
    return 0;
}

