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
vector<int> ans;

void dfs(int curNode, int prvNode){
	ans.push_back(curNode+1);
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			ans.push_back(curNode+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<n;x++) sort(adj[x].begin(), adj[x].end());
	
	dfs(0, 0);
	
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

