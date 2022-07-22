#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
int lt[maxN], rt[maxN], node[maxN], parrent[maxN], prefix[maxN], t = 0;

void dfs(int curNode, int prvNode){
	lt[curNode] = t;
	node[t++] = curNode;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parrent[nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
	
	rt[curNode] = t-1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
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
	
	parrent[root] = -1;
	dfs(root, -1);
	
	for(int x=0;x<n;x++){
		prefix[x] = (x > 0 ? prefix[x-1] : 0);
		prefix[x] += c[node[x]];
	}
	
	int table[n+1];
	fill(table, table+n+1, 0);
	
	for(int x=0;x<n;x++){
		bool valid = false;
		vector<int> v;
		
		for(auto nxt : adj[x]){
			int sum = (nxt != parrent[x] ? prefix[rt[nxt]] - prefix[lt[nxt]-1] : prefix[n-1] - prefix[rt[x]] + (lt[x] > 0 ? prefix[lt[x]-1] : 0));

			if((sum >= 2 && c[nxt] == 1) || (sum >= 1 && c[x] == 1)){
				if(nxt == parrent[x]){
					table[lt[x]]++;
					table[rt[x]+1]--;
				} else {
					table[0]++;
					table[lt[nxt]]--;
					
					table[rt[nxt]+1]++;
					table[n]--;
				}
			}
			
			if(sum >= 1){
				v.push_back(nxt);
			}
			
			if(c[nxt] == 1){
				valid = true;
			}
		}
		
		if(valid){
			table[lt[x]]++;
			table[lt[x]+1]--;
			
			for(auto nxt : adj[x]){
				int sum = (nxt != parrent[x] ? prefix[rt[nxt]] - prefix[lt[nxt]-1] : prefix[n-1] - prefix[rt[nxt]] + (lt[nxt] > 0 ? prefix[lt[nxt]-1] : 0));
				if(c[nxt] == 1){
					if(v.size() > 2){
						if(nxt == parrent[x]){
							table[lt[x]]++;
							table[rt[x]+1]--;
						} else {
							table[0]++;
							table[lt[nxt]]--;
							
							table[rt[nxt]+1]++;
							table[n]--;
						}
					} else if(v.size() == 2){
						int p = -1;
						for(int x=0;x<v.size();x++){
							if(nxt != v[x]){
								p = v[x];
								break;
							}
						}
						
						if(nxt == parrent[x]){
							table[lt[x]]++;
							table[rt[x]+1]--;
							
							table[lt[p]]--;
							table[rt[p]+1]++;
						} else if(p == parrent[x]){
							table[lt[x]]++;
							table[rt[x]+1]--;
							
							table[lt[nxt]]--;
							table[rt[nxt]+1]++;
						} else {
							table[0]++;
							table[n]--;
							
							table[lt[nxt]]--;
							table[rt[nxt]+1]++;
							
							table[lt[p]]--;
							table[rt[p]+1]++;
						}
					}
				}
			}
		}
	}
	
	bool ans[n];
	fill(ans, ans+n, false);
	
	int cur = 0;
	for(int x=0;x<n;x++){
		cur += table[x];
		
		ans[node[x]] |= (cur > 0);
		ans[node[x]] |= c[node[x]];
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

