#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxM = 2e5 + 5;

vector<int> adj[maxM];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int m;
	cin >> m;
	
	pair<int, int> p[m+1];
	int l[m+1], r[m+1];
	vector<pair<int, int>> v;
	for(int x=1;x<=m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		p[x] = {a, b};
		if(a < b){
			v.push_back({a, x});
			v.push_back({min(a+k, b), -x});
			l[x] = a; r[x] = min(a+k-1, b-1);
		} else {
			v.push_back({max(a+1, b-k+1), x});
			v.push_back({b+1, -x});
			l[x] = max(a+1, b-k+1); r[x] = b;
		}
	}
	
	sort(v.begin(), v.end());
	
	set<int> st;
	
	for(int x=0;x<v.size();x++){
		if(v[x].second < 0){
			for(auto idx : st){
				adj[-v[x].second].push_back(idx);
				adj[idx].push_back(-v[x].second);
			}		
			
			st.erase(-v[x].second);
		} else {
			st.insert(v[x].second);
		}
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		int s, t;
		cin >> s >> t;
		
		s--; t--;
		
		queue<pair<int, int>> q;
		int dist[m+1];
		fill(dist, dist+m+1, 1e9);
		
		for(int x=1;x<=m;x++){
			if(l[x] <= s && s <= r[x]){
				dist[x] = 0;
				q.push({dist[x], x});
			}
		}
		
		int ans = 1e9;
		while(!q.empty()){
			pair<int, int> pn = q.front();
			q.pop();
			
			if(l[pn.second] <= t && t <= r[pn.second]){
				ans = min(ans, pn.first);
			}
			
			for(auto nxt : adj[pn.second]){
				if(dist[nxt] > pn.first+1){
					dist[nxt] = pn.first+1;
					q.push({dist[nxt], nxt});
				}
			}
		}
		
		cout << (ans != 1e9 ? ans : -1) << "\n";
	}
    return 0;
}

