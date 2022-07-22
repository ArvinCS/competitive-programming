#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
vector<int> v, w[maxN];
int prv[maxN], parent[maxN], id = 0;

void dfs(int curNode, int prvNode){
	prv[curNode] = prvNode;
	cout << prvNode << " -> " << curNode << "\n";
	int sz = adj[curNode].size();
	assert(sz > 0);
	if(sz-(curNode != prvNode) == 0){
		w[id].push_back(curNode);
	} else if(sz-(curNode != prvNode) == 1){
		for(auto nxt : adj[curNode]){
			if(nxt != prvNode){
				dfs(nxt, curNode);
			}
		}
	} else {
		w[id].push_back(prvNode);
		
		id++;
		parent[id] = curNode;
		
		int cnt = 0;
		for(auto nxt : adj[curNode]){
			if(nxt != prvNode){
				if(cnt >= 1){
					id++;
					parent[id] = nxt;
					dfs(nxt, curNode);
				} else {
					dfs(nxt, curNode);	
				}
				
				cnt++;
			}
		}
	}
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
		
		id = 0;
		v.clear();
		for(int x=0;x<n;x++){
			adj[x].clear();
			w[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int root = -1;
		for(int x=0;x<n;x++){
			if(adj[x].size() == 1){
				root = x;
				break;
			}
		}
		
		parent[0] = root;
		dfs(root, root);
		id++;
		
		vector<array<int, 4>> ans;
		for(int x=id-1;x>0;x--){
			if(w[0].empty()) break;
			ans.push_back({parent[x], prv[parent[x]], parent[x], w[0].back()});
			w[0].pop_back();
			
			while(!w[x].empty()){
				w[0].push_back(w[x].back());
				cout << "- " << w[x].back() << "\n";
				w[x].pop_back();
			}cout << " --\n";
		}
		
		cout << ans.size() << "\n";
		for(auto a : ans){
			cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << "\n";
		}
	}
	
    return 0;
}

