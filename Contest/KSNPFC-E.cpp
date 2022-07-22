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

ll k[maxN], dist[maxN];
vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int x=0;x<n;x++){
		cin >> k[x];
	}
	
	queue<pair<int, int>> q;
	dist[0] = 0;
	q.push({0, 0});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		dist[p.first] = dist[p.second]+1;
		for(auto nxt : adj[p.first]){
			if(nxt != p.second){
				q.push({nxt, p.first});
			}
		}
	}
	
	vector<pair<ll, ll>> v;
	for(int x=0;x<n;x++){
		if(k[x] > 0){
//			cout << dist[x] << " " << k[x] << "\n";
			v.push_back({dist[x], 1});
			v.push_back({dist[x]+k[x], -1});
		}
	}
		
	sort(v.begin(), v.end());
	
	ll ans = 0, cnt = 0, prv = 0;
	for(auto p : v){
		if(p.second == -1){
			cnt--;
			
			if(cnt == 0){
				ans += max(0ll, p.first-prv);
//				cout << p.first-prv-1 << " --\n";
			}
		} else {
			if(cnt == 0){
				prv = p.first;
			}
			cnt++;
			
			ans += max(0ll, p.first-prv+1);
//			cout << p.first-prv+1 << "\n";
			prv = p.first+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

