#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui dfs(ui from, int city[], vector<ui> adj[], bool visited[]){
	visited[from] = true;
	ui total = 0;
	for(ui x=0;x<adj[from].size();x++){
		ui target = adj[from][x];
		if(!visited[target]){
			total += dfs(target, city, adj, visited);
		}
	}	
	return total + city[from];
}

ui verify(int n, ui start, int predict[], int city[], vector<ui> adj[], bool visited[]){
	visited[start] = true;
	
	bool tmpVisited[n];
	copy(visited, visited+n, tmpVisited);
	
	int total = dfs(start, city, adj, tmpVisited);
	int happy = (total+predict[start])/2;
	int sad = total - happy;

	if(happy < 0 || sad < 0){
		return inf_int;
	}
	
	int nextHappy = 0;
	for(ui y=0;y<adj[start].size();y++){
		if(visited[adj[start][y]]) continue;
		nextHappy += verify(n, adj[start][y], predict, city, adj, visited);

		cout << "nest: " << nextHappy << "\n";
		if(nextHappy > happy){
			return inf_int;
		} 
	}
	
	return happy;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int city[n];
		for(ui x=0;x<n;x++){
			cin >> city[x];
		}
		
		int predict[n];
		for(ui x=0;x<n;x++){
			cin >> predict[x];
		}
		
		vector<ui> adj[n];
		for(ui x=0;x<n-1;x++){
			ui tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			tmp1--; tmp2--;
			
			adj[tmp1].push_back(tmp2);
			adj[tmp2].push_back(tmp1);
		}
		
		bool visited[n], possible = true;
		fill(visited, visited+n, false);
		
		int total = verify(n, 0, predict, city, adj, visited);
			
		if(total > m) cout << "NO\n";
		else cout << "YES\n";
	}
	
    return 0;
}

