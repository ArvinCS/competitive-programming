#include <bits/stdc++.h>



using namespace std;



#define ll long long



const int maxN = 1e5 + 5;

const ll mod = 1e9 + 7;



int a[maxN], b[maxN];

vector<pair<int, int>> adj[maxN], new_adj[maxN];

int low[maxN], disc[maxN], comp[maxN], t = 0, id = 0;

bool bridge[maxN];

stack<int> st;



ll powmod(ll x, ll y){

	ll ans = 1;

	

	x %= mod;

	while(y > 0){

		if(y&1) ans = (ans * x) % mod;

		

		y >>= 1;

		x = (x * x) % mod;

	}

	return ans;

}



ll dfs2(int curNode, int prvNode){

	ll ans = 1;

	

	for(auto nxt : new_adj[curNode]){

		if(nxt.first != prvNode){

			ans *= (dfs2(nxt.first, curNode)+1);

			ans %= mod;

		}

	}

	

	return ans % mod;

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

	

	while(q--){

		int node;

		cin >> node;

		

		node--;

		cout << dfs2(comp[node], comp[node]) << "\n";
		
	}

	return 0;

}


