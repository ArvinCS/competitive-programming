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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int pos[m];
	fill(pos, pos+m, 0);
	
	vector<int> v[m], w[n+1];
	for(int x=0;x<m;x++){
		int k;
		cin >> k;
		
		for(int y=0;y<k;y++){
			int a;
			cin >> a;
			
			if(y == 0){
				w[a].push_back(x);
			}
			v[x].push_back(a);
		}
	}
	
	priority_queue<pair<int, int>> pq;
	for(int x=1;x<=n;x++){
		if(w[x].size() > 0){
			pq.push({w[x].size(), x});
		}
	}
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(w[p.second].size() != p.first || p.first == 0) continue;
		if(p.first == 1){
			cout << "No\n";
			return 0;
		}
		
		int a = w[p.second][p.first-1], b = w[p.second][p.first-2];
		w[p.second].pop_back(); w[p.second].pop_back();
		
		pos[a]++;
		pos[b]++;
		
		if(pos[a] < v[a].size()){
			int col = v[a][pos[a]];
			
			w[col].push_back(a);
			pq.push({w[col].size(), col});
		}
		if(pos[b] < v[b].size()){
			int col = v[b][pos[b]];
			
			w[col].push_back(b);
			pq.push({w[col].size(), col});
		}
		
		pq.push({w[p.second].size(), p.second});
	}
	
	cout << "Yes\n";
    return 0;
}

