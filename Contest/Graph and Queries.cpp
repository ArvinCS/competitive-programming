#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e5 * 2 + 5;
const int maxM = 1e5 * 3 + 5;

vector<int> adj[maxN+maxM];
int data[maxN], par[maxN];
int node[maxN+maxM];

int size = 0;

int getRoot(int x){
	if(x == node[x]) return x;
	return node[x] = getRoot(node[x]);
}

void addEdge(int u, int v){
	u = getRoot(u); v = getRoot(v);
	
	node[size] = size;
	par[u] = size;
	par[v] = size;
	
	adj[size].push_back(u);
	if(u != v) adj[size].push_back(v);
	
	size++;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	size = n;
	
	for(int x=0;x<n;x++) cin >> data[x];
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
		
		addEdge(a, b);	
	}
	for(int x=0;x<q;x++){
		short y;
		cin >> t;
		
		if(y == 1){
			
		} else {
			
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

