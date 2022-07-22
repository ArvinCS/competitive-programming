#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
ll l[maxN], r[maxN];

pair<ll, ll> solve(int curNode) {
	pair<ll, ll> ans = {0, 0};
	for(auto nxt : adj[curNode]){
		pair<ll, ll> p = solve(nxt);
		
		ans.first += p.first;
		ans.second += p.second;
	}
	
	if(ans.first < l[curNode]){
		ans.first = r[curNode];
		ans.second++;
	}
	
	ans.first = min(ans.first, r[curNode]);
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		
		int p[n];
		for(int x=1;x<n;x++){
			cin >> p[x];
			p[x]--;
			adj[p[x]].push_back(x);
		}
		
		for(int x=0;x<n;x++){
			cin >> l[x] >> r[x];
		}
		
		cout << solve(0).second << "\n";
	}
	
    return 0;
}

