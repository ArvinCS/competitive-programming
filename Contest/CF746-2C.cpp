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
ll a[maxN], sum = 0, cnt = 0;
int n;

ll dfs(int curNode, int prvNode){
	ll val = a[curNode];
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			val ^= dfs(nxt, curNode);
		}
	}
	
	if(val == sum){
		cnt++;
		val = 0;
	}
	return val;
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
		int k;
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
			adj[x].clear();
		}
		
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		sum = 0;
		
		for(int x=0;x<n;x++){
			sum ^= a[x];
		}
		
		if(sum == 0){
			cout << "YES\n";
			continue;
		}
		
		if(k == 2){
			cout << "NO\n";
			continue;
		}
		
		cnt = 0;
		ll val = 0;
		for(int x=0;x<n;x++){
			if(adj[x].size() == 1){
				val = dfs(x, x);
				break;
			}
		}
		
		if(val != 0){
			cout << "NO\n";
			continue;
		}
		
		if(cnt > 1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
