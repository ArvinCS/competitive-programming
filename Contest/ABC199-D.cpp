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

vector<int> adj[25];
ull ans = 0;
int n, m;

void solve(int curNode, int color[25], ull mul){
	if(curNode > n){
		bool valid = true;
		for(int x=1;x<=n;x++){
			for(auto nxt : adj[x]){
				if(color[nxt] == color[x]){
					valid = false;
					break;
				}
			}
			if(!valid) break;
		}
		
		if(valid){
			ans += mul;
		}
		return;
	}
	
	if(adj[curNode].size() == 0){
		solve(curNode+1, color, mul*3ull);
		return;
	}
	
	for(int x=0;x<3;x++){		
		bool valid = true;
		for(auto nxt : adj[curNode]){
			if(nxt > curNode) break;
			if(x == color[nxt]){
				valid = false;
				break;
			}
		}
		if(!valid) continue;
		
		color[curNode] = x;
		solve(curNode+1, color, mul);
	}
	color[curNode] = -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=1;x<=n;x++){
		sort(adj[x].begin(), adj[x].end());
	}
	
	int color[25];
	fill(color, color+25, -1);
	
	solve(1, color, 1);
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

