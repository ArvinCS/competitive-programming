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
bool active[maxN];

bool dfs(int curNode){
	if(table[curNode] != -1) return false;
	if(active[curNode]){
		table[curNode] = 0;
		return true;
	}
	
	bool cycle = false;
	int ans = 0;
	active[curNode] = true;
	for(auto nxt : adj[curNode]){
		cycle |= dfs(nxt);
		ans = max(ans, table[nxt]+(nxt > curNode));
	}
	active[curNode] = false;
	table[curNode] = ans;
	
	return cycle;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			table[x] = -1;
			active[x] = false;
		}
		for(int x=0;x<n;x++){
			int k;
			cin >> k;
			
			for(int y=0;y<k;y++){
				int a;
				cin >> a;
				
				a--;
				adj[x].push_back(a);
			}
		}
		
		int ans = 0;
		bool cycle = false;
		for(int x=0;x<n;x++){
			cycle |= dfs(x);
			ans = max(ans, table[x]+1);
		}
		
		if(cycle){
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
	
    return 0;
}

