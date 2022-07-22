#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<int, int>> adj[30];

string mv[4] = {"ATAS", "BAWAH", "KIRI", "KANAN"};
bool visited[30], mark[30];
int table[30][4], parrent[30];

int move(int x){
	cout << mv[x] << endl;
	
	int res;
	cin >> res;
	
	return res;	
}

void dfsCol(int startNode, int curNode){
	int nxt = move(0);
	adj[curNode].push_back({nxt, 0});
	adj[nxt].push_back({curNode, 1});
	
	table[nxt][1] = curNode;
	table[curNode][0] = nxt;
	
	visited[curNode] = true;
	if(nxt != startNode){
		dfsCol(startNode, nxt);
	}
}

void dfsRow(int startNode, int curNode){
	if(startNode != curNode && !visited[curNode]){
		dfsCol(curNode, curNode);
	}
	
	int nxt = move(3);
	adj[curNode].push_back({nxt, 3});
	adj[nxt].push_back({curNode, 2});
	
	table[nxt][2] = curNode;
	table[curNode][3] = nxt;
	parrent[curNode] = startNode;
	
	if(nxt != startNode){
		dfsRow(startNode, nxt);
	}
}

pair<int, int> dfs(int curNode){
	pair<int, int> ans = {parrent[curNode] == 1 ? 0 : -1e9 - curNode, mark[curNode] ? 0 : -1e9};
	if(curNode != 1){
		for(auto nxt : adj[curNode]){
			if(!visited[nxt.first]){
				visited[nxt.first] = true;
				pair<int, int> p = dfs(nxt.first);
				visited[nxt.first] = false;
				
				if(parrent[curNode] != 1) ans.first = max(ans.first, p.first+(nxt.second == 0 ? 1 : (nxt.second == 1 ? -1 : 0)));
				if(!mark[curNode]) ans.second = max(ans.second, p.second+(nxt.second == 2 ? 1 : (nxt.second == 3 ? -1 : 0)));
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string subsoal;
	cin >> subsoal;
	
	int n;
	cin >> n;
	
	fill(mark, mark+n+1, false);
	fill(visited, visited+n+1, false);
	
	int node = 1;
	while(true){
		mark[node] = true;
		dfsRow(node, node);
		
		int nxt = move(0);
		
		adj[node].push_back({nxt, 0});
		adj[nxt].push_back({node, 1});
		
		table[nxt][1] = node;
		table[node][0] = nxt;
		
		if(nxt == 1) break;
		node = nxt;
	}
	
	int ans[5][5];
	fill(ans[0], ans[5], 0);
	
	int row[n+1], col[n+1];
	for(int x=1;x<=n;x++){
		fill(visited, visited+n+1, false);
		
		visited[x] = true;
		pair<int, int> p = dfs(x);
		ans[p.first][p.second] = x;
		cout << x << " -> " << parrent[x] << " " << p.first << "," << p.second << "\n";
	}
	
	for(int x=1;x<=n;x++){
		cout << x << ":\n";
		for(auto p : adj[x]){
			cout << p.first << " " << p.second << "\n";
		}
	}
//	node = 1;
//	int cnt = 0;
//	while(true){
//		int node2 = node;
//		while(true){
//			int nxt2 = table[node2][3];
//			row[nxt2] = cnt;
//			
////			cout << node << " " << node2 << " " << nxt2 << "\n";
//			if(nxt2 == node) break;
//			node2 = nxt2;
//		}
//		
//		int nxt = table[node][1];
//		if(nxt == 1) break;
//		node = nxt;
//		cnt++;
//	}
//	
//	int ans[5][5];
//	fill(ans[0], ans[5], 0);
//	
//	for(int x=1;x<=n;x++){
////		cout << x << " -> " << row[x] << " " << col[x] << "\n";
//		ans[row[x]][col[x]] = x;
//	}
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(y > 0) cout << " ";
			cout << ans[x][y];
		}
		cout << endl;
	}
    return 0;
}

