#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
priority_queue<pair<ll, int>> pq[maxN];
vector<ll> v;
ll h[maxN];

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}		
	
	ll mx = h[curNode];
	bool need = true;
	if(!pq[curNode].empty()){
		if(pq[curNode].top().first > mx){
			need = pq[curNode].top().second;
		} else if(pq[curNode].top().first == mx){
			need = false;
		}
		
		mx = max(mx, pq[curNode].top().first);
		pq[curNode].pop();
		
		while(!pq[curNode].empty()){
			if(pq[curNode].top().first == mx){
				need = false;
			}
			
			v.push_back(pq[curNode].top().first);
			pq[curNode].pop();
		}
	}
	
	pq[prvNode].push({mx, need});
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<ll, int>> w;
	for(int x=0;x<n;x++){
		cin >> h[x];
		w.push_back({h[x], x});
	}
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	sort(w.begin(), w.end());
	
	int root = w[0].second;
	
	for(auto nxt : adj[root]){
		dfs(nxt, root);
	}
	
	ll ans = pq[root].top().first;
	bool need = pq[root].top().second;
	pq[root].pop();
	
	if(adj[root].size() == 1){
		if(h[root] > ans){
			need = true;
			
			pq[root].push({ans, 0});
			ans = h[root];
		} else if(h[root] == ans){
			need = false;
			
			pq[root].push({h[root], 0});
		} else {
			pq[root].push({h[root], 0});
		}
	} else {
		if(h[root] >= ans){
			need = true;
		}
		
		ans = max(ans, h[root]);
	}
	
	cout << ans << " " << need << "\n";
	cout << root << " " << pq[root].size() << "\n";
	
	while(!pq[root].empty()){
		if(need){
			ans *= 2;
			need = false;
		} else {
			v.push_back(pq[root].top().first);	
		}
		
		pq[root].pop();
	}
		
	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		cout << v[x] << " -\n";
		ans += v[x];
	}
	
	cout << ans << "\n";
    return 0;
}

