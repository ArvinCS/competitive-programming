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
ll fac[maxN];
int neighbour[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1ll;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % smod;
	}
	
	ll n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	stack<pair<int, int>> st;
	st.push({0, 0});
	
	while(!st.empty()){
		pair<int, int> p = st.top();
		st.pop();
		
		int cnt = 0;
		for(auto nxt : adj[p.first]){
			if(nxt != p.second){
				cnt++;
				st.push({nxt, p.first});
			}
		}
		neighbour[p.first] = cnt;
	}
	
	bool head = true;
	ll ans = 1;
	for(int x=0;x<n;x++){
		if(neighbour[x] == 0) continue;
		
		ans = (ans * fac[neighbour[x]+1-head]) % smod;
		head = false;
	}
	cout << (ans * n) % smod << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

