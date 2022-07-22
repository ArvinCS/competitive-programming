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

ll dist[maxN];
ll ans[maxN];
vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(dist, dist+n, inf_ll);
	fill(ans, ans+n, 0);
	
	queue<int> q;
	dist[0] = 0;
	ans[0] = 1;
	q.push(0);
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(dist[nxt] > dist[curNode]+1){
				dist[nxt] = dist[curNode]+1;
				ans[nxt] = ans[curNode];
				
				q.push(nxt);
			} else if(dist[nxt] == dist[curNode]+1){
				ans[nxt] += ans[curNode];
			}
			ans[nxt] %= mod;
		}
	}
	
	cout << ans[n-1] << "\n";
    return 0;
}

