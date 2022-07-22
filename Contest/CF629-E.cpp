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

const int maxN = 3e5;

vector<int> adj[maxN];
ll parrent[maxN], in[maxN], out[maxN], depth[maxN];
ll timer = 0;

void dfs(int curNode, int prevNode, int level){
	in[curNode] = ++timer;
	depth[curNode] = level;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prevNode){
			parrent[nxt] = curNode;
			dfs(nxt, curNode, level+1);
		}
	}
	
	out[curNode] = ++timer;
}

bool check(int u, int v){
    return ((in[u]<in[v] && out[u]>out[v]) || (in[v]<in[u] && out[v]>out[u]));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parrent[1] = 1;
	dfs(1, -1, 1);
	
	for(int x=0;x<m;x++){
		int k;
		cin >> k;
		
		vector<int> v;
		for(int x=0;x<k;x++){
			int tmp;
			cin >> tmp;
			
			v.push_back(tmp);
		}
		
		int cur = v[0];
		for(auto nxt : v) if(depth[nxt] > depth[cur]) cur = nxt;
		
		bool valid = true;
		
		for(int x=0;x<k;x++){
			int nxt = v[x];
			
			if(nxt == cur) continue;
			if(check(cur, nxt) || check(cur, parrent[nxt]) || check(parrent[cur], nxt) || check(parrent[cur], parrent[nxt])){
				continue;
			}
			
			valid = false;
			break;
		}
		
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar
