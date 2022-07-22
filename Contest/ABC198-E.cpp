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
bool ans[maxN];
int color[maxN];

void dfs(int curNode, int prevNode, bool exist[maxN]){
	if(exist[color[curNode]]){
		ans[curNode] = false;
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prevNode){
			bool prv = exist[color[curNode]];
			
			exist[color[curNode]] = true;
			dfs(nxt, curNode, exist);
			exist[color[curNode]] = prv;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=1;x<=n;x++){
		cin >> color[x];
	}
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(ans, ans+n+1, true);
	
	bool exist[maxN];
	fill(exist, exist+maxN, false);
	
	dfs(1, 0, exist);
	
	for(int x=1;x<=n;x++){
		if(ans[x]){
			cout << x << "\n";
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

