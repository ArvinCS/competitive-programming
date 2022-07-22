#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

struct SegmentTree {
	int tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, 0);
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] += val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = (tree[x] + tree[x^1]);
		}
	}
	
	int query(int left, int right){
		int ans = 0;
		
		for(left += maxN, right += maxN; left < right; left >>= 1, right >>= 1){
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

vector<int> adj[maxN];
//int inTime[maxN], outTime[maxN], parent[logN][maxN], level[maxN], t = 0;
int c[maxN], parent[maxN];//, root[maxN], sz[maxN];
map<pair<int, int>, pair<int, int>> mp;
//SegmentTree tree;

pair<int, int> dfs(int curNode, int prvNode){
	auto it = mp.find({curNode, prvNode});
	if(it != mp.end()) return (*it).second;
	
	parent[curNode] = prvNode;
	
	pair<int, int> mn = {1e9, 1e9};
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && c[nxt] == -1){
			pair<int, int> p = dfs(nxt, curNode);
			mn = min(mn, p);
		}
	}
	
	if(mn.first == 1e9) return {curNode, curNode};
	return mp[{curNode, prvNode}] = {min(mn.first, curNode), mn.second};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<n;x++){
		sort(adj[x].begin(), adj[x].end());
	}
	
	fill(c, c+n, -1);
	
	int cur = 0;
	for(int x=0;x<n;x++){
		if(c[x] == -1){
			vector<pair<int, int>> v;
			for(auto nxt : adj[x]){
				if(c[nxt] == -1){
					v.push_back(dfs(nxt, x));
				}
			}
			
			sort(v.begin(), v.end());
			
			if(v.size() > 0){
				int curNode = v[0].second;
				while(curNode != x){
					c[curNode] = cur;
					curNode = parent[curNode];
				}
			}
			if(v.size() > 1){
				int curNode = v[1].second;
				while(curNode != x){
					c[curNode] = cur;
					curNode = parent[curNode];
				}
			}
			c[x] = cur++;
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << c[x]+1;
	}
	cout << "\n";
    return 0;
}
