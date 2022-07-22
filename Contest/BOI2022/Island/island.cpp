#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int cnt = 0;
	for(int x=0;x<n;x++){
		bool visited[n];
		fill(visited, visited+n, false);
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		visited[x] = true;
		for(auto nxt : adj[x]){
			if(!visited[nxt]){
				visited[nxt] = true;
				pq.push({s[nxt], nxt});
			}
		}
		
		ll cur = s[x];
		while(!pq.empty() && pq.top().first <= cur){
			pair<int, int> p = pq.top();
			pq.pop();
			
			cur += p.first;
			
			for(auto nxt : adj[p.second]){
				if(!visited[nxt]){
					visited[nxt] = true;
					pq.push({s[nxt], nxt});
				}
			}
		}
		
		if(pq.empty()) cout << 1;
		else cout << 0;
		
		cnt += (pq.empty()?1:0);
		while(!pq.empty()) pq.pop();
	}
	assert(cnt >= n/2);
	cout << "\n";
    return 0;
}

