#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct Fenwick {
	int tree[2*maxN];
	int n;
	
	void reset(int n){
		this->n = n;
		fill(tree, tree+n+1, 0);	
	}	
	
	void update(int pos, int val){
		pos++;
		
		while(pos <= n){
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
};

Fenwick tree;
int cur = 0, inTime[maxN], outTime[maxN];
vector<int> adj[maxN];

void dfs(int curNode, int prvNode){
	inTime[curNode] = cur++;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
	
	outTime[curNode] = cur++;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cur = 0;
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		
		for(int x=1;x<n;x++){
			int p;
			cin >> p;
			
			p--;
			adj[p].push_back(x);
		}
		
		vector<int> w;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			w.push_back(a[x]);
		}
		
		dfs(0, 0);
		tree.reset(cur);
		
		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());
		
		vector<int> v[w.size()];
		for(int x=0;x<n;x++){
			v[lower_bound(w.begin(), w.end(), a[x]) - w.begin()].push_back(x);
		}
		
		ll ans = 0;
		for(int x=0;x<w.size();x++){
			for(auto node : v[x]){
				int cnt = tree.query(outTime[node]) - tree.query(inTime[node]);
				ans += cnt*1ll*(cnt-1)/2;
			}
			for(auto node : v[x]){
				tree.update(inTime[node], 1);
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

