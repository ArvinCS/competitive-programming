#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;
const int logN = log2(maxN)+1;

int a[maxN], cnt[maxN], prvCnt[maxN], cost[maxN], prvCost[maxN], level[maxN], parent[logN][maxN]; // at idx i
int len[maxN], prvLen[maxN];
bool ok[maxN], prvOk[maxN];
vector<int> adj[maxN], v;

void dfs(int curNode, int prvNode){
	cost[curNode] = ok[curNode] = 0;
	v.push_back(curNode);
	for(int i=1;i<logN;i++){
		parent[i][curNode] = parent[i-1][parent[i-1][curNode]];
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			parent[0][nxt] = curNode;
			dfs(nxt, curNode);
			v.push_back(curNode);
			cost[curNode] += cost[nxt];
		}
	}
	
	int mx = 0;
	int one = 0, zero = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && !ok[nxt]){
			if((a[nxt]+len[nxt]+1)%2 == 0){
				if(cost[nxt] == 0){
					one++;
				} else {
					mx = max(mx, cnt[nxt]+1);
					zero++;
				}
			} else {
				one++;
			}
		}
	}
	
	cnt[curNode] = mx;
	len[curNode] = one+zero;
	if(one == 0 && zero == 0){
		ok[curNode] = a[curNode];
		return;
	}
	
	cost[curNode] += (one+zero)*2+zero*2;
//	cout << curNode << ": " << cost[curNode] << " " << one << " " << zero << " " << mx << "\n";
}

int findLCA(int x, int y){
	if(level[x] > level[y]) swap(x, y);
	
	for(int i=logN-1;i>=0;i--){
		if(level[x] <= level[y]-(1 << i)){
			y = parent[i][y];
		}
	}
	
	if(x == y) return x;
	
	for(int i=logN-1;i>=0;i--){
		if(parent[i][x] != parent[i][y]){
			x = parent[i][x];
			y = parent[y][y];
		}
	}
	
	return parent[0][x];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		char c;
		cin >> c;
		
		a[x] = (c == '1');
	}
	
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	level[0] = 0;
	parent[0][0] = 0;
	dfs(0, 0);
	
	int ans = 1e9;
	for(int x=1;x<v.size();x++){
		int curNode = v[x];
		
		int lca = parent[0][curNode];
		int val = 0;
		
		int mx = 0, one = 0, zero = 0;
		if(level[lca] > 0 && !prvOk[parent[0][lca]]){
			val += prvCost[parent[0][lca]];
			mx = max(mx, prvCnt[parent[0][lca]]);
			
			if((a[parent[0][lca]]+prvLen[parent[0][lca]]+1)%2 == 0){
				if(prvCost[parent[0][lca]] > 0){
					zero++;
				} else {
					one++;
				}
				zero++;
			} else {
				one++;
			}
		}
		
		if(lca != curNode){
			for(auto nxt : adj[lca]){
				if(nxt != parent[0][lca] && nxt != curNode && !ok[nxt]){
					val += cost[nxt];
					
					if((a[nxt]+len[nxt]+1)%2 == 0){
						if(cost[nxt] > 0){
							zero++;
						} else {
							one++;
						}
						mx = max(mx, cnt[nxt]+1);
					} else {
						one++;
					}
				}
			}
			
			val += (one+zero)*2+zero*2;
			
			if(val > 0) prvOk[lca] = false;
			else prvOk[lca] = a[lca];
			 
			prvCost[lca] = val; prvCnt[lca] = mx;
		}
		
//		cout << " a " << zero << " " << one << " " << (a[lca]+one+zero)%2 << " " << prvOk[lca] << "\n";
		prvLen[lca] = one+zero;
		one = 0; zero = 0;
		
		if(lca != curNode && !prvOk[lca]){
			cout << x << ", " << (a[lca]+prvLen[lca]+1) << "\n";
			if((a[lca]+prvLen[lca]+1)%2 == 0){
//				cout << "A " << (a[lca]+len+1) << "\n";
				if(val > 0){
					zero++;
				} else {
					one++;
				}
				
				mx++;
			} else {
				one++;
				mx = 0;
			}
		}
		
		cout << " = " << val << "\n";
		for(auto nxt : adj[curNode]){
			if(nxt != parent[0][curNode] && !ok[nxt]){
				val += cost[nxt];
				if((a[nxt]+len[nxt]+1)%2 == 0){
					zero++;
					mx = max(mx, cnt[nxt]+1);
				} else {
					one++;
				}
			}
		}
		
		val += (one+zero)*2+1;
		
		cout << prvNode << " to " << curNode << " = " << val << " " << zero << " " << one << " " << mx << "\n";
		if((a[curNode]^((one+zero+1+zero)%2)) == 1){
			ans = min(ans, val+zero*2);
			cout << "-< " << val+zero*2 << "\n";
		}
		if(zero > 0 && (a[curNode]^((one+(zero-1)+1+(zero-1))%2)) == 1 && mx > 0){
			cout << "A\n";
			ans = min(ans, val+(zero-1)*2-mx-max(0, mx-1)*2-1);
			cout << "-> " << val+(zero-1)*2-mx-max(0, mx-1)*2-1 << "\n";
		}
		if(one > 0 && (a[curNode]^((one+(zero-1)+1+(zero-1))%2)) == 1 && mx > 0){
			cout << "A\n";
			ans = min(ans, val+(zero-1)*2-mx-max(0, mx-1)*2-1);
			cout << "-> " << val+(zero-1)*2-mx-max(0, mx-1)*2-1 << "\n";
		}
	}
	
	if(ans == 1e9) ans = 0;
	
	cout << ans << "\n";
    return 0;
}

