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

bool visited[maxN], curVisited[maxN];
vector<int> adj[maxN];

bool dfs(int curNode){
	visited[curNode] = true;
	curVisited[curNode] = true;
	
	bool ans = false;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt] && dfs(nxt)){
			ans = true;
		} else if(curVisited[nxt]){
			ans = true;
		}
	}
	curVisited[curNode] = false;
	return ans;
}

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= smod;
	
	while(y > 0){
		if(y&1) ans = (ans*x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	for(int x=0;x<n;x++){
		visited[x] = curVisited[x] = false;
		adj[x].push_back(data[x]-1);
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(!visited[x]){
			bool cycle = dfs(x);
			ans += cycle;
		}
	}
	cout << (powmod(2ll, ans) - 1 + mod) % mod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

