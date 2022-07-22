#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

ll a[maxN];
vector<int> adj[maxN];
vector<pair<ll, int>> v[maxN];

void dfs(int curNode, int prvNode){
	cout << curNode << "\n";
	vector<ll> tmp;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			tmp.push_back(a[nxt]);
			dfs(nxt, curNode);
			
			while(!v[nxt].empty()){
				v[curNode].push_back(v[nxt].back());
				v[nxt].pop_back();
			}
		}
	}
	
	map<int, vector<pair<ll, int>>> mp;
	for(auto p : v[curNode]){
		cout << curNode << " = " << p.first << " " << p.second << "\n";
		mp[p.second].push_back(p);
	}
	
	vector<pair<ll, int>> w;
	for(auto p : mp){
		if(p.second.size() < p.first){
			cout << "skipped\n";
			continue;
		}
		
		sort(p.second.rbegin(), p.second.rend());
		
		ll sum = a[curNode];
		for(int x=0;x<p.first;x++){
			sum += p.second[x].first;
		}
		
		cout << p.first << " -> " << sum << "\n";
		w.push_back({sum, p.first});
	}
	
	sort(tmp.rbegin(), tmp.rend());
	
	ll sum = a[curNode];
	for(int x=0;x<tmp.size();x++){
		sum += tmp[x];
		
		if(mp[x+1].size() >= x+1){
			cout << mp[x+1].size() << " " << x+1 << " ?\n";
			continue;
		}
		
		cout << curNode << " " << x+1 << " " << sum << " =\n";
		w.push_back({sum, x+1});
	}
	
	v[curNode].clear();
	swap(v[curNode], w);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=1;x<n;x++){
		int p;
		cin >> p;
		
		p--;
		adj[p].push_back(x);
		adj[x].push_back(p);
	}
	
	dfs(0, -1);
	
	ll ans = 0;
	for(auto p : v[0]){
		ans += p.first;
		cout << p.first << " - " << p.second << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

