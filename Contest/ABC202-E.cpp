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

vector<int> adj[maxN], v[maxN], w[maxN];
int dist[maxN], inTime[maxN], outTime[maxN], cnt = 0;

void dfs(int curNode, int prvNode, int d){
	dist[curNode] = d;
	inTime[curNode] = cnt++;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, d+1);
		}
	}
	outTime[curNode] = cnt++;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int p;
		cin >> p;
		
		p--;
		adj[p].push_back(x);
	}
	
	dfs(0, -1, 0);
	
	vector<pair<int, int>> tmp, tmp2;
	for(int x=0;x<n;x++){
		tmp.push_back({dist[x], inTime[x]});
		tmp2.push_back({dist[x], outTime[x]});
	}
	
	sort(tmp.begin(), tmp.end());
	sort(tmp2.begin(), tmp2.end());
	
	for(int x=0;x<n;x++){
		v[tmp[x].first].push_back(tmp[x].second);
		w[tmp2[x].first].push_back(tmp2[x].second);
	}
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--;
		if(dist[a] == b){
			cout << "1\n";
			continue;
		}
		if(dist[a] > b){
			cout << "0\n";
			continue;
		}
		
		int ans = v[b].size();
		auto it = upper_bound(v[b].begin(), v[b].end(), outTime[a]);
		auto it2 = lower_bound(w[b].begin(), w[b].end(), inTime[a]);
		
		if(it != v[b].end()) ans -= (v[b].size() - (it - v[b].begin()));
		if(it2 != w[b].begin()) ans -= (it2 - w[b].begin());
		cout << ans << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

