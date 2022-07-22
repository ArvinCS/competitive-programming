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

	int n, m;
	cin >> n >> m;
	
	int data[n], pos[n+1];

	for(int x=0;x<n;x++){
		cin >> data[x];
		pos[data[x]] = x;
	}
	
	int num = data[n-1];
	vector<int> adj[n+1];
	for(int x=0;x<m;x++){
		int u, v;
		cin >> u >> v;
		
		adj[v].push_back(u);
	}

	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<adj[data[x]].size();y++){
			if(pos[adj[data[x]][y]] < pos[data[x]]){
				cnt[pos[adj[data[x]][y]]]++;
			}
		}
	}
	
	vector<pair<int, int>> need;
	for(int x=0;x<adj[num].size();x++){
		need.push_back(make_pair(pos[adj[num][x]], adj[num][x]));
	}
	
	sort(need.rbegin(), need.rend());
	
	int ans = 0, last = n-1;
	for(int x=0;x<need.size();x++){
		int a = need[x].first, b = need[x].second;
//		cout << a << "-" << b << "\n";
		if(cnt[a] >= last-a){
			ans++;
			last--;
		}
	}
//	for(int x=0;x<n;x++){
//		cout << cnt[x] << " ";
//	}
//	cout << "\n";
	
//	int last = n-1;
//	for(int x=n-2;x>=0;x--){
//		if(cnt[x] == n-1-x){
//			ans++;
//			last--;
//		}
//		if(last <= 0) break;
//	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

