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

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int table[maxN];

int dfs(int curNode){
	if(table[curNode] != -1) return table[curNode];
	
	table[curNode] = 0;
	for(auto nxt : adj[curNode]){
		table[curNode] += dfs(nxt);
	}
	table[curNode]++;
	
	cout << curNode << "\n";
	return table[curNode];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
		
		table[x] = -1;
	}
	
	for(int x=0;x+1<n;x++){
		adj[p[x].first].push_back(p[x+1].first);
		adj[p[x].first].push_back(p[x+1].second);
		adj[p[x].second].push_back(p[x+1].first);
		adj[p[x].second].push_back(p[x+1].second);
	}
	
	int ans = 0;
	for(int x=0;x<n;x++){
		ans = max(ans, dfs(x));
	}
	
	cout << ans << "\n";
    return 0;
}

