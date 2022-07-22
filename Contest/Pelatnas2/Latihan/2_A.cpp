#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

int sz[maxN], ti[maxN], to[maxN], t = 0;
vector<int> adj[maxN];

void dfs(int curNode){
	sz[curNode] = 1;
	ti[curNode] = t++;
	for(auto nxt : adj[curNode]){
		dfs(nxt);
		sz[curNode] += sz[nxt];
	}
	
	to[curNode] = t++;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
		if(p[x] >= 0) adj[p[x]].push_back(x);
	}
	
	fill(sz, sz+n, 0);
	
	for(int x=0;x<n;x++){
		if(p[x] == -1){
			dfs(x);
		}
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		int k;
		cin >> k;
		
		vector<pair<int, int>> v;
		for(int x=0;x<k;x++){
			int node;
			cin >> node;
			
			v.push_back({ti[node-1], node});
			v.push_back({to[node-1], -node});
		}
		
		sort(v.begin(), v.end());
		
		int cnt = 0, ans = 0;
		for(int x=0;x<v.size();x++){
			if(v[x].second > 0){
				if(cnt == 0){
					ans += sz[v[x].second-1];
				}
				
				cnt++;
			} else {
				cnt--;
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

