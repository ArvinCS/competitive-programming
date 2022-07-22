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
		v.push_back({p[x].first, 1, x});
		v.push_back({p[x].second, 0, x});
	}
	
	sort(v.begin(), v.end());
	
	pair<int, int> d[q];
	for(int x=0;x<q;x++){
		cin >> d[x].first >> d[x].second;
		d[x].first--; d[x].second--;
	}
	
	
	int ans[q];
	
	for(int x=0;x<q;x++){
		int dist[n];
		fill(dist, dist+n, 1e9);
		
		bool active[n];
		fill(active, active+n, false);
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for(int y=0;y<v.size();y++){
			while(!pq.empty() && !active[pq.top().second]){
				pq.pop();
			}
			
			if(!active[v[y][2]]){
				dist[v[y][2]] = min(dist[v[y][2]], (!pq.empty() ? pq.top().first+1 : (v[y][2] == d[x].first ? 0 : n+1)));
				if(dist[v[y][2]] <= n){
					pq.push({dist[v[y][2]], v[y][2]});
				}
			} else {
				dist[v[y][2]] = min(dist[v[y][2]], (!pq.empty() ? pq.top().first+1 : (v[y][2] == d[x].first ? 0 : n+1)));
				if(dist[v[y][2]] <= n){
					pq.push({dist[v[y][2]], v[y][2]});
				}
			}
			
			active[v[y][2]] ^= 1;
		}
		
		if(dist[d[x].second] > n) dist[d[x].second] = -1;
		ans[x] = dist[d[x].second];
	}
	
	for(int x=0;x<q;x++){
		if(ans[x] >= 0) cout << ans[x] << "\n";
		else cout << "impossible\n";
	}
    return 0;
}

