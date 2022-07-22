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
	
	vector<int> adj[n+1];
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bool visited[n+1];
	fill(visited, visited+n+1, false);
	
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(!visited[nxt]){
				visited[nxt] = true;
				q.push(nxt);
			}
		}	
	}
	
	for(int x=1;x<=n;x++){
		if(!visited[x]){
			cout << "-1\n";
			return 0;
		}
	}
	
	int color[n+1];
	fill(color, color+n+1, -1);
	
	q.push(1);
	
	vector<int> v[3];
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		if(color[curNode] != -1) continue;
		
		bool c[4];
		fill(c, c+4, false);
		
		for(auto nxt : adj[curNode]){
			if(color[nxt] == -1){
				q.push(nxt);
			} else {
				c[color[nxt]] = true;
			}
		}
		
		if(!c[1]){
			color[curNode] = 1;
			v[0].push_back(curNode);
		} else if(!c[2]){
			color[curNode] = 2;
			v[1].push_back(curNode);
		} else if(!c[3]){
			color[curNode] = 3;
			v[2].push_back(curNode);
		} else {
			cout << "-1\n";
			return 0;
		}
	}
	
	if(v[0].size() == 0 || v[1].size() == 0 || v[2].size() == 0){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=1;x<=n;x++){
		int cnt = 0;
		for(auto nxt : adj[x]){
			if(color[nxt] != color[x]){
				cnt++;
			}
		}
		
		int nxt1 = (color[x])%3, nxt2 = (color[x]+1)%3;
		if(cnt != (v[nxt1].size() + v[nxt2].size())){
			cout << "-1\n";
			return 0;
		}
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << color[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

