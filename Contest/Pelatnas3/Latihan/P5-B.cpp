#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

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
} tree;

int c[maxN], parent[maxN];
vector<int> adj[maxN];

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parent[nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v;
	for(int x=0;x<n;x++){
		cin >> c[x];
		v.push_back(c[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		c[x] = lower_bound(v.begin(), v.end(), c[x]) - v.begin();
	}
	
	int a[n], b[n];
	for(int x=0;x<n-1;x++){
		cin >> a[x] >> b[x];
		
		a[x]--; b[x]--;
		adj[a[x]].push_back(b[x]);
		adj[b[x]].push_back(a[x]);
	}
	
	parent[0] = -1;
	dfs(0, 0);
	
	for(int x=0;x<n-1;x++){
		tree.reset();
		
		int ans = 0;
		int curNode = a[x];
		while(curNode >= 0){
			ans += tree.query(c[curNode]-1);
			tree.update(c[curNode], 1);
			c[curNode] = c[b[x]];
			curNode = parent[curNode];
		}
		
		cout << ans << "\n";
	}
    return 0;
}

