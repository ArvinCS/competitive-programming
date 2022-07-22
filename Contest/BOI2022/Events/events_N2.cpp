#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<array<int, 3>> v;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		v.push_back({p[x].first, 0, x});
		v.push_back({p[x].second, 1, x});
	}
	
	sort(v.begin(), v.end());
	
	vector<int> s[n];
	pair<int, int> d[q];
	for(int x=0;x<q;x++){
		cin >> d[x].first >> d[x].second;
		d[x].first--; d[x].second--;
		
		s[d[x].first].push_back(x);
	}
	
	vector<int> adj[n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x == y) continue;
			
			if(p[y].first <= p[x].second && p[x].second <= p[y].second){
				adj[x].push_back(y);
			}
		}
	}
	
	int ans[q];
	
	for(int x=0;x<n;x++){
		int dist[n];
		fill(dist, dist+n, -1);
		
		queue<int> bfs;
		dist[x] = 0;
		bfs.push(x);
		
		while(!bfs.empty()){
			int curNode = bfs.front();
			bfs.pop();
			
			for(auto nxt : adj[curNode]){
				if(dist[nxt] == -1){
					dist[nxt] = dist[curNode]+1;
					bfs.push(nxt);
				}
			}
		}
		
		for(auto idx : s[x]){
			ans[idx] = dist[d[idx].second];
		}
	}
	
	for(int x=0;x<q;x++){
		if(ans[x] >= 0) cout << ans[x] << "\n";
		else cout << "impossible\n";
	}
    return 0;
}

