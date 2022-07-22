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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int p[n], h[n], sum[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
			sum[x] = p[x];
		}
		for(int x=0;x<n;x++){
			cin >> h[x];
		}
		
		vector<int> adj[n];
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		bool visited[n];
		vector<int> level[n];
		int total[n];
		for(int x=0;x<n;x++){
			total[x] = 0;
			visited[x] = false;
		}
		
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			level[p.second].push_back(p.first);
			visited[p.first] = true;
			
			for(auto i : adj[p.first]){
				if(!visited[i]) q.push(make_pair(i, p.second+1));
			}
		}
		
		bool possible = true;
		for(int x=0;x<n;x++){
			visited[x] = false;
		}
	
		for(int x=n-1;x>=0;x--){
			for(int y=0;y<level[x].size();y++){
				int idx = level[x][y];
				
				visited[idx] = true;
				
				if((sum[idx]-h[idx])&1){
					possible = false;
					break;
				}
				int bad = (sum[idx]-h[idx])/2;
				int good = h[idx]+bad;
				
//					cout << idx << " -> " << good << " " << bad << " " << sum[idx] << " "<< total[idx] << "\n";
				if(good < 0 || good > sum[idx] || good < total[idx]){
					possible = false;
					break;
				}
				
				for(auto i : adj[idx]){
					if(!visited[i]){
						sum[i] += sum[idx];
						total[i] += good;
						break;
					}
				}
			}
			if(!possible) break;
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

