#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, m;
	cin >> n >> m;
	
	us data[n+1];
	for(us x=1;x<=n;x++) cin >> data[x];
	
	vector<ui> adj[n+1];
	for(us x=0;x<n-1;x++){
		us tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}
	
	bool visited[n+1];
	fill(visited, visited+n+1, false);
	
	queue<pair<ui, ui>> q;
	q.push({1, data[1]});
	while(!q.empty()){
		pair<ui,ui> node = q.front();
//		cout << node.first << "," << node.second << "\n";
		q.pop();
		
		if(!visited[node.first] && node.second <= m){
			visited[node.first] = true;
			for(ui x=0;x<adj[node.first].size();x++){
				ui target = adj[node.first][x];
				if(!visited[target]){
					q.push({target, node.second+data[target]});
				}
			}
		}
	}
	
	us ans = 0;
	for(ui x=1;x<=n;x++){
		if(visited[x] && adj[x].size() == 1){
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

