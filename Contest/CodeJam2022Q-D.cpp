#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = 1e6;
const int maxN = 1e5 + 5;

vector<int> adj[maxN];
ll f[maxN];

pair<ll, ll> dfs(int curNode, int prvNode){
	pair<ll, ll> p = {0, 0};
	
	vector<ll> v;
	for(auto nxt : adj[curNode]){
		pair<ll, ll> q = dfs(nxt, curNode);
		p.second += q.second;
		v.push_back(q.first);
	}
	
	if(!v.empty()){
		sort(v.begin(), v.end());
		
		p.first = v[0];
		for(int x=1;x<v.size();x++){
			p.second += v[x];
		}
	}
	
	return {max(f[curNode], p.first), p.second};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			cin >> f[x];
		}
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
			
			p[x]--;
			if(p[x] != -1){
				adj[p[x]].push_back(x);
			}
		}
		
		cout << "Case #" << i << ": ";
		ll ans = 0;
		
		for(int x=0;x<n;x++){
			if(p[x] == -1){
				pair<ll, ll> p = dfs(x, x);
				ans += p.first+p.second;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

