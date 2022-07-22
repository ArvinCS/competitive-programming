#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n,m;
	cin >> n >> m;
	
	short maze[n][m];
	for(short x=0;x<n;x++){
		for(short y=0;y<m;y++){
			cin >> maze[x][y];
		}
	}
	
	vector<pair<short, short>> adj[n][m] = {}; // zero based index
	for(short x=0;x<n;x++){
		for(short y=0;y<m;y++){
			if(maze[x][y] != -1){
				if(x > 0 && maze[x-1][y] != -1) adj[x][y].push_back({x-1, y});	
				if(x+1 < n && maze[x+1][y] != -1) adj[x][y].push_back({x+1, y});	
				if(y > 0 && maze[x][y-1] != -1) adj[x][y].push_back({x, y-1});	
				if(y+1 < m && maze[x][y+1] != -1) adj[x][y].push_back({x, y+1});	
			}		
		}
	}
	
	short startX, startY; // one based index
	cin >> startX >> startY;
	
	vector<pair<short, short>> queue; // zero based index
	short dist[n][m]; // zero based index
	fill(&dist[0][0], &dist[0][0]+n*m, -1);
	
	queue.push_back({startX-1, startY-1});
	dist[startX-1][startY-1] = 1;
	
	short minDist = 30005;
	while(queue.size() > 0){
		pair<short, short> curNode = queue.front();
		queue.erase(queue.begin());
		//cout << curNode.first << "," << curNode.second << " -> " << dist[curNode.first][curNode.second] << "\n";
		for(short x=0;x<adj[curNode.first][curNode.second].size();x++){
			pair<short, short> node = adj[curNode.first][curNode.second][x];
			if(dist[node.first][node.second] == -1){
				queue.push_back(node);
				dist[node.first][node.second] = dist[curNode.first][curNode.second] + 1;
				if(node.first == 0 || node.second == 0 || node.first == n-1 || node.second == m-1) minDist = min(minDist, dist[node.first][node.second]);
			}
		}	
		if(curNode.first == 0 || curNode.second == 0 || curNode.first == n-1 || curNode.second == m-1) minDist = min(minDist, dist[curNode.first][curNode.second]);
	}
	
	cout << minDist << "\n";
    return 0;
}
