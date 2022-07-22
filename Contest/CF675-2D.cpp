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

const int maxM = 1e5 + 5;

int parrent[maxM], sz[maxM];
ll best[maxM];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]) swap(a, b);
		
		parrent[b] = a;
		sz[a] += sz[b];
		best[a] = min(best[a], best[b]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	pair<ll, ll> loc[m];
	for(int x=0;x<m;x++){
		cin >> loc[x].first >> loc[x].second;
	}
	
	vector<pair<ll, int>> v, w;
	for(int x=0;x<m;x++){
		parrent[x] = x;
		sz[x] = 1;
		best[x] = abs(c-loc[x].first)+abs(d-loc[x].second);
		
		v.push_back({loc[x].first, x});
		w.push_back({loc[x].second, x});
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	for(int x=1;x<v.size();x++){ // x coordinate
		if(v[x-1].first == v[x].first){
			merge(v[x-1].second, v[x].second);
		}
	}
	for(int x=1;x<w.size();x++){ // y coordinate
		if(w[x-1].first == w[x].first){
			merge(w[x-1].second, w[x].second);
		}
	}
	
	vector<pair<int, ll>> adj[m];
	for(int x=1;x<v.size();x++){ // x coordinate		
		int p1 = getParrent(v[x-1].second), p2 = getParrent(v[x].second);
		
		if(p1 != p2){
			adj[p1].push_back({p2, v[x].first-v[x-1].first});
			adj[p2].push_back({p1, v[x].first-v[x-1].first});
		}
	}
	for(int x=1;x<w.size();x++){ // y coordinate		
		int p1 = getParrent(w[x-1].second), p2 = getParrent(w[x].second);
		
		if(p1 != p2){
			adj[p1].push_back({p2, w[x].first-w[x-1].first});
			adj[p2].push_back({p1, w[x].first-w[x-1].first});
		}
	}
	
	ll dist[m];
	fill(dist, dist+m, inf_ll);
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	
	ll ans = abs(a-c)+abs(b-d);
	for(int x=0;x<m;x++){
		ll tmp = min(abs(a-loc[x].first), abs(b-loc[x].second));
		
		if(dist[getParrent(x)] > tmp){
			dist[getParrent(x)] = tmp;
			ans = min(ans, dist[getParrent(x)]+best[getParrent(x)]);
			pq.push({dist[getParrent(x)], getParrent(x)});
		}
	}
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		
		ans = min(ans, best[p.second]+p.first);
		for(auto nxt : adj[getParrent(p.second)]){
			if(dist[nxt.first] > dist[p.second]+nxt.second){
				dist[nxt.first] = dist[p.second]+nxt.second;
				pq.push({dist[nxt.first], nxt.first});
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

