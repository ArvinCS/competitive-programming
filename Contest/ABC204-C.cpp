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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n];
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
	}
	
	ll ans = 0;
	
	bool visited[n];
	for(int x=0;x<n;x++){
		fill(visited, visited+n, false);
		queue<int> q;
		q.push(x);
		
		visited[x] = true;
		while(!q.empty()){
			int curNode = q.front();
			q.pop();
			
			ans++;
			for(auto nxt : adj[curNode]){
				if(!visited[nxt]){
					visited[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

