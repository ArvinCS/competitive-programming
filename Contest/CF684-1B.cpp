#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int maxK = sqrt(maxN)+1;

struct SegmentTree {
	pair<int, int> tree[4*maxN];
	int n;
	
	void reset(int n){
		fill(tree, tree+4*n, make_pair(1e9, 1e9));
		
		this->n = n;
		for(int x=0;x<n;x++){
			tree[n+x] = {1e9, x};
		}
		for(int x=n-1;x>=0;x--){
			tree[x] = min(tree[x<<1], tree[x<<1|1]);
		}
	}
	
	void update(int pos, int val){
		tree[pos += n].first = val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = min(tree[x], tree[x^1]);
		}
	}
	
	pair<int, int> query(int left, int right){
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

vector<int> adj[maxN], new_adj[maxN];
bool exist[maxN];
SegmentTree tree;
int store[maxK];

vector<bool> solve(int n, int k){
	tree.reset(n);
		
	int sz[n];
	for(int x=0;x<n;x++){
		tree.update(x, adj[x].size());
		sz[x] = adj[x].size();
	}
	
	while(true){
		pair<int, int> mn = tree.query(0, n);
		
		if(mn.first == 0){
			exist[mn.second] = false;
			tree.update(mn.second, 1e9);
			continue;
		}
		if(mn.first >= k){
			break;
		}
		
		for(auto nxt : adj[mn.second]){
			if(exist[nxt]){
				sz[nxt]--;
				tree.update(nxt, sz[nxt]);
			}
		}
		
		exist[mn.second] = false;
		tree.update(mn.second, 1e9);
	}
	
	vector<bool> ans(n, false);
	for(int x=0;x<n;x++){
		if(tree.query(x, x+1).first != 1e9) ans[x] = true;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		fill(exist, exist+n, true);
		for(int x=0;x<=n;x++){
			adj[x].clear();
			new_adj[x].clear();
		}
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		vector<bool> v = solve(n, k);
		vector<bool> w = solve(n, k-1);
		
		vector<int> ans;
		for(int x=0;x<n;x++){
			if(v[x]){
				ans.push_back(x);
			}
		}
		
		if(!ans.empty()){
			cout << "1 " << ans.size() << "\n";
			for(int x=0;x<ans.size();x++){
				if(x > 0) cout << " ";
				cout << ans[x]+1;
			}
			cout << "\n";
		} else {
			if(k*1ll*(k-1) > 2*m){
				cout << "-1\n";
				continue;;
			}
			
			set<pair<int, int>> st;
			for(int x=0;x<n;x++){
				if(w[x]){
					for(auto nxt : adj[x]){
						if(w[nxt]){
							st.insert({x, nxt});
							new_adj[x].push_back(nxt);
						}
					}
				}
			}
			
			bool found = false;
			for(int x=0;x<n;x++){
				if(w[x] && new_adj[x].size() == k-1){
					bool valid = true;
					for(int y=0;y<k-1;y++){
						for(int z=y+1;z<k-1;z++){
							if(!st.count({new_adj[x][y], new_adj[x][z]})){
								valid = false;
							}
						}
						if(!valid) break;
					}
					
					if(valid){
						cout << "2\n";
						cout << x+1;
						for(auto nxt : new_adj[x]){
							cout << " " << nxt+1;
						}
						cout << "\n";
						
						found = true;
						break;
					}
				}
			}
			
			if(!found){
				cout << "-1\n";
			}
		}
	}
	
    return 0;
}

