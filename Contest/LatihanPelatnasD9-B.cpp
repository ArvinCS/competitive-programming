#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 1e9 + 7;

vector<int> adj[maxN];
ll table[maxN][3];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void dfs(int curNode){
	if(adj[curNode].empty()){
		table[curNode][1] = 1;	
		return;
	}
	
	for(auto nxt : adj[curNode]){
		dfs(nxt);
	}
	
	if(adj[curNode].size() == 1){
		table[curNode][0] = table[adj[curNode][0]][0];
		table[curNode][1] = table[adj[curNode][0]][1];
		table[curNode][2] = table[adj[curNode][0]][2];
		return;
	}
	
	ll sum = 1, sum2 = 1;
	for(auto nxt : adj[curNode]){
		sum2 *= table[nxt][1] % mod;
		sum2 %= mod;
		
		sum *= ((2*table[nxt][1] % mod - table[nxt][2] + mod) % mod + table[nxt][0]) % mod;
		sum %= mod;
	}
	
	for(auto nxt : adj[curNode]){
		table[curNode][0] += sum2 * powmod(table[nxt][1], mod-2) % mod * (((table[nxt][1] - table[nxt][2] + table[nxt][0]) + mod) % mod) % mod;
		table[curNode][0] %= mod;
	}
	
	table[curNode][1] = (sum - table[curNode][0] + mod) % mod;
	table[curNode][2] = sum2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int p;
		cin >> p;
		
		p--;
		adj[p].push_back(x);
	}
	
	fill(table[0], table[maxN], 0);
	
	dfs(0);
	
	cout << table[0][1] % mod << "\n";
	return 0;
}

