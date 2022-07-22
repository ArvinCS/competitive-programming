#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const ll mod = 1e9 + 7;

int a[maxN], b[maxN], root = -1;
vector<pair<int, int>> adj[maxN], new_adj[maxN];
int low[maxN], disc[maxN], comp[maxN], t = 0, id = 0;
ll table[maxN], pending[maxN];
bool bridge[maxN];
stack<int> st;
map<pair<int, int>, ll> mp;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans % mod;
}

void dfs2(int curNode, int prvNode){
//	if(mp.find({curNode, prvNode}) != mp.end()){
//		table[curNode] = mp[{curNode, prvNode}];
//		return;
//	}
	
	ll ans = 1;
	
	for(auto nxt : new_adj[curNode]){
		if(nxt.first != prvNode){
			dfs2(nxt.first, curNode);
			ans *= (table[nxt.first]+1);
			ans %= mod;
		}
	}
		
	table[curNode] = ans % mod;
}

void dfs3(int curNode, int prvNode, ll val){
	val = (val+1) % mod;
	pending[curNode] = val;
	
	for(auto nxt : new_adj[curNode]){
		if(nxt.first != prvNode){
			ll new_val = pending[curNode];
			new_val *= table[curNode] % mod;
			new_val %= mod;
			
			new_val *= powmod(table[nxt.first]+1, mod-2) % mod;
			new_val %= mod;
			
			dfs3(nxt.first, curNode, new_val);
		}
	}
//	cout << prvNode << " " << curNode << " -> " << pending[curNode] << "\n";
}

void dfs(int curNode, int prvNode){
	disc[curNode] = low[curNode] = t++;
	
	st.push(curNode);
	
	for(auto nxt : adj[curNode]){
		if(disc[nxt.first] == -1){
			dfs(nxt.first, curNode);
			
			if(low[nxt.first] > disc[curNode]){
				bridge[nxt.second] = true;
			}
			
			if(bridge[nxt.second]){
				while(st.top() != nxt.first){
					comp[st.top()] = id;
					st.pop();
				}
				
				comp[nxt.first] = id++;
				st.pop();
			}
			
			low[curNode] = min(low[curNode], low[nxt.first]);
		} else if(nxt.first != prvNode){
			low[curNode] = min(low[curNode], disc[nxt.first]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int x=0;x<m;x++){
		cin >> a[x] >> b[x];
		
		a[x]--; b[x]--;
		adj[a[x]].push_back({b[x], x});
		adj[b[x]].push_back({a[x], x});
	}
	
	fill(bridge, bridge+n, false);
	fill(disc, disc+n, -1);
	
	dfs(0, 0);
	
	while(!st.empty()){
		comp[st.top()] = id;
		st.pop();
	}
	id++;
	
	for(int x=0;x<m;x++){
		if(bridge[x]){
			new_adj[comp[a[x]]].push_back({comp[b[x]], x});
			new_adj[comp[b[x]]].push_back({comp[a[x]], x});
		}	
	}
	
	for(int x=0;x<n;x++){
		if(new_adj[comp[x]].size() <= 1){
			root = comp[x];
			break;
		}
	}
	
	assert(root >= 0);
	
	dfs2(root, root);
	dfs3(root, root, 0);
	
//	for(int x=0;x<n;x++) cout << comp[x] << " ";
//	cout << "\n";
//	for(int x=0;x<id;x++){
//		cout << table[x] << " ";
//	}cout << "\n";
	while(q--){
		int node;
		cin >> node;
		
		node--;
		
//		dfs2(comp[node], comp[node]);
		cout << table[comp[node]] * pending[comp[node]] % mod << "\n";
	}
	return 0;
}
