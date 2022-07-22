#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
bool mark[maxN];
pair<int, int> ans = {0, 0};

void dfs(int curNode){
	int cnt = 0;
	for(auto nxt : adj[curNode]){
		dfs(nxt);
		if(adj[nxt].size() > 0) cnt++;
	}
	
	int sz = adj[curNode].size();
	if(sz > 0){
		int mn = min(1+sz/2, ans.second);
		ans.first += 1+sz/2-mn;
		ans.second -= mn;
		
		ans.second += (sz%2==0);
	}
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
		
		int p[n];
		p[0] = -1;
		for(int x=1;x<n;x++){
			cin >> p[x];
			p[x]--;
		}
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			mark[x] = false;
		}
		for(int x=1;x<n;x++){
			adj[p[x]].push_back(x);
		}
		
		ans = {0, 0};
		dfs(0);
		if(ans.second == 0){
			ans.first++;
		}
		
		cout << ans.first << "\n";
	}
	
    return 0;
}

