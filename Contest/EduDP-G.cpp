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

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
int table[maxN];
bool visited[maxN];

void solve(int curNode){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]) solve(nxt);
		
		table[curNode] = max(table[curNode], 1 + table[nxt]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
	}
	
	fill(table, table+n+1, 0);
	fill(visited, visited+n+1, false);
	
	for(int x=1;x<=n;x++) if(!visited[x]) solve(x);
	
	int ans = 0;
	for(int x=1;x<=n;x++) ans = max(ans, table[x]);
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

